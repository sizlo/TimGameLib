//
//  XMLInterpreter.cpp
//  TimGameLib
//
//  Created by Tim Brier on 11/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "XMLInterpreter.hpp"
#include "SystemUtilities.hpp"
#include "GameOptions.hpp"

namespace XMLInterpreter
{

// =============================================================================
// XMLInterpreter::ReadConfig
// Set the game options from a config file
// -----------------------------------------------------------------------------
void ReadConfig(std::string filename)
{
    // Read the file
    pugi::xml_document theDocument;
    std::string fullName = SystemUtilities::GetResourcePath() + filename;
    pugi::xml_parse_result theResult = theDocument.load_file(fullName.c_str());

    if (theResult.status != pugi::status_ok)
    {
        DEBUG_LOG("Error parsisng config xml file: %s", filename.c_str());
        DEBUG_LOG("Status code: %d", theResult.status);
        
        // Bail out
        return;
    }

    // Begin processing
    pugi::xml_node theRoot = theDocument.document_element();

    // Go through all children of the root and process each in turn
    for (pugi::xml_node theNode = theRoot.first_child();
         theNode;
         theNode = theNode.next_sibling())
    {
        if (strcmp(theNode.name(), "windowHeight") == 0)
        {
            GameOptions::windowHeight = GetInt(theNode);
        }
        else if (strcmp(theNode.name(), "windowWidth") == 0)
        {
            GameOptions::windowWidth = GetInt(theNode);
        }
        else if (strcmp(theNode.name(), "useVsync") == 0)
        {
            GameOptions::doVsync = GetBool(theNode);
        }
        else if (strcmp(theNode.name(), "fullscreen") == 0)
        {
            GameOptions::fullscreen = GetBool(theNode);
        }
        else if (strcmp(theNode.name(), "preserveAspect") == 0)
        {
            GameOptions::preserveAspect = GetBool(theNode);
        }
        else
        {
             DEBUG_LOG("Unknown xml node: %s", theNode.name());
        }
    }
}

// =============================================================================
// XMLInterpreter::GetInt
// -----------------------------------------------------------------------------
int GetInt(pugi::xml_node theRoot)
{
    int theResult = 0;
    theResult = theRoot.text().as_int();
    return theResult;
}

// =============================================================================
// XMLInterpreter::GetBool
// -----------------------------------------------------------------------------
bool GetBool(pugi::xml_node theRoot)
{
    int theResult = 0;
    theResult = theRoot.text().as_bool();
    return theResult;
}

// =============================================================================
// XMLInterpreter::GetVector2f
// -----------------------------------------------------------------------------
CVector2f GetVector2f(pugi::xml_node theRoot)
{
    CHECK_CHILD(theRoot, "x");
    CHECK_CHILD(theRoot, "y");
    
    CVector2f theResult;
    theResult.x = theRoot.child("x").text().as_float();
    theResult.y = theRoot.child("y").text().as_float();
    
    return theResult;
}
    
// =============================================================================
// XMLInterpreter::GetTime
// -----------------------------------------------------------------------------
CTime GetTime(pugi::xml_node theRoot)
{
    float seconds = theRoot.text().as_float();
    CTime theResult = CTime::Seconds(seconds);
    
    return theResult;
}
    
} // namespace XMLInterpreter