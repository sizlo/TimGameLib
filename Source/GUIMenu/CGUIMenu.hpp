//
//  CGUIMenu.hpp
//  TimGameLib
//
//  Created by Tim Brier on 08/05/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CGUIMenu__
#define __TimeGameLib__CGUIMenu__

#include "CMenu.hpp"
#include "CWidget.hpp"

class CGUIMenu : public CMenu
{
public:
    CGUIMenu();
    virtual ~CGUIMenu();
    
    virtual void Update(CTime elapsedTime);
    virtual void Draw(CWindow *theWindow);
    
    virtual void Enter();
    virtual void Exit();
    
    virtual bool HandleMessage(CEvent theEvent);
    
    void AddWidget(CWidget theWidget);
    
private:
    std::list<CWidget>              mWidgets;
    std::list<CWidget>::iterator    mCurrentSelection;
};

#endif // __TimeGameLib__CGUIMenu__