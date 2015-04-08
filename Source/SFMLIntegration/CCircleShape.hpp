//
//  CCircleShape.hpp
//  TimGameLib
//
//  Created by Tim Brier on 19/02/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CCircleShape__
#define __TimeGameLib__CCircleShape__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "CConvexShape.hpp"

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CCircleShape : public CConvexShape
{
public:
    CCircleShape(float radius, int pointcount = 30);
    ~CCircleShape();
};

#endif /* defined(__TimeGameLib__CCircleShape__) */
