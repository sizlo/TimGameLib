//
//  SFMLIntegration.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef TimeGameLib_SFMLIntegration_hpp
#define TimeGameLib_SFMLIntegration_hpp

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include "CDrawable.hpp"
#include "CClock.hpp"
#include "CColour.hpp"
#include "CEvent.hpp"
#include "CFloatRect.hpp"
#include "CIntRect.hpp"
#include "CImage.hpp"
#include "CKeyboard.hpp"
#include "CMouse.hpp"
#include "CTexture.hpp"
#include "CTime.hpp"
#include "CVector2.hpp"
#include "CFont.hpp"
#include "CMusic.hpp"
#include "CConvexShape.hpp"
#include "CCircleShape.hpp"
#include "CSprite.hpp"
#include "CText.hpp"
#include "CWindow.hpp"
#include "CView.hpp"
#include "CVertex.hpp"

#include "../GameOptions.hpp"


// =============================================================================
// Helper methods
// -----------------------------------------------------------------------------
static void InitSFML(sf::Window *theWindow)
{
    DEBUG_LOG("Initialising SFML v%d.%d.%d", SFML_VERSION_MAJOR, SFML_VERSION_MINOR, SFML_VERSION_PATCH);

    // When we're not in debug mode redirect SFML errors to nowhere
#if !TGL_DEBUG
    sf::err().rdbuf(NULL);
#endif
    
    // Don't repeat keypress events
    theWindow->setKeyRepeatEnabled(false);
    
#if USE_SFML_VSYNC
    theWindow->setVerticalSyncEnabled(GameOptions::doVsync);
#endif
}

#endif
