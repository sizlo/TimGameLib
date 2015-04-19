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
    
    // Get the mouse position relative to the window
    CVector2f GetMousePosition();
    // Map window position to view position
    CVector2f GetViewPosition(CVector2i windowPosition);
};

#endif /* defined(__TimeGameLib__SystemUtilities__) */
