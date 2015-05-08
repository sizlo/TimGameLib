//
//  CGUIMenu.cpp
//  TimGameLib
//
//  Created by Tim Brier on 08/05/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CGUIMenu.hpp"
#include "CGame.hpp"

CGUIMenu::CGUIMenu()
{
    
}

CGUIMenu::~CGUIMenu()
{
    
}

void CGUIMenu::Update(CTime elapsedTime)
{
    
}

void CGUIMenu::Draw(CWindow *theWindow)
{
    for (CWidget w : mWidgets)
    {
        w.Draw(theWindow);
    }
    
    mCurrentSelection->DrawHighlight(theWindow);
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
    bool theResult = false;
    
    if (theEvent.type == CEvent::KeyPressed)
    {
        if (theEvent.key.code == CKeyboard::W)
        {
            if (mCurrentSelection != mWidgets.begin())
            {
                mCurrentSelection--;
            }
        }
        else if (theEvent.key.code == CKeyboard::S)
        {
            mCurrentSelection++;
            if (mCurrentSelection == mWidgets.end())
            {
                mCurrentSelection--;
            }
        }
    }
    
    return theResult;
}

void CGUIMenu::AddWidget(CWidget theWidget)
{
    mWidgets.push_back(theWidget);
}