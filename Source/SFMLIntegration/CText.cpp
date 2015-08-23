//
//  CText.cpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CText.hpp"
#include "../TextUtilties.hpp"
#include <sstream>

// =============================================================================
// CText constructor/destructor
// -----------------------------------------------------------------------------
CText::CText() : sf::Text()
{
    
}

CText::CText(std::string theString, CFont &theFont, unsigned int theFontSize /* = 12 */)
: sf::Text(theString, theFont, theFontSize)
{
    
}

CText::CText(std::string theString, CVector2f thePos, unsigned int theFontSize /* = 12 */)
: sf::Text(theString, *TextUtilities::GetFont(kFontTypeDefault), theFontSize)
{
    setPosition(thePos);
}

CText::~CText()
{
    
}

// =============================================================================
// CBoundedText constructor/destructor
// -----------------------------------------------------------------------------
CBoundedText::CBoundedText() : CText()
{
    
}

CBoundedText::CBoundedText(std::string theString,
                           float maxWidth,
                           CFont &theFont,
                           unsigned int theFontSize)
: CText("", theFont, theFontSize)
{
    // Split the string into words
    std::stringstream ss(theString);
    std::string item;
    char delim = ' ';
    std::list<std::string> words;
    while (std::getline(ss, item, delim))
    {
        words.push_back(item);
    }
    
    // Build the string word by word, inserting a new line when it gets too long
	std::string theBoundedString = "";
	if (!words.empty())
	{
		theBoundedString += words.front();
		words.pop_front();
	}

    for (auto it = words.begin(); it != words.end(); it++)
    {
        std::string word = *it;
        char delim = ' ';
        std::string sizeTestString = theBoundedString + delim + word;
        CText sizeTest(sizeTestString, theFont, theFontSize);
        if (sizeTest.getLocalBounds().width > maxWidth)
        {
            delim = '\n';
        }
        theBoundedString += delim + word;
    }
    
    // Use this newly built string
    setString(theBoundedString);
}

CBoundedText::~CBoundedText()
{
    
}