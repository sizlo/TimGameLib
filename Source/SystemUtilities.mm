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
// Explicitly include the prefix file as cotire for cmake doesn't auto include
// it for .mm
#include "TimGameLib_Prefix.pch"

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
CWindow             *theGameWindow;
    
// =============================================================================
// SystemUtilities::Init
// Initialise at program launch
// -----------------------------------------------------------------------------
void Init(CWindow *theWindow)
{
    theGameWindow = theWindow;
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
// SystemUtilities::GetMousePosition
// Get the mouse position relative to the windows current view
// -----------------------------------------------------------------------------
CVector2f GetMousePosition()
{
    CVector2i windowPosition = CMouse::getPosition(*theGameWindow);
    CVector2f viewPosition = GetViewPosition(windowPosition);
    
    return viewPosition;
}
    
// =============================================================================
// SystemUtilities::GetViewPosition
// Map window position to view position
// -----------------------------------------------------------------------------
CVector2f GetViewPosition(CVector2i windowPosition)
{
    CVector2f viewPosition = theGameWindow->mapPixelToCoords(windowPosition);
    return viewPosition;
}
    
} // namespace SystemUtilities

