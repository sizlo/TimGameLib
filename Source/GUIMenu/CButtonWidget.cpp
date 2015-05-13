//
//  CButtonWidget.cpp
//  TimGameLib
//
//  Created by Tim Brier on 08/05/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CButtonWidget.hpp"
#include "SystemUtilities.hpp"

CButtonWidget::CButtonWidget(float left,
                             float top,
                             float width,
                             float height,
                             std::string label,
                             std::function<void()> callback)
:   CWidget(left, top, width, height, label)
{
    CVector2f pos = mLabel.getPosition();
    float y = pos.y;
    float x = left + width / 2.0f;
    CFloatRect bounds = mLabel.getLocalBounds();
    mLabel.setOrigin(bounds.left + (bounds.width / 2.0f),
                     bounds.top + (bounds.height / 2.0f));
    mLabel.setPosition(x, y);
    
    mCallback = callback;
}

CButtonWidget::~CButtonWidget()
{
    
}

bool CButtonWidget::HandleMessage(CEvent theEvent)
{
    bool messageEaten = false;
    
    if (theEvent.type == CEvent::KeyPressed)
    {
        if (theEvent.key.code == CKeyboard::Return
            || theEvent.key.code == CKeyboard::Space)
        {
            PressButton();
            messageEaten = true;
        }
    }
    else if (theEvent.type == CEvent::MouseButtonPressed)
    {
        if (theEvent.mouseButton.button == CMouse::Left)
        {
            // Make sure the cursor is inside the button
            CVector2i windowPos;
            windowPos.x = theEvent.mouseButton.x;
            windowPos.y = theEvent.mouseButton.y;
            CVector2f viewPos = SystemUtilities::GetViewPosition(windowPos);
            if (CFloatRect(mLeft, mTop, mWidth, mHeight).contains(viewPos))
            {
                PressButton();
                messageEaten = true;
            }
        }
    }
    
    return messageEaten;
}

void CButtonWidget::PressButton()
{
    mCallback();
}