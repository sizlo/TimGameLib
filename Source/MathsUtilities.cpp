//
//  MathsUtilities.cpp
//  TimGameLib
//
//  Created by Tim Brier on 10/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "MathsUtilities.hpp"
#include <stdlib.h>
#include <time.h>

namespace MathsUtilities
{
    
int RandomInRange(int min, int max)
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(NULL));
    }
    
    int range = (max - min) + 1;
    int num = rand();
    num %= range;
    num += min;
    
    return num;
}
    
} // namespace MathsUtilities