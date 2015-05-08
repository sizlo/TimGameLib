//
//  CWidget.hpp
//  TimGameLib
//
//  Created by Tim Brier on 08/05/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CWidget__
#define __TimeGameLib__CWidget__

#include "CUpdateable.hpp"
#include "CRenderable.hpp"
#include "CMessageListener.hpp"

class CWidget : public CUpdateable,
                public CRenderable,
                public CMessageListener<CEvent>
{
public:
    CWidget(float left,
            float top,
            float width,
            float height,
            std::string label);
    virtual ~CWidget();
    
    virtual void Update(CTime elapsedTime);
    virtual void Draw(CWindow *theWindow);
    virtual void DrawHighlight(CWindow *theWindow);
    
    virtual bool HandleMessage(CEvent theEvent);
    
    virtual bool IsBlockingFocusChange();
    
protected:
    float mLeft;
    float mTop;
    float mWidth;
    float mHeight;
    
    CText mLabel;
    
private:
    std::string mLabelString;
    CConvexShape mOutlineShape;
};

#endif // __TimeGameLib__CWidget__