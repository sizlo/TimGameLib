//
//  CVector2.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CVector2__
#define __TimeGameLib__CVector2__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
template <typename T> class CVector2 : public sf::Vector2<T>
{
public:
    CVector2();
    CVector2(T X, T Y);
    CVector2(sf::Vector2<T> other);
    ~CVector2();
    
    // Conversion from another vector type
    template <typename U> CVector2(CVector2<U> other);
    
    // Get the magnitude of the vector
    T GetMagnitude();
    
    // Normalise a vector to unit length 1
    void Normalise();
    
    // Get the dot product of this and another vector
    T DotProduct(CVector2<T> rhs);
    
    // Get the angle between the 2 vectors in degrees
    float AngleBetween(CVector2<T> rhs);
    
    // Get the angle needed to rotate this vector for it to align with a given
    // vector
    float AngleTo(CVector2<T> rhs);
    
    // Get the component of a vector in the given direction
    CVector2<T> GetComponentInDirection(CVector2<T> direction);
};

// =============================================================================
// Include the method definitions since they are required prior to instantiating
// a template class
// -----------------------------------------------------------------------------
#include "CVector2.cpp"

// =============================================================================
// Common typedefs
// -----------------------------------------------------------------------------
typedef CVector2<float> CVector2f;
typedef CVector2<int>   CVector2i;

#endif /* defined(__TimeGameLib__CVector2__) */
