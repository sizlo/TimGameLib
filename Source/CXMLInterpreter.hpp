//
//  CXMLInterpreter.hpp
//  TimGameLib
//
//  Created by Tim Brier on 11/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CXMLInterpreter__
#define __TimeGameLib__CXMLInterpreter__

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "Libraries/pugixml/pugixml.hpp"
#include "SFMLIntegration/SFMLIntegration.hpp"

// =============================================================================
// Macros
// -----------------------------------------------------------------------------
#define CHECK_ATTRIBUTE(node, attr)                 \
    if (node.attribute(attr) == NULL)               \
    {                                               \
        DEBUG_LOG("Missing attribute: %s", attr);   \
    }

#define CHECK_CHILD(root, childName)                \
    if (root.child(childName) == NULL)              \
    {                                               \
        DEBUG_LOG("Missing child: %s", childName);  \
    }

// =============================================================================
// namespace definition
// -----------------------------------------------------------------------------
class CXMLInterpreter
{
public:
    CXMLInterpreter(std::string filename);
    ~CXMLInterpreter();
    
    bool LoadFile();
    
protected:
    // Get a given data type from an xml node
    int             GetInt          (pugi::xml_node theRoot);
    bool            GetBool         (pugi::xml_node theRoot);
    CVector2f       GetVector2f     (pugi::xml_node theRoot);
    CTime           GetTime         (pugi::xml_node theRoot);
    
    std::string mFilename;
    pugi::xml_document mDocument;
};

#endif /* defined(__TimeGameLib__CXMLInterpreter__) */
