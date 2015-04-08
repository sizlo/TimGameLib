//
//  CColour.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CColour__
#define __TimeGameLib__CColour__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CColour : public sf::Color
{
public:
    CColour(sf::Uint8 red,
            sf::Uint8 green,
            sf::Uint8 blue,
            sf::Uint8 alpha = 255);
    CColour(sf::Color theColour);
    ~CColour();
};

#endif /* defined(__TimeGameLib__CColour__) */
