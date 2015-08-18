//
//  GameOptions.cpp
//  TimGameLib
//
//  Created by Tim Brier on 05/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "GameOptions.hpp"
#include "XMLInterpreter.hpp"

namespace GameOptions
{

// =============================================================================
// Namespace gloabals
// -----------------------------------------------------------------------------
unsigned int    windowHeight        = 720;
unsigned int    windowWidth         = 1280;
float           viewLeft            = 0.0f;
float           viewTop             = 0.0f;
float           viewHeight          = 1080.0f;
float           viewWidth           = 1920.0f;
bool            fullscreen          = false;
bool            preserveAspect      = true;
bool            doVsync             = true;
unsigned int    maxFPS              = 60;
int             antiAliasingLevel   = 8;

// =============================================================================
// GameOptions::ReadConfig
// Read the config from a file
// -----------------------------------------------------------------------------
void ReadConfig()
{
    XMLInterpreter::ReadConfig("config.xml");
}

} // namespace GameOptions