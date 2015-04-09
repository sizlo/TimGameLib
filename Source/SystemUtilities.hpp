//
//  SystemUtilities.hpp
//  TimGameLib
//
//  Created by Tim Brier on 26/09/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__SystemUtilities__
#define __TimeGameLib__SystemUtilities__

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "SFMLIntegration/SFMLIntegration.hpp"
#include "CEventPublisher.hpp"
#include "CEventListener.hpp"
#include <string>
#include <list>

// =============================================================================
// Namespace definition
// -----------------------------------------------------------------------------
namespace SystemUtilities
{
    // Initialise at program launch
    void Init(CWindow *theWindow);
    // Return the platform specific path to the resource location
    std::string GetResourcePath();
    
    // Subscribe to events
    void SubscribeToEvents(CEventListener *theListener);
    // Unsubscribe to events
    void UnsubscribeToEvents(CEventListener *theListener);
    // Publish an event
    void PublishEvent(CEvent theEvent);
    
    
    // Get the mouse position relative to the window
    CVector2f GetMousePosition();
};

#endif /* defined(__TimeGameLib__SystemUtilities__) */
