//
//  CEventListener.hpp
//  TimGameLib
//
//  Created by Tim Brier on 09/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimGameLib__CEventListener__
#define __TimGameLib__CEventListener__

#include "CObserver.hpp"
#include "SFMLIntegration/SFMLIntegration.hpp"

class CEventListener : public CObserver
{
public:
    virtual void ReactToEvent(CEvent *theEvent) = 0;
    virtual void React(void *data);
};

#endif /* defined(__TimGameLib__CEventListener__) */
