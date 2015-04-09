//
//  CEvent.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CEvent__
#define __TimeGameLib__CEvent__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "CVector2.hpp"
#include <list>

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CEvent : public sf::Event
{
public:
    
    struct MouseDragEvent
    {
        CVector2f               pressLocation;
        CVector2f               releaseLocation;
        std::list<CVector2f>    inBetweenLocations;
        sf::Mouse::Button       button;
        bool                    inProgress = false;
    };
    
    enum ExtraEventType
    {
        MouseDrag = CEvent::EventType::Count
    };
    
    bool IsExtra(){return mIsExtra;};
    
    void SetExtraType(ExtraEventType theType)
    {
        mIsExtra = true;
        type = CEvent::EventType::Count;
        extraType = theType;
    };
    
    ExtraEventType extraType;
    
    // Data for extra events
    MouseDragEvent mouseDrag;
    
private:
    bool mIsExtra = false;
};

#endif /* defined(__TimeGameLib__CEvent__) */
