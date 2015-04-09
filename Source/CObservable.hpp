//
//  CObservable.hpp
//  TimGameLib
//
//  Created by Tim Brier on 09/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimGameLib__CObservable__
#define __TimGameLib__CObservable__

#include "CObserver.hpp"
#include <list>

class CObservable
{
public:
    virtual void Subscribe(CObserver *theObserver);
    virtual void Unsubscribe(CObserver *theObserver);
    virtual void Publish(void *data);
    
private:
    std::list<CObserver *> mSubscribers;
};

#endif /* defined(__TimGameLib__CObservable__) */
