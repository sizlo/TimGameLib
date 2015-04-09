//
//  CObservable.cpp
//  TimGameLib
//
//  Created by Tim Brier on 09/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CObservable.hpp"

void CObservable::Subscribe(CObserver *theObserver)
{
    mSubscribers.push_back(theObserver);
}

void CObservable::Unsubscribe(CObserver *theObserver)
{
    mSubscribers.remove(theObserver);
}

void CObservable::Publish(void *data)
{
    for (CObserver *current: mSubscribers)
    {
        current->React(data);
    }
}