//
//  MathsUtilities.hpp
//  TimGameLib
//
//  Created by Tim Brier on 10/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimGameLib__MathsUtilities__
#define __TimGameLib__MathsUtilities__

#include <functional>

namespace MathsUtilities
{
    std::function<int()> GetRandomGeneratorFunctionForRange(int min, int max);
    std::function<float()> GetRandomGeneratorFunctionForRange(float min, float max);
}

#endif /* defined(__TimGameLib__MathsUtilities__) */
