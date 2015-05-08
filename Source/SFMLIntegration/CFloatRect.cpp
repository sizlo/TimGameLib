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
#include "CColour.hpp"

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

CConvexShape CFloatRect::GetOutlineShape()
{
    CConvexShape shape = CConvexShape(4);
    shape.setPoint(0, CVector2f(left, top));
    shape.setPoint(1, CVector2f(left + width, top));
    shape.setPoint(2, CVector2f(left + width, top + height));
    shape.setPoint(3, CVector2f(left, top + height));
    shape.setFillColor(CColour(0, 0, 0, 0));
    shape.setOutlineColor(CColour::Black);
    shape.setOutlineThickness(1.0f);
    return shape;
}
