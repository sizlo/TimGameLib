//
//  CMenu.cpp
//  TimGameLib
//
//  Created by Tim Brier on 02/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#include "CMenu.hpp"

void CMenu::Enter()
{
    CMessageBroadcaster<CEvent>::Subscribe(this);
}

void CMenu::Exit()
{
    CMessageBroadcaster<CEvent>::Unsubscribe(this);
}