//
//  CWidget.cpp
//  TimGameLib
//
//  Created by Tim Brier on 08/05/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CWidget.hpp"
#include "../TextUtilties.hpp"

CWidget::CWidget(float left,
                 float top,
                 float width,
                 float height,
                 std::string label)
:   mLeft(left),
    mTop(top),
    mWidth(width),
    mHeight(height),
    mLabelString(label)
{
    mOutlineShape = CRectangleShape(mWidth, mHeight);
    mOutlineShape.setPosition(mLeft, mTop);
    mOutlineShape.setOutlineThickness(1.0f);
    mOutlineShape.setOutlineColor(CColour::Black);
    mOutlineShape.setFillColor(CColour(0, 0, 0, 0));
    
    mLabel = CText(mLabelString, *(TextUtilities::GetFont(kFontTypeDefault)), 30);
    CFloatRect labelBounds = mLabel.getGlobalBounds();
    mLabel.setOrigin(0.0f, labelBounds.top + (labelBounds.height / 2.0f));
    float xPos = mLeft + 10.0f;
    float yPos = mTop + (mHeight / 2.0f);
    mLabel.setPosition(xPos, yPos);
    mLabel.setColor(CColour::Black);
    
    mActive = true;
}


CWidget::~CWidget()
{
    
}

void CWidget::Update(CTime elapsedTime)
{
    
}

void CWidget::Draw(CWindow *theWindow)
{
    theWindow->draw(mLabel);
}

void CWidget::DrawHighlight(CWindow *theWindow)
{
    theWindow->DrawShape(mOutlineShape);
}

bool CWidget::HandleMessage(CEvent theEvent)
{
    bool theResult = false;
    
    return theResult;
}

bool CWidget::IsBlockingFocusChange()
{
    return false;
}

CFloatRect CWidget::GetBounds()
{
    return CFloatRect(mLeft, mTop, mWidth, mHeight);
}

void CWidget::SetActive(bool active)
{
    mActive = active;
}

bool CWidget::IsActive()
{
    return mActive;
}