//
//  CObserver.hpp
//  TimGameLib
//
//  Created by Tim Brier on 09/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimGameLib__CObserver__
#define __TimGameLib__CObserver__

class CObserver
{
public:
    virtual void React(void *data) = 0;
};

#endif /* defined(__TimGameLib__CObserver__) */
