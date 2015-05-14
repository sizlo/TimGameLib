//
//  CToggleWidget.hpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#ifndef __MenuTest__CToggleWidget__
#define __MenuTest__CToggleWidget__

#include "CWidget.hpp"

class CToggleWidget : public CWidget
{
public:
    CToggleWidget(float left,
                  float top,
                  float width,
                  float height,
                  std::string label,
                  bool state);
    ~CToggleWidget();
    
    virtual void Draw(CWindow *theWindow);
    
    virtual bool HandleMessage(CEvent theEvent);
    
private:
    void ToggleState();
    
    bool mState;
    
    CConvexShape mOuterSquare;
    CConvexShape mInnerSquare;
};

#endif /* defined(__MenuTest__CToggleWidget__) */
