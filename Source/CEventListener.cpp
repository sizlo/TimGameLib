//
//  CEventListener.cpp
//  TimGameLib
//
//  Created by Tim Brier on 09/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CEventListener.hpp"

void CEventListener::React(void *data)
{
    ReactToEvent(static_cast<CEvent *>(data));
}