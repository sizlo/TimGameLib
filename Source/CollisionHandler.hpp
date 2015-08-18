//
//  CollisionHandler.hpp
//  TimGameLib
//
//  Created by Tim Brier on 28/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CollisionHandler__
#define __TimeGameLib__CollisionHandler__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include "SFMLIntegration/SFMLIntegration.hpp"

// =============================================================================
// Enums
// -----------------------------------------------------------------------------
enum ECollisionResolveOptions
{
    // Which object(s) to move when seperating the colliding objects
    kCRMoveLeft         = 1 << 0,
    kCRMoveRight        = 1 << 1,
    kCRMoveBoth         = 1 << 2
};

enum ECollisionDetectionType
{
    kCDOverlapping,     // Do the shapes overlap at all
    kCDLhsInside,       // Is the lhs shape completely inside the rhs shape
    kCDRhsInside        // Is the rhs shape completely inside the lhs shape
};

// =============================================================================
// Namespace definition
// -----------------------------------------------------------------------------
namespace CollisionHandler
{
    // Check for collisions between 2 convex shapes
    bool AreColliding(CConvexShape &lhs,
                      CConvexShape &rhs,
                      CVector2f *correctionVector,
                      ECollisionDetectionType detectionType = kCDOverlapping);
    
    // Check if 2 shapes collide in an axis
    bool AreCollidingInAxis(CConvexShape &lhs,
                            CConvexShape &rhs,
                            CVector2f axis,
                            CVector2f *correctionVector,
                            ECollisionDetectionType detectionType);
    
    // Check if a line intersects a shape
    bool AreIntersecting(CLine &theLine,
                         CConvexShape &theShape,
                         std::list<CVector2f> *intersectionPoints,
                         bool returnCorners = true);
    
    // Project a point onto an axis
    float Project(CVector2f point, CVector2f axis);
    
    // Seperate the 2 penetrating bodies
    void Seperate(CConvexShape &lhs,
                  CConvexShape &rhs,
                  CVector2f correctionVector,
                  ECollisionResolveOptions theOptions);
}


#endif /* defined(__TimeGameLib__CollisionHandler__) */
