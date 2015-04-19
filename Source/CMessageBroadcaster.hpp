//
//  CMessageBroadcaster.hpp
//  TimGameLib
//
//  Created by Tim Brier on 19/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef TimGameLib_CMessageBroadcaster_hpp
#define TimGameLib_CMessageBroadcaster_hpp

#include "CMessageListener.hpp"
#include <list>

template<typename T>
struct SSubcriptionRequest
{
    CMessageListener<T> *listener;
    bool subscriptionRequested;
};

template <typename T>
class CMessageBroadcaster
{
public:
    static void BroadcastMessage(T m);
    static void Subscribe(CMessageListener<T> *l);
    static void Unsubscribe(CMessageListener<T> *l);
    
private:
    static std::list<CMessageListener<T> *> smSubscribers;
    static std::list<SSubcriptionRequest<T>> smPendingRequests;
    static bool smIsBroadcasting;
};

template <typename T>
std::list<CMessageListener<T> *> CMessageBroadcaster<T>::smSubscribers;

template <typename T>
std::list<SSubcriptionRequest<T>> CMessageBroadcaster<T>::smPendingRequests;

template <typename T>
bool CMessageBroadcaster<T>::smIsBroadcasting = false;

template <typename T>
void CMessageBroadcaster<T>::BroadcastMessage(T m)
{
    smIsBroadcasting = true;
    
    for (CMessageListener<T> *l: smSubscribers)
    {
        bool messageWasEaten = false;
        messageWasEaten = l->HandleMessage(m);
        if (messageWasEaten)
        {
            break;
        }
    }
    
    for (SSubcriptionRequest<T> r: smPendingRequests)
    {
        if (r.subscriptionRequested)
        {
            smSubscribers.push_back(r.listener);
        }
        else
        {
            smSubscribers.remove(r.listener);
        }
    }
    
    smIsBroadcasting = false;
}

template <typename T>
void CMessageBroadcaster<T>::Subscribe(CMessageListener<T> *l)
{
    if (!smIsBroadcasting)
    {
        smSubscribers.push_back(l);
    }
    else
    {
        SSubcriptionRequest<T> r;
        r.subscriptionRequested = true;
        r.listener = l;
        smPendingRequests.push_back(r);
    }
}

template <typename T>
void CMessageBroadcaster<T>::Unsubscribe(CMessageListener<T> *l)
{
    if (!smIsBroadcasting)
    {
        smSubscribers.remove(l);
    }
    else
    {
        SSubcriptionRequest<T> r;
        r.subscriptionRequested = false;
        r.listener = l;
        smPendingRequests.push_back(r);
    }
}

#endif
