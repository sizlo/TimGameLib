//
//  CVector2.cpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <math.h>

// =============================================================================
// Constants
// -----------------------------------------------------------------------------
#define RAD_TO_DEG 57.2957795131

// =============================================================================
// CVector2 constructor/destructor
// -----------------------------------------------------------------------------
template <typename T>
CVector2<T>::CVector2() : sf::Vector2<T>()
{
    
}

template <typename T>
CVector2<T>::CVector2(T X, T Y) : sf::Vector2<T>(X, Y)
{
    
}

template <typename T>
CVector2<T>::CVector2(sf::Vector2<T> other)
: sf::Vector2<T>(other)
{
    
}

template <typename T>
CVector2<T>::~CVector2()
{
    
}

template <typename T> template <typename U>
CVector2<T>::CVector2(CVector2<U> other) : sf::Vector2<T>(other)
{
    
}

// =============================================================================
// CVector2::GetMagnitude
// -----------------------------------------------------------------------------
template <typename T>
T CVector2<T>::GetMagnitude()
{
    return sqrt(this->x * this->x + this->y * this->y);
}

// =============================================================================
// CVector2::Normalise
// -----------------------------------------------------------------------------
template <typename T>
void CVector2<T>::Normalise()
{
    T length = GetMagnitude();
    
    // Bail out if our length is 0
    if (length == 0)
    {
        return;
    }
    
    this->x /= length;
    this->y /= length;
}

// =============================================================================
// CVector2::Rotate
// -----------------------------------------------------------------------------
template <typename T>
void CVector2<T>::Rotate(float angle)
{
    angle *= DEG_TO_RAD;
    
    float newX = this->x * cos(angle) - this->y * sin(angle);
    float newY = this->x * sin(angle) + this->y * cos(angle);
    this->x = newX;
    this->y = newY;
}

// =============================================================================
// CVector2::DotProduct
// -----------------------------------------------------------------------------
template <typename T>
T CVector2<T>::DotProduct(CVector2<T> rhs)
{
    return (this->x * rhs.x) + (this->y * rhs.y);
}

// =============================================================================
// CVector2::AngleBetween
// -----------------------------------------------------------------------------
template <typename T>
float CVector2<T>::AngleBetween(CVector2<T> rhs)
{
    float rads = atan2(this->y - rhs.y, this->x - rhs.x);
    float degs = rads * RAD_TO_DEG;
    return degs;
}

// =============================================================================
// CVector2::AngleBetween
// -----------------------------------------------------------------------------
template <typename T>
float CVector2<T>::AngleTo(CVector2<T> rhs)
{
    float rads = atan2(rhs.y, rhs.x) - atan2(this->y, this->x);
    if (rads < 0)
    {
        rads += 2 * M_PI;
    }
    float degs = rads * RAD_TO_DEG;
    return degs;
}

// =============================================================================
// CVector2::GetComponentInDirection
// -----------------------------------------------------------------------------
template <typename T>
CVector2<T> CVector2<T>::GetComponentInDirection(CVector2<T> direction)
{
    // Normalise the direction
    direction.Normalise();
    
    return DotProduct(direction) * direction;
}