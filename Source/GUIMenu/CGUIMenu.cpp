//
//  CGUIMenu.cpp
//  TimGameLib
//
//  Created by Tim Brier on 08/05/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CGUIMenu.hpp"
#include "CGame.hpp"
#include "../SystemUtilities.hpp"

CGUIMenu::CGUIMenu()
{
    
}

CGUIMenu::~CGUIMenu()
{
    FREE_LIST_CONTENTS(mWidgets);
}

void CGUIMenu::Update(CTime elapsedTime)
{
    
}

void CGUIMenu::Draw(CWindow *theWindow)
{
    for (CWidget *w : mWidgets)
    {
        w->Draw(theWindow);
    }
    
    (*mCurrentSelection)->DrawHighlight(theWindow);
}

void CGUIMenu::Enter()
{
    CMenu::Enter();
    
    CGame::Get()->RegisterRenderable(this);
    CGame::Get()->RegisterUpdateable(this);
    
    mCurrentSelection = mWidgets.begin();
}

void CGUIMenu::Exit()
{
    CMenu::Exit();
    
    CGame::Get()->UnregisterRenderable(this);
    CGame::Get()->UnregisterUpdateable(this);
}

bool CGUIMenu::HandleMessage(CEvent theEvent)
{
    bool messageEaten = false;
    
    if (theEvent.type == CEvent::KeyPressed)
    {
        if (theEvent.key.code == CKeyboard::W
            || theEvent.key.code == CKeyboard::Up)
        {
            messageEaten = MoveSelectionUp();
        }
        else if (theEvent.key.code == CKeyboard::S
                 || theEvent.key.code == CKeyboard::Down)
        {
            messageEaten = MoveSelectionDown();
        }
    }
    else if (theEvent.type == CEvent::MouseMoved)
    {
        if (!(*mCurrentSelection)->IsBlockingFocusChange())
        {
            SelectOptionUnderMouse(CVector2i(theEvent.mouseMove.x, theEvent.mouseMove.y));
        }
    }
    
    if (!messageEaten)
    {
        (*mCurrentSelection)->HandleMessage(theEvent);
    }
    
    return messageEaten;
}

void CGUIMenu::AddWidget(CWidget *theWidget)
{
    mWidgets.push_back(theWidget);
}

bool CGUIMenu::MoveSelectionUp()
{
    bool didMove = false;
    
    if (!(*mCurrentSelection)->IsBlockingFocusChange())
    {
        if (mCurrentSelection != mWidgets.begin())
        {
            mCurrentSelection--;
            didMove = true;
        }
    }
    
    return didMove;
}

bool CGUIMenu::MoveSelectionDown()
{
    bool didMove = false;
    
    if (!(*mCurrentSelection)->IsBlockingFocusChange())
    {
        mCurrentSelection++;
        if (mCurrentSelection == mWidgets.end())
        {
            mCurrentSelection--;
        }
        else
        {
            didMove = true;
        }
    }
    
    return didMove;
}

void CGUIMenu::SelectOptionUnderMouse(CVector2i windowPosition)
{
    CVector2f viewPosition = SystemUtilities::GetViewPosition(windowPosition);
    
    for (std::list<CWidget *>::iterator w = mWidgets.begin();
         w != mWidgets.end();
         w++)
    {
        if ((*w)->GetBounds().contains(viewPosition))
        {
            mCurrentSelection = w;
        }
    }
}