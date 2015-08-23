#ifndef __TimGameLib__CConfigInterpreter__
#define __TimGameLib__CConfigInterpreter__

#include "CXMLInterpreter.hpp"

class CConfigInterpreter : public CXMLInterpreter
{
public:
    CConfigInterpreter(std::string filename);
    ~CConfigInterpreter();
    
    void Parse();
    void Write();
};

#endif // __TimGameLib__CConfigInterpreter__
