#include "CVideoMode.hpp"
#include <math.h>

std::string aspectToString(float aspect)
{
	if (aspect == 16.0f / 9.0f) return "16:9";
	if (aspect == 16.0f / 10.0f) return "16:10";
	if (aspect == 4.0f / 3.0f) return "4:3";
	if (aspect == 21.0f / 9.0f) return "21:9";

	bool found = false;
	int numerator;
	int denominator = 1;
	while (!found)
	{
		float result = aspect * (float)denominator;
		if (ceilf(result) == result) // If result is an int
		{
			numerator = (int)result;
			found = true;
		}
		else
		{
			denominator++;
		}
	}
	return std::to_string(numerator) + ":" + std::to_string(denominator);
}

CVideoMode::CVideoMode() : sf::VideoMode()
{
    
}

CVideoMode::CVideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeBitsPerPixel /* = 32 */)
: sf::VideoMode(modeWidth, modeHeight, modeBitsPerPixel)
{
    
}

CVideoMode::~CVideoMode()
{
    
}

std::string CVideoMode::AsString()
{
    std::string s = std::to_string(width) + "*" + std::to_string(height) + " ";
	s += aspectToString(GetAspectRatio());
    return s;
}

float CVideoMode::GetAspectRatio()
{
	return (float)width / (float)height;
}

std::set<CVideoMode> CVideoMode::GetModes()
{
    std::set<CVideoMode> modes;
    
    // Add all fullscreen modes
    auto fsModes = getFullscreenModes();
    for (auto m: fsModes)
    {
        modes.insert(CVideoMode(m.width, m.height));
    }
    
    CVideoMode max = CVideoMode(CVideoMode::getDesktopMode().width, CVideoMode::getDesktopMode().height);
    
    // Now add some 16:9 resolutions less than the max res
    CVideoMode r;
    r = CVideoMode(640, 360); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(800, 450); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1280, 720); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1600, 900); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1920, 1080); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    
    // Now add some 16:10 resolutions
    r = CVideoMode(640, 400); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(800, 500); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1280, 800); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1440, 900); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1680, 1050); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1920, 1200); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    
    // Now add some 4:3 resolutions
    r = CVideoMode(640, 480); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(800, 600); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1024, 768); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1280, 960); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    r = CVideoMode(1600, 1200); if (r.width <= max.width && r.height <= max.height) modes.insert(r);
    
    return modes;    
}

std::set<CVideoMode> CVideoMode::GetModesWithAspectRatio(float aspect)
{
	std::set<CVideoMode> aspectModes;
	auto modes = GetModes();
	for (auto m : modes)
	{
		if (m.GetAspectRatio() == aspect)
		{
			aspectModes.insert(m);
		}
	}
	return aspectModes;
}