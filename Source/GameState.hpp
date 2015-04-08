//
//  GameState.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef TimeGameLib_GameState_hpp
#define TimeGameLib_GameState_hpp

// =============================================================================
// Game state enum
// -----------------------------------------------------------------------------
enum EGameState
{
    kGameStateFrontEnd  = 1 << 0,
    kGameStateInGame    = 1 << 1,
    kGameStatePaused    = 1 << 2,
    kGameStateUpdating  = 1 << 3
};

#endif
