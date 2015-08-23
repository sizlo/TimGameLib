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
	float GetAspectRatio();
    
	static std::set<CVideoMode> GetModes();
	static std::set<CVideoMode> GetModesWithAspectRatio(float aspect);
};

#endif // __TimGameLib__CVideoMode__
