//
//  CClock.hpp
//  TimGameLib
//
//  Created by Tim Brier on 18/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CClock__
#define __TimeGameLib__CClock__

// =============================================================================
// Include files
// -----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "CTime.hpp"

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CClock : public sf::Clock
{
public:
    CClock();
    ~CClock();
};

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CPauseableClock : public CClock
{
public:
    CPauseableClock();
    ~CPauseableClock();
    
    CTime Restart(CTime theStartTime = CTime::Zero);
    CTime Pause();
    CTime Resume();
    
    CTime GetElapsedTime();
    
private:
    CTime mAccumulatedTime;
    bool mPaused;
};

#endif /* defined(__TimeGameLib__CClock__) */
