//
//  GameOptions.hpp
//  TimGameLib
//
//  Created by Tim Brier on 05/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__GameOptions__
#define __TimeGameLib__GameOptions__

// =============================================================================
// namespace definition
// -----------------------------------------------------------------------------
namespace GameOptions
{
    // Public globals
    extern unsigned int windowHeight;
    extern unsigned int windowWidth;
    extern float        viewLeft;
    extern float        viewTop;
    extern float        viewHeight;
    extern float        viewWidth;
    extern bool         fullscreen;
    extern bool         preserveAspect;
    extern bool         doVsync;
    extern unsigned int maxFPS;
    extern int          antiAliasingLevel;

    extern void ReadConfig();
    extern void WriteConfig();
};

#endif /* defined(__TimeGameLib__GameOptions__) */
