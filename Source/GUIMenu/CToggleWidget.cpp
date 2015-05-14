//
//  CToggleWidget.cpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#include "CToggleWidget.hpp"
#include "SystemUtilities.hpp"

CToggleWidget::CToggleWidget(float left,
                             float top,
                             float width,
                             float height,
                             std::string label,
                             bool state)
:   CWidget(left, top, width, height, label)
{
    mState = state;
    
    float outerGap = 5.0f;
    float outerSize = mHeight - (2 * outerGap);
    float outerLeft = (mLeft + mWidth) - (outerGap + outerSize);
    float outerTop = mTop + outerGap;
    mOuterSquare = CRectangleShape(outerSize, outerSize);
    mOuterSquare.setPosition(outerLeft, outerTop);
    mOuterSquare.setOutlineColor(CColour::Black);
    mOuterSquare.setOutlineThickness(1.0f);
    mOuterSquare.setFillColor(CColour(0, 0, 0, 0));
    
    float innerGap = 5.0f;
    float innerSize = outerSize - (2 * innerGap);
    float innerLeft = outerLeft + innerGap;
    float innerTop = outerTop + innerGap;
    mInnerSquare = CRectangleShape(innerSize, innerSize);
    mInnerSquare.setPosition(innerLeft, innerTop);
    mInnerSquare.setFillColor(CColour::Black);
}

CToggleWidget::~CToggleWidget()
{
    
}

void CToggleWidget::Draw(CWindow *theWindow)
{
    CWidget::Draw(theWindow);
    
    theWindow->DrawShape(mOuterSquare);

    if (mState)
    {
        theWindow->DrawShape(mInnerSquare);
    }
}

bool CToggleWidget::HandleMessage(CEvent theEvent)
{
    bool messageEaten = false;
    
    if (theEvent.type == CEvent::KeyPressed)
    {
        if (theEvent.key.code == CKeyboard::Return
            || theEvent.key.code == CKeyboard::Space)
        {
            ToggleState();
            messageEaten = true;
        }
    }
    else if (theEvent.type == CEvent::MouseButtonPressed
             && theEvent.mouseButton.button == CMouse::Left)
    {
        // Make sure the mouse is inside the toggle shape
        CVector2i windowPos;
        windowPos.x = theEvent.mouseButton.x;
        windowPos.y = theEvent.mouseButton.y;
        CVector2f viewPos = SystemUtilities::GetViewPosition(windowPos);
        
        if (mOuterSquare.getGlobalBounds().contains(viewPos))
        {
            ToggleState();
            messageEaten = true;
        }
    }
    
    return messageEaten;
}

bool CToggleWidget::GetValue()
{
    return mState;
}

void CToggleWidget::ToggleState()
{
    mState = !mState;
}