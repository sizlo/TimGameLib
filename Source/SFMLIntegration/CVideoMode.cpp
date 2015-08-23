#include "CVideoMode.hpp"

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
    std::string s = std::to_string(width) + "*" + std::to_string(height);
    if ((float)width / height == 16.0f / 9.0f) s += " 16:9";
    if ((float)width / height == 16.0f / 10.0f) s += " 16:10";
    if ((float)width / height == 4.0f / 3.0f) s += " 4:3";
    return s;
}

std::set<CVideoMode> CVideoMode::GetModes()
{
    std::set<CVideoMode> modes;
    
    // Add all fullscreen modes
    auto fsModes = getFullscreenModes();
    for (auto m: fsModes)
    {
        modes.insert(CVideoMode(m.width, m.height, m.bitsPerPixel));
    }
    
    CVideoMode max = CVideoMode(CVideoMode::getDesktopMode().width, CVideoMode::getDesktopMode().height);
    
    // Now add some 16:9 resolutions less than the max res
    CVideoMode r;
    r = CVideoMode(640, 360); if (r <= max) modes.insert(r);
    r = CVideoMode(800, 450); if (r <= max) modes.insert(r);
    r = CVideoMode(1280, 720); if (r <= max) modes.insert(r);
    r = CVideoMode(1600, 900); if (r <= max) modes.insert(r);
    r = CVideoMode(1920, 1080); if (r <= max) modes.insert(r);
    
    // Now add some 16:10 resolutions
    r = CVideoMode(640, 400); if (r <= max) modes.insert(r);
    r = CVideoMode(800, 500); if (r <= max) modes.insert(r);
    r = CVideoMode(1280, 800); if (r <= max) modes.insert(r);
    r = CVideoMode(1440, 900); if (r <= max) modes.insert(r);
    r = CVideoMode(1680, 1050); if (r <= max) modes.insert(r);
    r = CVideoMode(1920, 1200); if (r <= max) modes.insert(r);
    
    // Now add some 4:3 resolutions
    r = CVideoMode(640, 480); if (r <= max) modes.insert(r);
    r = CVideoMode(800, 600); if (r <= max) modes.insert(r);
    r = CVideoMode(1024, 768); if (r <= max) modes.insert(r);
    r = CVideoMode(1280, 960); if (r <= max) modes.insert(r);
    r = CVideoMode(1600, 1200); if (r <= max) modes.insert(r);
    
    return modes;    
}