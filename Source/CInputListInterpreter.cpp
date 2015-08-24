#include "CInputListInterpreter.hpp"
#include "GameOptions.hpp"

CInputListInterpreter::CInputListInterpreter(std::string filename)
: CXMLInterpreter(filename)
{
    
}

CInputListInterpreter::~CInputListInterpreter()
{
    
}

std::list<SInputListEntry> CInputListInterpreter::Parse()
{
    std::list<SInputListEntry> theList;
    
    // Begin processing
    pugi::xml_node theRoot = mDocument.document_element();
    
    // Go through all children of the root and process each in turn
    for (pugi::xml_node theNode = theRoot.first_child();
         theNode;
         theNode = theNode.next_sibling())
    {
        if (strcmp(theNode.name(), "input") == 0)
        {
            theList.push_back(GetEntry(theNode));
        }
        else
        {
            DEBUG_LOG("Unknown xml node: %s", theNode.name());
        }
    }
    
    return theList;
}

void CInputListInterpreter::Write(std::list<SInputListEntry> theList)
{
    mDocument.load("<inputList></inputList>");
    pugi::xml_node theRoot = mDocument.document_element();
    
    for (auto entry: theList)
    {
        pugi::xml_node theChild = theRoot.append_child("input");
        pugi::xml_node theName = theChild.append_child("name");
        pugi::xml_node theType = theChild.append_child("type");
        pugi::xml_node theCode = theChild.append_child("code");
        theName.text().set(entry.name.c_str());
        theType.text().set(entry.input.GetType());
        theCode.text().set(entry.input.GetCode());
    }
    
    mDocument.save_file(mFilename.c_str());
}

SInputListEntry CInputListInterpreter::GetEntry(pugi::xml_node theRoot)
{
    std::string name;
    EInputType type;
    int code;
    
    CHECK_CHILD(theRoot, "name");
    CHECK_CHILD(theRoot, "type");
    CHECK_CHILD(theRoot, "code");
    
    // Go through all children of the root and process each in turn
    for (pugi::xml_node theNode = theRoot.first_child();
         theNode;
         theNode = theNode.next_sibling())
    {
        if (strcmp(theNode.name(), "name") == 0)
        {
            name = theNode.text().as_string();
        }
        else if (strcmp(theNode.name(), "type") == 0)
        {
            type = (EInputType)theNode.text().as_int();
        }
        else if (strcmp(theNode.name(), "code") == 0)
        {
            code = theNode.text().as_int();
        }
        else
        {
            DEBUG_LOG("Unknown xml node: %s", theNode.name());
        }
    }
    
    SInputListEntry entry;
    entry.name = name;
    if (type == kKeyboardInput)
    {
        entry.input = CInput((CKeyboard::Key) code);
    }
    else
    {
        entry.input = CInput((CMouse::Button) code);
    }
    
    return entry;
}