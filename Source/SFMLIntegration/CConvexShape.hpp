//
//  CConvexShape.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CConvexShape__
#define __TimeGameLib__CConvexShape__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include <list>
#include "CVector2.hpp"
#include "../CLine.hpp"

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CConvexShape : public sf::ConvexShape
{
public:
    CConvexShape(unsigned int pointCount = 0);
    CConvexShape(std::list<CVector2f> &thePoints);
    ~CConvexShape();
    
    // Build and return a list of lines within the shape
    std::list<CLine> GetGlobalLines();
    // Return a point in global coordinates
    CVector2f GetGlobalPoint(unsigned int index);
    
    // Collision Detection
    bool IsCollidingWith(CConvexShape &other,
                         CVector2f *correctionVector = NULL);
    bool IsInside(CConvexShape &other, CVector2f *correctionVector = NULL);
    bool IsContaining(CConvexShape &other, CVector2f *correctionVector = NULL);
};

#endif /* defined(__TimeGameLib__CConvexShape__) */
