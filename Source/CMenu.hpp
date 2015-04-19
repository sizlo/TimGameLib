//
//  CMenu.hpp
//  TimGameLib
//
//  Created by Tim Brier on 02/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef TimeGameLib_CMenu_hpp
#define TimeGameLib_CMenu_hpp

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CRenderable.hpp"
#include "CUpdateable.hpp"
#include "CGameLocation.hpp"
#include "CMessageListener.hpp"
#include "CMessageBroadcaster.hpp"

// =============================================================================
// Abstract class definition
// -----------------------------------------------------------------------------
class CMenu :   public CRenderable,
                public CUpdateable,
                public CGameLocation,
                public CMessageListener<CEvent>
{
public:
    virtual ~CMenu(){};
    
    virtual void Enter();
    virtual void Draw(CWindow *theWindow) = 0;
    virtual void Update(CTime elapsedTime) = 0;
    virtual bool HandleMessage(CEvent theEvent) = 0;
    virtual void Exit();
};

void CMenu::Enter()
{
    CMessageBroadcaster<CEvent>::Subscribe(this);
}

void CMenu::Exit()
{
    CMessageBroadcaster<CEvent>::Unsubscribe(this);
}

#endif
