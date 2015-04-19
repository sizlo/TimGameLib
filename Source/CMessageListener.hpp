//
//  CMessageListener.hpp
//  TimGameLib
//
//  Created by Tim Brier on 19/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef TimGameLib_CMessageListener_hpp
#define TimGameLib_CMessageListener_hpp

template <typename T>
class CMessageListener
{
public:
    virtual bool HandleMessage(T m) = 0;
};

#endif
