//
//  CInputWidget.cpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#include "CInputWidget.hpp"
#include "SystemUtilities.hpp"
#include "TextUtilties.hpp"

CInputWidget::CInputWidget(float left,
                           float top,
                           float width,
                           float height,
                           std::string label,
                           CInput currentInput)
:   CWidget(left, top, width, height, label)
{
    mCurrentInput = currentInput;
    mState = kInputWidgetStateNormal;
}

CInputWidget::~CInputWidget()
{
    
}

void CInputWidget::Update(CTime elapsedTime)
{
    CWidget::Update(elapsedTime);
    
    std::string s = mCurrentInput.AsString();
    if (mState == kInputWidgetStateCapturing)
    {
        s = "Press new input";
    }
    
    mInputText = CText(s, *(TextUtilities::GetFont(kFontTypeDefault)), 30);
    CFloatRect b = mInputText.getGlobalBounds();
    mInputText.setOrigin(b.left + b.width/2 , b.top + b.height/2);
    mInputText.setPosition(mLeft + mWidth/2 + mWidth/4, mTop + mHeight/2);
    mInputText.setColor(CColour::Black);
}

void CInputWidget::Draw(CWindow *theWindow)
{
    CWidget::Draw(theWindow);
    
    theWindow->draw(mInputText);
}

bool CInputWidget::HandleMessage(CEvent theEvent)
{
    bool messageEaten = false;
    
    switch (mState)
    {
        case kInputWidgetStateNormal:
            if (theEvent.type == CEvent::KeyPressed)
            {
                if (theEvent.key.code == CKeyboard::Return
                    || theEvent.key.code == CKeyboard::Space)
                {
                    StartCapturing();
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
                        StartCapturing();
                        messageEaten = true;
                    }
                }
            }
            break;
            
        case kInputWidgetStateCapturing:
            if (theEvent.type == CEvent::KeyPressed)
            {
                TrySetNewInput(CInput(theEvent.key.code));
            }
            else if (theEvent.type == CEvent::MouseButtonPressed)
            {
                TrySetNewInput(CInput(theEvent.mouseButton.button));
            }
            break;
    }
    
    return messageEaten;
}

CInput CInputWidget::GetCurrentInput()
{
    return mCurrentInput;
}

void CInputWidget::SetDisallowedInputs(std::list<CInput> theInputs)
{
    mDisallowedInputs = theInputs;
}

bool CInputWidget::IsBlockingFocusChange()
{
    return mState == kInputWidgetStateCapturing;
}

void CInputWidget::StartCapturing()
{
    mState = kInputWidgetStateCapturing;
}

void CInputWidget::StopCapturing()
{
    mState = kInputWidgetStateNormal;
}

void CInputWidget::TrySetNewInput(CInput theNewInput)
{
    // If we hit escape cancel the capture
    if (theNewInput == CInput(CKeyboard::Escape))
    {
        StopCapturing();
        return;
    }
    
    bool isDisallowed = false;
    for (auto i: mDisallowedInputs)
    {
        if (i == theNewInput && i != mCurrentInput)
        {
            isDisallowed = true;
        }
    }
    
    if (!isDisallowed)
    {
        mCurrentInput = theNewInput;
        StopCapturing();
    }
}