//
//  CFloatRect.cpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CFloatRect.hpp"

// =============================================================================
// CFloatRect constructor/destructor
// -----------------------------------------------------------------------------
CFloatRect::CFloatRect() : sf::FloatRect()
{
    
}

CFloatRect::CFloatRect(sf::FloatRect other) : sf::FloatRect(other)
{
    
}

CFloatRect::CFloatRect(float left, float top, float width, float height)
:   sf::FloatRect(left, top, width, height)
{
    
}

CFloatRect::~CFloatRect()
{
    
}
