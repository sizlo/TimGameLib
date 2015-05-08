//
//  CButtonWidget.hpp
//  TimGameLib
//
//  Created by Tim Brier on 08/05/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CButtonWidget__
#define __TimeGameLib__CButtonWidget__

#include "CWidget.hpp"

class CButtonWidget : public CWidget
{
public:
    CButtonWidget(float left,
                  float top,
                  float width,
                  float height,
                  std::string label);
    ~CButtonWidget();
};

#endif // __TimeGameLib__CButtonWidget__