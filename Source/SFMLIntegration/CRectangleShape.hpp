//
//  CRectangleShape.hpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#ifndef __MenuTest__CRectangleShape__
#define __MenuTest__CRectangleShape__

#include <iostream>

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "CConvexShape.hpp"

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CRectangleShape : public CConvexShape
{
public:
    CRectangleShape(CVector2f size, bool centreOrigin = false);
    CRectangleShape(float width, float height, bool centreOrigin = false);
    ~CRectangleShape();
};

#endif /* defined(__MenuTest__CRectangleShape__) */
