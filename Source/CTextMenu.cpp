//
//  CTextMenu.cpp
//  TimGameLib
//
//  Created by Tim Brier on 31/01/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include "CTextMenu.hpp"
#include "CGame.hpp"

// =============================================================================
// CTextMenu constructor
// -----------------------------------------------------------------------------
CTextMenu::CTextMenu(std::string theTitle, CFloatRect theShape)
:   mTitle(theTitle),
    mShape(theShape)
{
    
}

// =============================================================================
// CTextMenu::Enter
// -----------------------------------------------------------------------------
void CTextMenu::Enter()
{
    CMenu::Enter();
    
    // Register any updateables and renderables
    CGame::Get()->RegisterUpdateable(this);
    CGame::Get()->RegisterRenderable(this);
    
    mCurrentSelection = 0;
}

// =============================================================================
// CTextMenu::Exit
// -----------------------------------------------------------------------------
void CTextMenu::Exit()
{
    CMenu::Exit();
    
    // Unregister all updateables and renderables
    CGame::Get()->UnregisterUpdateable(this);
    CGame::Get()->UnregisterRenderable(this);
}

// =============================================================================
// CTextMenu::Update
// -----------------------------------------------------------------------------
void CTextMenu::Update(CTime elapsedTime)
{

}

// =============================================================================
// CTextMenu::ReactToEvent
// -----------------------------------------------------------------------------
void CTextMenu::ReactToEvent(CEvent *theEvent)
{
    if (theEvent->type == CEvent::KeyPressed)
    {
        if (theEvent->key.code == CKeyboard::Up)
        {
            mCurrentSelection--;
        }
        else if (theEvent->key.code == CKeyboard::Down)
        {
            mCurrentSelection++;
        }
        else if (theEvent->key.code == CKeyboard::Return)
        {
            ExecuteMenuItem(mCurrentSelection);
        }
    }
    
    // Clamp the current selection
    mCurrentSelection = std::max(mCurrentSelection, 0);
    mCurrentSelection = std::min(mCurrentSelection, int(mMenuItems.size()) - 1);
}

// =============================================================================
// CTextMenu::Draw
// -----------------------------------------------------------------------------
void CTextMenu::Draw(CWindow *theWindow)
{
    int xPosLeft    = mShape.left +  40;
    int xPosRight   = mShape.left + 50;
    int yPos        = mShape.top + 50;
    int yOffset     = 20;
    
    // Draw the background
    CVector2f heightOffset = CVector2f(0.0f, mShape.height);
    CVector2f widthOffset = CVector2f(mShape.width, 0.0f);
    CVector2f topLeft = CVector2f(mShape.left, mShape.top);
    CVector2f topRight = topLeft + widthOffset;
    CVector2f bottomLeft = topLeft + heightOffset;
    CVector2f bottomRight = bottomLeft + widthOffset;
    std::list<CVector2f> points;
    points.push_back(topLeft);
    points.push_back(topRight);
    points.push_back(bottomRight);
    points.push_back(bottomLeft);
    CConvexShape background = CConvexShape(points);
    background.setFillColor(CColour::Black);
    theWindow->DrawShape(background);
    
    // Draw the title
    theWindow->DrawTextAt(mTitle, xPosLeft, yPos, CColour::White);
    yPos += yOffset + yOffset;
    
    // Draw each menu item
    int i = 0;
    FOR_EACH_IN_LIST(std::string, mMenuItems)
    {
        std::string itemText = (*it);
        theWindow->DrawTextAt(itemText, xPosRight, yPos, CColour::White);
        
        // Draw the highlight if this is the current selection
        if (i == mCurrentSelection)
        {
            theWindow->DrawTextAt(">", xPosLeft, yPos, CColour::White);
        }
        
        i++;
        yPos += yOffset;
    }
}

// =============================================================================
// CTextMenu::AddMenuItem
// -----------------------------------------------------------------------------
void CTextMenu::AddMenuItem(std::string theItem)
{
    mMenuItems.push_back(theItem);
}

// =============================================================================
// CTextMenu::GetCurrentSelectionIndex
// -----------------------------------------------------------------------------
int CTextMenu::GetCurrentSelectionIndex()
{
    return mCurrentSelection;
}

// =============================================================================
// CTextMenu::SetCurrentSelectionIndex
// -----------------------------------------------------------------------------
void CTextMenu::SetCurrentSelectionIndex(int theIndex)
{
    mCurrentSelection = theIndex;
}