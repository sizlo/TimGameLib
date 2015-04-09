//
//  CGame.hpp
//  TimGameLib
//
//  Created by Tim Brier on 26/09/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimGameLib__TimeGameLib__
#define __TimGameLib__TimeGameLib__

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "SFMLIntegration/SFMLIntegration.hpp"
#include "TextUtilties.hpp"
#include "CUpdateable.hpp"
#include "CRenderable.hpp"
#include "CGameLocation.hpp"
#include "GameState.hpp"
#include <list>

// =============================================================================
// Forward Declarations
// -----------------------------------------------------------------------------
class CDebugHelper;

// =============================================================================
// Structs
// -----------------------------------------------------------------------------
struct SUpdateableRegistrationRequest
{
    bool            mShouldRegister;
    CUpdateable     *mUpdateable;
};

// =============================================================================
// Class Definition
// -----------------------------------------------------------------------------
class CGame
{
public:
    static CGame * Get();
    
    CGame();
    ~CGame();
    
    // Initialise the game
    virtual void Init(int initialGameLocation);
    // Enter the main loop, returns program exit code
    virtual int Run();
    // Cleanup before quitting
    virtual void Cleanup();
    
    // Exit the game
    virtual void ExitGame();
    
    // Set/unset GameState flags
    virtual void SetGameState       (EGameState theState);
    virtual void UnsetGameState     (EGameState theState);
    // Returns true only if the current gamestate has all the given flags
    virtual bool HasAllGameStates   (EGameState theState);
    
    // Register/unregister updatable/renderables
    virtual void RegisterUpdateable  (CUpdateable    *theUpdateable);
    virtual void RegisterRenderable  (CRenderable    *theRenderable);
    virtual void UnregisterUpdateable(CUpdateable    *theUpdateable);
    virtual void UnregisterRenderable(CRenderable    *theRenderable);
    
    // Go to a game location
    virtual void GoToLocation(int theLocation,
                             std::string filename = std::string());
    
    static CDebugHelper * GetDebugHelper();
protected:
    // Process all events recieved this cylce
    void ProcessEvents();
    // Update all CUpdatables registered
    void Update(CTime elapsedTime);
    // Render all CRenderables registered
    void Render();
    
    // The game window
    std::string mWindowTitle;
    CWindow *mWindow;
    
    // Frames per second and updates per second
    int mFPS;
#if !USE_SFML_VSYNC
    int mUPS;
#endif

    // When set we won't run one update cycle
    bool mShouldSkipUpdateFrame;
    
    // The code returned on program exit
    int mExitCode;
    // Has an exit been requested
    bool mExitRequested;
    
    // The current game state
    EGameState mGameState;
    
    // Updateable and renderable lists
    std::list<CUpdateable *> mTheUpdateables;
    std::list<SUpdateableRegistrationRequest>
                                    mUpdateableRegistrationRequests;
    std::list<CRenderable *> mTheRenderables;
    
    // The current game location (menu/level)
    CGameLocation *mCurrentLocation;
    
    // Singleton instance
    static CGame *smInstance;
};


#endif /* defined(__TimGameLib__TimeGameLib__) */
