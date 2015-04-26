//
//  CConvexShape.cpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CConvexShape.hpp"
#include "../CollisionHandler.hpp"

// =============================================================================
// CConvexShape constructor/destructor
// -----------------------------------------------------------------------------
CConvexShape::CConvexShape(unsigned int pointCount /* = 0 */)
: sf::ConvexShape(pointCount)
{
    
}

CConvexShape::CConvexShape(std::list<CVector2f> &thePoints)
: sf::ConvexShape((int) thePoints.size())
{
    int theIndex = 0;
    
    FOR_EACH_IN_LIST(CVector2f, thePoints)
    {
        setPoint(theIndex, (*it));
        theIndex++;
    }
}

CConvexShape::~CConvexShape()
{
    
}

// =============================================================================
// CConvexShape::GetLines
// Build and return a list of lines within the shape using global coords
// -----------------------------------------------------------------------------
std::list<CLine> CConvexShape::GetGlobalLines()
{
    std::list<CLine> theResult;
    
    int numPoints = getPointCount();
    CVector2f pos = getPosition();
    
    for (int i = 0; i < numPoints; i++)
    {
        CVector2f start = GetGlobalPoint(i);
        CVector2f end = GetGlobalPoint((i+1) % numPoints);
        
        theResult.push_back(CLine(start, end));
    }
    
    return theResult;
}

// =============================================================================
// CConvexShape::GetGlobalPoint
// Get the indexth point in the shape in global coords
// -----------------------------------------------------------------------------
CVector2f CConvexShape::GetGlobalPoint(unsigned int index)
{
    CVector2f localPoint = getPoint(index);
    CVector2f scaledPoint = localPoint;
    CVector2f scale = getScale();
    scaledPoint.x *= scale.x;
    scaledPoint.y *= scale.y;
    
    return getPosition() + scaledPoint;
}

// =============================================================================
// CConvexShape::IsCollidingWith
// -----------------------------------------------------------------------------
bool CConvexShape::IsCollidingWith(CConvexShape &other,
                                   CVector2f *correctionVector /* = NULL */)
{
    CVector2f cv;
    bool theResult = CollisionHandler::AreColliding(*this,
                                                    other,
                                                    &cv,
                                                    kCDOverlapping);
    
    if (correctionVector != NULL)
    {
        *correctionVector = cv;
    }
    
    return theResult;
}

// =============================================================================
// CConvexShape::IsInside
// -----------------------------------------------------------------------------
bool CConvexShape::IsInside(CConvexShape &other,
                            CVector2f *correctionVector /* = NULL */)
{
    CVector2f cv;
    bool theResult = CollisionHandler::AreColliding(*this,
                                                    other,
                                                    &cv,
                                                    kCDLhsInside);
    
    if (correctionVector != NULL)
    {
        *correctionVector = cv;
    }
    
    return theResult;
}

// =============================================================================
// CConvexShape::IsCollidingWith
// -----------------------------------------------------------------------------
bool CConvexShape::IsContaining(CConvexShape &other,
                                CVector2f *correctionVector /* = NULL */)
{
    CVector2f cv;
    bool theResult = CollisionHandler::AreColliding(*this,
                                                    other,
                                                    &cv,
                                                    kCDRhsInside);
    
    if (correctionVector != NULL)
    {
        *correctionVector = cv;
    }
    
    return theResult;
}