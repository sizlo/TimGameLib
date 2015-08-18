//
//  CGame.cpp
//  TimGameLib
//
//  Created by Tim Brier on 26/09/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CGame.hpp"
#include "CTextureBank.hpp"
#include "GameOptions.hpp"
#include "DebugOptions.hpp"
#include "SystemUtilities.hpp"
#include "CMessageBroadcaster.hpp"
#include <sstream>

// =============================================================================
// Static Members
// -----------------------------------------------------------------------------
CGame * CGame::smInstance = NULL;

// =============================================================================
// Non member variables
// -----------------------------------------------------------------------------
#if TGL_DEBUG
CDebugHelper *theDebugHelper;
#endif

// =============================================================================
// Singleton Accessor
// -----------------------------------------------------------------------------
CGame * CGame::Get()
{
    return smInstance;
}

// =============================================================================
// CGame constructor/destructor
// -----------------------------------------------------------------------------
CGame::CGame(std::string theTitle)
:   mWindowTitle(theTitle),
    mWindow(NULL),
    mClearColour(CColour::Black),
    mFPS(0),
    mShouldSkipUpdateFrame(false),
#if !USE_SFML_VSYNC
    mUPS(0),
#endif
    mExitCode(EXIT_SUCCESS),
    mExitRequested(false),
    mGameState((EGameState)0),
    mCurrentLocation(NULL),
    mNextLocation(NULL)
{
    if (smInstance == NULL)
    {
        smInstance = this;
    }
}

CGame::~CGame()
{
    
}

// =============================================================================
// CGame::Init
// Initialise the game
// -----------------------------------------------------------------------------
void CGame::Init(int initialGameLocation)
{
    // Initialise game options
    GameOptions::ReadConfig();
    InitialiseOptions();

    // Create the game window
    mWindow = new CWindow(GameOptions::windowWidth,
                          GameOptions::windowHeight,
                          mWindowTitle,
                          GameOptions::fullscreen,
                          GameOptions::antiAliasingLevel);
        
    // Use a view to make the game resolution independant
    CView theView(CFloatRect(GameOptions::viewLeft, GameOptions::viewTop,
                             GameOptions::viewWidth, GameOptions::viewHeight));

    // If we want to preserve the games original aspect ratio then set a viewport
    if (GameOptions::preserveAspect)
    {
        float vpLeft = 0.0f;
        float vpTop = 0.0f;
        float vpWidth = 1.0f;
        float vpHeight = 1.0f;

        float windowAspect = (float) GameOptions::windowWidth / (float) GameOptions::windowHeight;
        float viewAspect = GameOptions::viewWidth / GameOptions::viewHeight;

        if (windowAspect > viewAspect)
        {
            // The window aspect is wider than the view aspect
            // The viewport will use the full window height
            // Calculate what percentage of the view height that is
            float percent = (float) GameOptions::windowHeight / GameOptions::viewHeight;
            // Now use this to calculate the viewport width in pixels
            float vpWidthPx = GameOptions::viewWidth * percent;
            // Now work out what percent of the window width this is
            vpWidth = vpWidthPx / (float) GameOptions::windowWidth;

            // Now work out how far along the window we need to put this is order to center it
            vpLeft = (1.0f - vpWidth) / 2.0f;
        }
        else if (windowAspect < viewAspect)
        {
            // The window aspect is taller than the view aspect
            // Do similar calculations to above but in other dimension
            float percent = (float) GameOptions::windowWidth / GameOptions::viewWidth;
            float vpHeightPx = GameOptions::viewHeight * percent;
            vpHeight = vpHeightPx / (float) GameOptions::windowHeight;
            vpTop = (1.0f - vpHeight) / 2.0f;
        }

        theView.setViewport(CFloatRect(vpLeft, vpTop, vpWidth, vpHeight));
    }


    mWindow->setView(theView);
    
    if ((GameOptions::windowWidth * 1.0f) / GameOptions::windowHeight
        != GameOptions::viewWidth / GameOptions::viewHeight)
    {
        DEBUG_LOG("View aspect ratio doesn't match window aspect ratio");
    }
    
    // Initialise other systems
    SystemUtilities::Init(mWindow);
    SFMLInitialiser::InitSFML(mWindow);
    
    // Create and register any lifetime objects
#if TGL_DEBUG
    theDebugHelper = new CDebugHelper();
#endif
    
    // Enter the initial location
    GoToLocation(initialGameLocation);
}

// =============================================================================
// CGame::InitialiseOptions
// Initialise any game options, called after the config file is read
// -----------------------------------------------------------------------------
void CGame::InitialiseOptions()
{
    // Do nothing, this is game specific
}

// =============================================================================
// CGame::Run
// Enter the main loop, returns program exit code
// -----------------------------------------------------------------------------
int CGame::Run()
{
    CClock  theUpdateClock;
#if !USE_SFML_VSYNC
    CClock  theRenderClock;
    CTime   timeSinceLastRender = CTime::Zero;
#endif
    
    while (mWindow->isOpen())
    {
        ProcessEvents();
        
        CTime timeSinceLastUpdate = theUpdateClock.restart();
        if (!mShouldSkipUpdateFrame)
        {
            Update(timeSinceLastUpdate);
        }
        mShouldSkipUpdateFrame = false;
       
#if !USE_SFML_VSYNC
        // Only render if vsync is off or enough time has past
        timeSinceLastRender += theRenderClock.restart();
        if (!GameOptions::doVsync
            || timeSinceLastRender.asSeconds() >= 1.0f / GameOptions::maxFPS)
        {
            timeSinceLastRender = CTime::Zero;
            Render();
        }
#else
        Render();
#endif

        // If we requested a new location switch to it
        if (mNextLocation != NULL)
        {
            SwitchLocation();
        }
    }
    
    return mExitCode;
}

// =============================================================================
// CGame::Cleanup
// Cleanup before quitting
// -----------------------------------------------------------------------------
void CGame::Cleanup()
{
    SAFE_DELETE(mWindow);
    SAFE_DELETE(mCurrentLocation);
#if TGL_DEBUG
    SAFE_DELETE(theDebugHelper);
#endif
    TextUtilities::Cleanup();
    CTextureBank::Cleanup();
}

// =============================================================================
// CGame::ExitGame
// Exit the game
// -----------------------------------------------------------------------------
void CGame::ExitGame()
{
    DEBUG_LOG("Exit requested");
    mExitRequested = true;
}

// =============================================================================
// CGame::SetGameState
// Set given GameState flags
// -----------------------------------------------------------------------------
void CGame::SetGameState(EGameState theState)
{
    mGameState = static_cast<EGameState>(mGameState | theState);
}

// =============================================================================
// CGame::UnsetGameState
// Unset the given GameState flags
// -----------------------------------------------------------------------------
void CGame::UnsetGameState(EGameState theState)
{
    mGameState = static_cast<EGameState>(mGameState & ~theState);
}

// =============================================================================
// CGame::HasAllGameStates
// Returns true only if the current state has all the given flags
// -----------------------------------------------------------------------------
bool CGame::HasAllGameStates(EGameState theState)
{
    EGameState theResult = static_cast<EGameState>(mGameState & theState);
    return theResult == theState;
}

// =============================================================================
// CGame::RegisterUpdateable
// Add an updateable to the list
// -----------------------------------------------------------------------------
void CGame::RegisterUpdateable(CUpdateable *theUpdateable)
{
    // If we're not updating then we can add it now, otherwise add it to a list
    // to be added after the current update cycle
    if (!HasAllGameStates(kGameStateUpdating))
    {
        mTheUpdateables.push_back(theUpdateable);
    }
    else
    {
        SUpdateableRegistrationRequest theRequest;
        theRequest.mShouldRegister = true;
        theRequest.mUpdateable = theUpdateable;
        mUpdateableRegistrationRequests.push_back(theRequest);
    }
}

// =============================================================================
// CGame::RegisterRenderable
// Add a renderable to the list
// -----------------------------------------------------------------------------
void CGame::RegisterRenderable(CRenderable *theRenderable)
{
    mTheRenderables.push_back(theRenderable);
}

// =============================================================================
// CGame::UnregisterUpdateable
// Remove a given updateable from the list
// -----------------------------------------------------------------------------
void CGame::UnregisterUpdateable(CUpdateable *theUpdateable)
{
    // If we're not updating go ahead and remove it, otherwise add it to a list
    // to be removed after the current update cycle
    if (!HasAllGameStates(kGameStateUpdating))
    {
        mTheUpdateables.remove(theUpdateable);
    }
    else
    {
        SUpdateableRegistrationRequest theRequest;
        theRequest.mShouldRegister = false;
        theRequest.mUpdateable = theUpdateable;
        mUpdateableRegistrationRequests.push_back(theRequest);
    }
}

// =============================================================================
// CGame::UnregisterRenderable
// Remove a given renderable from the list
// -----------------------------------------------------------------------------
void CGame::UnregisterRenderable(CRenderable *theRenderable)
{
    mTheRenderables.remove(theRenderable);
}

// =============================================================================
// CGame::GetDebugHelper
// -----------------------------------------------------------------------------
CDebugHelper * CGame::GetDebugHelper()
{
#if TGL_DEBUG
    return theDebugHelper;
#else
    return NULL;
#endif
}

// =============================================================================
// CGame::GoToLocation
// Go to a game location (level/menu)
// -----------------------------------------------------------------------------
void CGame::GoToLocation(int theLocation,
                         std::string filename /* = std::string() */)
{
    // Set up the next location, we'll move there at the end of this update
    switch (theLocation)
    {
        case kGameLocationDummy:
            DEBUG_LOG("Dummy location requested");
            mNextLocation = new CDummyGameLocation();
            break;
            
        default:
            DEBUG_LOG("Unimplemented game location - going to dummy location");
            mNextLocation = new CDummyGameLocation();
            break;
    }
}

// =============================================================================
// CGame::SwitchLocation
// -----------------------------------------------------------------------------
void CGame::SwitchLocation()
{
    // If we're already in a location leave it
    if (mCurrentLocation != NULL)
    {
        mCurrentLocation->Exit();
        SAFE_DELETE(mCurrentLocation);
    }
    
    // Now switch to the next location and enter it
    mCurrentLocation = mNextLocation;
    mNextLocation = NULL;
    mCurrentLocation->Enter();
}

// =============================================================================
// CGame::ProcessEvents
// Process all events recieved this cycle
// -----------------------------------------------------------------------------
void CGame::ProcessEvents()
{
    CEvent theEvent;
    while (mWindow->pollEvent(theEvent))
    {
        switch (theEvent.type)
        {
            case CEvent::KeyPressed:
                // Hack to enable cmd+q / alt+f4 functionality
#if TGL_MAC
                if (theEvent.key.code == CKeyboard::Q
                    && (CKeyboard::isKeyPressed(CKeyboard::LSystem)
                        || CKeyboard::isKeyPressed(CKeyboard::RSystem)))
                {
                    ExitGame();
                }
#elif TGL_WINDOWS
                if (theEvent.key.code == CKeyboard::F4
                    && (CKeyboard::isKeyPressed(CKeyboard::LAlt)))
                {
                    ExitGame();
                }
#endif
                break;
                
            case CEvent::Closed:
                // Exit on close event
                ExitGame();
                break;

            case CEvent::GainedFocus:
                mCurrentLocation->ReactToFocusGained();
                
                // Skip a frame when we gain focus
                mShouldSkipUpdateFrame = true;
                break;

            case CEvent::LostFocus:
                mCurrentLocation->ReactToFocusLost();
                break;
                
            default:
                break; // Do nothing
        }
        
        // Broadcast this event
        CMessageBroadcaster<CEvent>::BroadcastMessage(theEvent);
        
    }
    
    // React to exit requests
    if (mExitRequested)
    {
        mWindow->close();
    }
}

// =============================================================================
// CGame::Update
// Update all registered CUpdatables
// -----------------------------------------------------------------------------
void CGame::Update(CTime elapsedTime)
{
    // Set game state
    SetGameState(kGameStateUpdating);
    
#if !USE_SFML_VSYNC
    // Count updates
    static int numUpdates;
    static CTime accumulatingElapsedTime;
    
    numUpdates++;
    accumulatingElapsedTime += elapsedTime;
    if (accumulatingElapsedTime.asSeconds() >= 1.0f) // Every second
    {
        mUPS = numUpdates;
        numUpdates = 0;
        accumulatingElapsedTime = CTime::Zero;
    }
#endif
    
#if TGL_DEBUG
    if (DebugOptions::useSlowMotion)
    {
        elapsedTime /= 10.0f;
    }
#endif
    
    // Iterate through the registered updateables, updating each in turn
    FOR_EACH_IN_LIST(CUpdateable *, mTheUpdateables)
    {
        // Only update when in an appropriate state
        if ((*it)->ShouldUpdateForState(mGameState))
        {
            (*it)->Update(elapsedTime);
        }
    }
    
    // Add or remove any updateables that were requested this cycle
    while (!mUpdateableRegistrationRequests.empty())
    {
        SUpdateableRegistrationRequest thisRequest =
                                    mUpdateableRegistrationRequests.front();
        mUpdateableRegistrationRequests.pop_front();
        
        if (thisRequest.mShouldRegister)
        {
            mTheUpdateables.push_back(thisRequest.mUpdateable);
        }
        else
        {
            mTheUpdateables.remove(thisRequest.mUpdateable);
        }
    }
    
    // Unset game state
    UnsetGameState(kGameStateUpdating);
}

// =============================================================================
// CGame::Render
// Render all CRenderable registered
// -----------------------------------------------------------------------------
void CGame::Render()
{
    // Count frames
    static int numFrames = 0;
    static CClock theClock;
    static CTime elapsedTime;
    
    numFrames++;
    elapsedTime += theClock.restart();
    if (elapsedTime.asSeconds() >= 1.0f) // Every second
    {
        mFPS = numFrames;
        numFrames = 0;
        elapsedTime = CTime::Zero;
    }
    
    // Clear the window
    mWindow->clear(mClearColour);
    
    // Iterate through all registered renderables, drawing them all
    FOR_EACH_IN_LIST(CRenderable *, mTheRenderables)
    {
        (*it)->Draw(mWindow);
    }
    
    // In debug draw frame/update rate over everything else
#if TGL_DEBUG
    if (DebugOptions::showFramerate)
    {
        std::stringstream theStream;
        theStream << "FPS: " << mFPS;
#if !USE_SFML_VSYNC
        theStream << std::endl << "UPS: " << mUPS;
#endif
        mWindow->DrawTextAt(theStream.str(),
                            GameOptions::viewWidth - 100,
                            5,
                            CColour::Red);
    }
    
    theDebugHelper->Draw(mWindow);
#endif
    
    // Display the new window contents
    mWindow->display();
}





