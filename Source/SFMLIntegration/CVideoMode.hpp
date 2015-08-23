#ifndef __TimGameLib__CVideoMode__
#define __TimGameLib__CVideoMode__

#include <SFML/Graphics.hpp>
#include <set>

class CVideoMode : public sf::VideoMode
{
public:
    CVideoMode();
    CVideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeBitsPerPixel = 32);
    ~CVideoMode();
    
    std::string AsString();
    
    static std::set<CVideoMode> GetModes();
};

#endif // __TimGameLib__CVideoMode__
