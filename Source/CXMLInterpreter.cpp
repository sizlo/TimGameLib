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
#include "CXMLInterpreter.hpp"
#include "SystemUtilities.hpp"

// =============================================================================
// CXMLInterpreter constructor/destructor
// -----------------------------------------------------------------------------
CXMLInterpreter::CXMLInterpreter(std::string filename)
{
    mFilename = SystemUtilities::GetResourcePath() + filename;
}

CXMLInterpreter::~CXMLInterpreter()
{
    
}

// =============================================================================
// CXMLInterpreter::LoadFile
// -----------------------------------------------------------------------------
bool CXMLInterpreter::LoadFile()
{
    pugi::xml_parse_result theResult = mDocument.load_file(mFilename.c_str());
    
    if (theResult.status != pugi::status_ok)
    {
        DEBUG_LOG("Error parsisng config xml file: %s", mFilename.c_str());
        DEBUG_LOG("Status code: %d", theResult.status);
        return false;
    }
    
    return true;
}

// =============================================================================
// CXMLInterpreter::GetInt
// -----------------------------------------------------------------------------
int CXMLInterpreter::GetInt(pugi::xml_node theRoot)
{
    int theResult = 0;
    theResult = theRoot.text().as_int();
    return theResult;
}

// =============================================================================
// CXMLInterpreter::GetFloat
// -----------------------------------------------------------------------------
float CXMLInterpreter::GetFloat(pugi::xml_node theRoot)
{
    float theResult = 0.0f;
    theResult = theRoot.text().as_float();
    return theResult;
}

// =============================================================================
// CXMLInterpreter::GetBool
// -----------------------------------------------------------------------------
bool CXMLInterpreter::GetBool(pugi::xml_node theRoot)
{
    int theResult = 0;
    theResult = theRoot.text().as_bool();
    return theResult;
}

// =============================================================================
// CXMLInterpreter::GetVector2f
// -----------------------------------------------------------------------------
CVector2f CXMLInterpreter::GetVector2f(pugi::xml_node theRoot)
{
    CHECK_CHILD(theRoot, "x");
    CHECK_CHILD(theRoot, "y");
    
    CVector2f theResult;
    theResult.x = theRoot.child("x").text().as_float();
    theResult.y = theRoot.child("y").text().as_float();
    
    return theResult;
}
    
// =============================================================================
// CXMLInterpreter::GetTime
// -----------------------------------------------------------------------------
CTime CXMLInterpreter::GetTime(pugi::xml_node theRoot)
{
    float seconds = theRoot.text().as_float();
    CTime theResult = CTime::Seconds(seconds);
    
    return theResult;
}