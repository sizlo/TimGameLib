//
//  CEventPublisher.hpp
//  TimGameLib
//
//  Created by Tim Brier on 09/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimGameLib__CEventPublisher__
#define __TimGameLib__CEventPublisher__

#include "CObservable.hpp"
#include "SFMLIntegration/SFMLIntegration.hpp"

class CEventPublisher : public CObservable
{
public:
    void PublishEvent(CEvent theEvent);
};

#endif /* defined(__TimGameLib__CEventPublisher__) */
