#include "CConfigInterpreter.hpp"
#include "GameOptions.hpp"

CConfigInterpreter::CConfigInterpreter(std::string filename)
: CXMLInterpreter(filename)
{
    
}

CConfigInterpreter::~CConfigInterpreter()
{
    
}

void CConfigInterpreter::Parse()
{
    // Begin processing
    pugi::xml_node theRoot = mDocument.document_element();

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