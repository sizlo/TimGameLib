//
//  CVertex.hpp
//  TimGameLib
//
//  Created by Tim Brier on 31/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CVertex__
#define __TimeGameLib__CVertex__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "CVector2.hpp"
#include "CColour.hpp"

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CVertex : public sf::Vertex
{
public:
    CVertex();
    CVertex(CVector2f thePosition, CColour theColour);
    ~CVertex();
};


#endif /* defined(__TimeGameLib__CVertex__) */
