//
//  CText.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CText__
#define __TimeGameLib__CText__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "CFont.hpp"
#include "CVector2.hpp"

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CText : public sf::Text
{
public:
    CText();
    CText(std::string theString, CFont &theFont, unsigned int theFontSize = 12);
    CText(std::string theString, CVector2f thePos, unsigned int theFontSize = 12);
    ~CText();
};

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CBoundedText : public CText
{
public:
    CBoundedText();
    CBoundedText(std::string theString,
                 float maxWidth,
                 CFont &theFont,
                 unsigned int theFontSize);
    ~CBoundedText();
};

#endif /* defined(__TimeGameLib__CText__) */
