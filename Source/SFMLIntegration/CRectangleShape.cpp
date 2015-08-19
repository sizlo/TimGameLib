//
//  CRectangleShape.cpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#include "CRectangleShape.hpp"

CRectangleShape::CRectangleShape(CVector2f size, bool centreOrigin /* = false */)
: CRectangleShape(size.x, size.y, centreOrigin)
{

}

CRectangleShape::CRectangleShape(float width, float height, bool centreOrigin /* = false */)
: CConvexShape(4)
{
    if (centreOrigin)
    {
        float w2 = width / 2.0f;
        float h2 = height / 2.0f;
        setPoint(0, CVector2f(-w2, -h2));
        setPoint(1, CVector2f(w2, -h2));
        setPoint(2, CVector2f(w2, h2));
        setPoint(3, CVector2f(-w2, h2));
    }
    else
    {
        setPoint(0, CVector2f(0.0f, 0.0f));
        setPoint(1, CVector2f(width, 0.0f));
        setPoint(2, CVector2f(width, height));
        setPoint(3, CVector2f(0.0f, height));
    }
}

CRectangleShape::~CRectangleShape()
{
    
}