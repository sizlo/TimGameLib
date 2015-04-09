//
//  CEventPublisher.cpp
//  TimGameLib
//
//  Created by Tim Brier on 09/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CEventPublisher.hpp"

void CEventPublisher::PublishEvent(CEvent theEvent)
{
    Publish(&theEvent);
}