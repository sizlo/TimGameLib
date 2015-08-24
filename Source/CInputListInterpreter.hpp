#ifndef __TimGameLib__CInputListInterpreter__
#define __TimGameLib__CInputListInterpreter__

#include "CXMLInterpreter.hpp"
#include "CInput.hpp"

struct SInputListEntry
{
    CInput input;
    std::string name;
};

class CInputListInterpreter : public CXMLInterpreter
{
public:
    CInputListInterpreter(std::string filename);
    ~CInputListInterpreter();
    
    std::list<SInputListEntry> Parse();
    void Write(std::list<SInputListEntry> theList);
    
private:
    SInputListEntry GetEntry(pugi::xml_node theRoot);
};

#endif // __TimGameLib__CInputListInterpreter__
