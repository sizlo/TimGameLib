//
//  Main.cpp
//  TimGameLib
//
//  Created by Tim Brier on 26/09/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CGame.hpp"


// =============================================================================
// Program entry point
// -----------------------------------------------------------------------------
int main(int argc, char **argv)
{
    CGame theGame("Game");
    theGame.Init();
    int returnCode = theGame.Run();
    theGame.Cleanup();
    
    return returnCode;
}
