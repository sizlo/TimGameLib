//
//  CPickerWidget.cpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#include "CPickerWidget.hpp"
#include "SystemUtilities.hpp"
#include "TextUtilties.hpp"

CPickerWidget::CPickerWidget(float left,
                             float top,
                             float width,
                             float height,
                             std::string label,
                             int currentIndex)
:   CWidget(left, top, width, height, label)
{
    mCurrentIndex = currentIndex;
    
    CVector2f mid(left + width/2, top + height/2);
    float margin = 5.0f;
    float buttonSize = height - 2*margin;
    
    mLeftButton = CConvexShape(3);
    mLeftButton.setPoint(0, CVector2f(0, buttonSize/2));
    mLeftButton.setPoint(1, CVector2f(buttonSize, 0));
    mLeftButton.setPoint(2, CVector2f(buttonSize, buttonSize));
    mLeftButton.setPosition(mid.x + margin, top + margin);
    mLeftButton.setFillColor(CColour::Black);
    mRightButton = CConvexShape(3);
    mRightButton.setPoint(0, CVector2f(0, 0));
    mRightButton.setPoint(1, CVector2f(buttonSize, buttonSize/2));
    mRightButton.setPoint(2, CVector2f(0, buttonSize));
    mRightButton.setPosition((left + width) - (buttonSize + margin), top + margin);
    mRightButton.setFillColor(CColour::Black);
}

CPickerWidget::~CPickerWidget()
{
    
}

void CPickerWidget::Update(CTime elapsedTime)
{
    CWidget::Update(elapsedTime);
    
    mOptionText = CText(mOptions.at(mCurrentIndex), *(TextUtilities::GetFont(kFontTypeDefault)), 30);
    CFloatRect b = mOptionText.getGlobalBounds();
    mOptionText.setOrigin(b.left + b.width/2 , b.top + b.height/2);
    mOptionText.setPosition(mLeft + mWidth/2 + mWidth/4, mTop + mHeight/2);
    mOptionText.setColor(CColour::Black);
}

void CPickerWidget::Draw(CWindow *theWindow)
{
    CWidget::Draw(theWindow);
    
    theWindow->DrawShape(mLeftButton);
    theWindow->DrawShape(mRightButton);
    theWindow->draw(mOptionText);
}

bool CPickerWidget::HandleMessage(CEvent theEvent)
{
    bool messageEaten = false;
    
    if (theEvent.type == CEvent::KeyPressed)
    {
        if (theEvent.key.code == CKeyboard::Left
            || theEvent.key.code == CKeyboard::A)
        {
            GoBackSelection();
            messageEaten = true;
        }
        else if (theEvent.key.code == CKeyboard::Right
                 || theEvent.key.code == CKeyboard::D)
        {
            GoForwardSelection();
            messageEaten = true;
        }
    }
    else if (theEvent.type == CEvent::MouseButtonPressed
             && theEvent.mouseButton.button == CMouse::Left)
    {
        // If the mouse is in either button then change selection
        CVector2i windowPos;
        windowPos.x = theEvent.mouseButton.x;
        windowPos.y = theEvent.mouseButton.y;
        CVector2f viewPos = SystemUtilities::GetViewPosition(windowPos);
        
        if (mLeftButton.getGlobalBounds().contains(viewPos))
        {
            GoBackSelection();
            messageEaten = true;
        }
        else if (mRightButton.getGlobalBounds().contains(viewPos))
        {
            GoForwardSelection();
            messageEaten = true;
        }
    }
    
    return messageEaten;
}

void CPickerWidget::SetCurrentIndex(int index)
{
    mCurrentIndex = index;
}

int CPickerWidget::GetCurrentIndex()
{
    return mCurrentIndex;
}

void CPickerWidget::AddOption(std::string theOption)
{
    mOptions.push_back(theOption);
}

void CPickerWidget::GoBackSelection()
{
    mCurrentIndex--;
    mCurrentIndex = std::max(mCurrentIndex, 0);
}

void CPickerWidget::GoForwardSelection()
{
    mCurrentIndex++;
    mCurrentIndex = std::min(mCurrentIndex, (int)mOptions.size()-1);
}