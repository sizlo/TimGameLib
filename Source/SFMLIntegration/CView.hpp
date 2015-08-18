//
//  CView.hpp
//  TimGameLib
//
//  Created by Tim Brier on 29/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CView__
#define __TimeGameLib__CView__

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CFloatRect.hpp"

// =============================================================================
// Class Definition
// -----------------------------------------------------------------------------
class CView : public sf::View
{
public:
    CView();
    CView(CFloatRect theRect);
    CView(const sf::View &theView);
    ~CView();
};

#endif /* defined(__TimeGameLib__CView__) */
