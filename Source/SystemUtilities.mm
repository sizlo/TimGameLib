//
//  SystemUtilities.mm
//  TimGameLib
//
//  Created by Tim Brier on 26/09/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "SystemUtilities.hpp"

#if TGL_MAC
#import <Foundation/Foundation.h>
#elif TGL_WINDOWS
#include <windows.h>
#include <Shlwapi.h>
#endif

namespace SystemUtilities
{
    
// =============================================================================
// Namespace globals
// -----------------------------------------------------------------------------
std::list<CEvent>   theInputEvents;
CWindow             *theGameWindow;
CEventPublisher     theEventPublisher;
std::list<CEvent>   theDragEvents;
    
// =============================================================================
// SystemUtilities::Init
// Initialise at program launch
// -----------------------------------------------------------------------------
void Init(CWindow *theWindow)
{
    theGameWindow = theWindow;
    
    // Add a drag event for each kind of mouse button
    CEvent leftDrag, rightDrag, middleDrag, x1Drag, x2Drag;
    leftDrag.SetExtraType(CEvent::ExtraEventType::MouseDrag);
    leftDrag.mouseDrag.button = CMouse::Left;
    rightDrag.SetExtraType(CEvent::ExtraEventType::MouseDrag);
    rightDrag.mouseDrag.button = CMouse::Right;
    middleDrag.SetExtraType(CEvent::ExtraEventType::MouseDrag);
    middleDrag.mouseDrag.button = CMouse::Middle;
    x1Drag.SetExtraType(CEvent::ExtraEventType::MouseDrag);
    x1Drag.mouseDrag.button = CMouse::XButton1;
    x2Drag.SetExtraType(CEvent::ExtraEventType::MouseDrag);
    x2Drag.mouseDrag.button = CMouse::XButton2;
    
    theDragEvents.push_back(leftDrag);
    theDragEvents.push_back(rightDrag);
    theDragEvents.push_back(middleDrag);
    theDragEvents.push_back(x1Drag);
    theDragEvents.push_back(x2Drag);
}

// =============================================================================
// SystemUtilities::GetResourcePath
// Return the platform specific path to the resource location
// -----------------------------------------------------------------------------
std::string GetResourcePath()
{
    std::string theReturnPath;

#if TGL_MAC
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSBundle* bundle = [NSBundle mainBundle];

    if (bundle == nil)
    {
        DEBUG_LOG("Resource location can't be found: bundle is nil");
    }
    else
    {
        NSString* path = [bundle resourcePath];
        theReturnPath = [path UTF8String] + std::string("/");
    }

    [pool drain];
#elif TGL_WINDOWS
	char buffer[MAX_PATH];
	DWORD result = GetModuleFileName(NULL, buffer, MAX_PATH);
	if (result == 0)
	{
		DEBUG_LOG("Failed to get module filename, error code %d", GetLastError());
	}
	else
	{
		PathRemoveFileSpec(buffer);
		theReturnPath = std::string(buffer) + std::string("\\");
	}
#endif

    return theReturnPath;
}
    
// =============================================================================
// SystemUtilities::SubscribeToEvents
// -----------------------------------------------------------------------------
void SubscribeToEvents(CEventListener *theListener)
{
    theEventPublisher.Subscribe(theListener);
}
    
// =============================================================================
// SystemUtilities::UnsubscribeToEvents
// -----------------------------------------------------------------------------
void UnsubscribeToEvents(CEventListener *theListener)
{
    theEventPublisher.Unsubscribe(theListener);
}
    
// =============================================================================
// SystemUtilities::PublishEvent
// -----------------------------------------------------------------------------
void PublishEvent(CEvent theEvent)
{
    std::list<CEvent> extraEventsToPublish;
    
    // If a button is pressed clear its drag event and set its start location
    if (theEvent.type == CEvent::EventType::MouseButtonPressed)
    {
        for (CEvent &dragEvent: theDragEvents)
        {
            if (dragEvent.mouseDrag.button == theEvent.mouseButton.button)
            {
                dragEvent.mouseDrag.inBetweenLocations.clear();
                int x = theEvent.mouseButton.x;
                int y = theEvent.mouseButton.y;
                dragEvent.mouseDrag.pressLocation = CVector2f(x, y);
                
                dragEvent.mouseDrag.inProgress = true;
            }
        }
    }
    
    // If the mouse is moved add this location to any in progress mouseDrags
    if (theEvent.type == CEvent::EventType::MouseMoved)
    {
        for (CEvent &dragEvent: theDragEvents)
        {
            if (dragEvent.mouseDrag.inProgress)
            {
                int x = theEvent.mouseMove.x;
                int y = theEvent.mouseMove.y;
                dragEvent.mouseDrag.inBetweenLocations.push_back(CVector2f(x, y));
            }
        }
    }
    
    // If a button is released set its end location
    if (theEvent.type == CEvent::EventType::MouseButtonReleased)
    {
        for (CEvent &dragEvent: theDragEvents)
        {
            if (dragEvent.mouseDrag.button == theEvent.mouseButton.button
                && dragEvent.mouseDrag.inProgress)
            {
                int x = theEvent.mouseButton.x;
                int y = theEvent.mouseButton.y;
                dragEvent.mouseDrag.releaseLocation = CVector2f(x, y);
                
                dragEvent.mouseDrag.inProgress = false;
                
                // Publish this finished drag if it actually moved
                if (dragEvent.mouseDrag.inBetweenLocations.size() > 0)
                {
                    extraEventsToPublish.push_back(dragEvent);
                }
            }
        }
    }
    
    theEventPublisher.PublishEvent(theEvent);
    
    for (CEvent extraEvent: extraEventsToPublish)
    {
        theEventPublisher.PublishEvent(extraEvent);
    }
}
    
// =============================================================================
// SystemUtilities::GetMousePosition
// Get the mouse position relative to the windows current view
// -----------------------------------------------------------------------------
CVector2f GetMousePosition()
{
    CVector2i windowPosition = CMouse::getPosition(*theGameWindow);
    CVector2f viewPosition = theGameWindow->mapPixelToCoords(windowPosition);
    
    return viewPosition;
}
    
} // namespace SystemUtilities

