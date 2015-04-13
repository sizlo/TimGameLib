//
//  CIntRect.cpp
//  TimGameLib
//
//  Created by Tim Brier on 13/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CIntRect.hpp"

// =============================================================================
// CIntRect constructor/destructor
// -----------------------------------------------------------------------------
CIntRect::CIntRect() : sf::IntRect()
{
    
}

CIntRect::CIntRect(sf::IntRect other) : sf::IntRect(other)
{
    
}

CIntRect::CIntRect(int left, int top, int width, int height)
:   sf::IntRect(left, top, width, height)
{
    
}

CIntRect::~CIntRect()
{
    
}