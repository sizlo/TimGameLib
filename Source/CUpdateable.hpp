//
//  CUpdateable.hpp
//  TimGameLib
//
//  Created by Tim Brier on 02/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef TimeGameLib_CUpdateable_hpp
#define TimeGameLib_CUpdateable_hpp

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "SFMLIntegration/SFMLIntegration.hpp"
#include "GameState.hpp"

// =============================================================================
// Abstract class definition
// -----------------------------------------------------------------------------
class CUpdateable
{
public:
    virtual void Update(CTime elapsedTime) = 0;
    virtual bool ShouldUpdateForState(EGameState theState){return true;};
};

#endif
