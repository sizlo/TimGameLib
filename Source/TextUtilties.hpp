//
//  TextUtilties.hpp
//  TimGameLib
//
//  Created by Tim Brier on 25/09/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__TextUtilties__
#define __TimeGameLib__TextUtilties__

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "SFMLIntegration/SFMLIntegration.hpp"

// =============================================================================
// Namespace Definition
// -----------------------------------------------------------------------------
namespace TextUtilities
{
    // Load or get the desired font
    CFont * GetFont(EFontType fontType);
    // Delete all loaded fonts
    void DeleteFonts();
    
    // Cleanup before quitting
    void Cleanup();
};

#endif /* defined(__TimeGameLib__TextUtilties__) */
