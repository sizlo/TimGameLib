//
//  CRectangleShape.cpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#include "CRectangleShape.hpp"

CRectangleShape::CRectangleShape(CVector2f size)
{
    CRectangleShape(size.x, size.y);
}

CRectangleShape::CRectangleShape(float width, float height)
: CConvexShape(4)
{
    setPoint(0, CVector2f(0.0f, 0.0f));
    setPoint(1, CVector2f(width, 0.0f));
    setPoint(2, CVector2f(width, height));
    setPoint(3, CVector2f(0.0f, height));
}

CRectangleShape::~CRectangleShape()
{
    
}