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
    mOuterSquare = CConvexShape(4);
    mOuterSquare.setPoint(0, CVector2f(outerLeft, outerTop));
    mOuterSquare.setPoint(1, CVector2f(outerLeft + outerSize, outerTop));
    mOuterSquare.setPoint(2, CVector2f(outerLeft + outerSize, outerTop + outerSize));
    mOuterSquare.setPoint(3, CVector2f(outerLeft, outerTop + outerSize));
    mOuterSquare.setOutlineColor(CColour::Black);
    mOuterSquare.setOutlineThickness(1.0f);
    mOuterSquare.setFillColor(CColour(0, 0, 0, 0));
    
    float innerGap = 5.0f;
    float innerSize = outerSize - (2 * innerGap);
    float innerLeft = outerLeft + innerGap;
    float innerTop = outerTop + innerGap;
    mInnerSquare = CConvexShape(4);
    mInnerSquare.setPoint(0, CVector2f(innerLeft, innerTop));
    mInnerSquare.setPoint(1, CVector2f(innerLeft + innerSize, innerTop));
    mInnerSquare.setPoint(2, CVector2f(innerLeft + innerSize, innerTop + innerSize));
    mInnerSquare.setPoint(3, CVector2f(innerLeft, innerTop + innerSize));
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

void CToggleWidget::ToggleState()
{
    mState = !mState;
}