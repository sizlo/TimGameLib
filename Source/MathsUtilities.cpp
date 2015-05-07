//
//  MathsUtilities.cpp
//  TimGameLib
//
//  Created by Tim Brier on 10/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "MathsUtilities.hpp"
#include <random>
#include <functional>

namespace MathsUtilities
{
    
std::function<unsigned int()> GetRandomGeneratorFunctionForRange(int min,
                                                                 int max)
{
    std::random_device device;
    std::default_random_engine generator(device());
    std::uniform_int_distribution<int> distribution(min, max);
    auto result = std::bind(distribution, generator);
    return result;
}
    
} // namespace MathsUtilities