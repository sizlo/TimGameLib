//
//  CIntRect.hpp
//  TimGameLib
//
//  Created by Tim Brier on 13/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimGameLib__CIntRect__
#define __TimGameLib__CIntRect__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CIntRect : public sf::IntRect
{
public:
    CIntRect();
    CIntRect(sf::IntRect other);
    CIntRect(int left, int top, int width, int height);
    ~CIntRect();
};

#endif /* defined(__TimGameLib__CIntRect__) */
