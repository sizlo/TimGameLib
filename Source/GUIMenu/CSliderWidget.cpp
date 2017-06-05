//
//  CSliderWidget.cpp
//  MenuTest
//
//  Created by Tim Brier on 02/06/2017.
//
//

#include "CSliderWidget.hpp"
#include "TextUtilties.hpp"
#include "SystemUtilities.hpp"

CSliderWidget::CSliderWidget(float left,
							 float top,
							 float width,
							 float height,
							 std::string label,
							 int min,
							 int max,
							 int step,
							 int current)
:	CWidget(left, top, width, height, label)
{
	mMin = min;
	mMax = max;
	mStep = step;
	mCurrent = current;
	
	mState = kSliderWidgetStateNormal;
	
	CVector2f mid(left + width/2, top + height/2);
	
	float hMargin = 5.0f;
	float vMargin = (height/2)-5.0f;
	
	float textWidth = 80.0f;
	
	float lineWidth = width/2 - (3*hMargin + textWidth);
	float lineHeight = height - 2*vMargin;
	
	mLine = CRectangleShape(lineWidth, lineHeight);
	mLine.setPosition(mid.x + hMargin, top + vMargin);
	mLine.setFillColor(CColour::Black);
	
	mOptionText = CText(std::to_string(mCurrent), *(TextUtilities::GetFont(kFontTypeDefault)), 30);
	mOptionText.setColor(CColour::Black);
	CFloatRect b = mOptionText.getGlobalBounds();
	mOptionText.setOrigin(b.left + b.width/2 , b.top + b.height/2);
	float textLeft = mid.x + hMargin + lineWidth + hMargin;
	float textRight = left + width - hMargin;
	float textX = textLeft + (textRight - textLeft)/2;
	mOptionText.setPosition(textX, top + height/2);
	
	vMargin = hMargin;
	float barHeight = height - 2*vMargin;
	mBar = CRectangleShape(barHeight / 2 , barHeight);
	mBar.setFillColor(CColour::Black);
	mBar.setPosition(mid.x + hMargin, top + vMargin);
	PositionBar();
}

CSliderWidget::~CSliderWidget()
{
	
}

void CSliderWidget::Draw(CWindow *theWindow)
{
	CWidget::Draw(theWindow);
	
	theWindow->DrawShape(mLine);
	theWindow->DrawShape(mBar);
	theWindow->draw(mOptionText);
}

bool CSliderWidget::HandleMessage(CEvent theEvent)
{
	bool messageEaten = false;
	
	switch(mState)
	{
		case kSliderWidgetStateNormal:
			if (theEvent.type == CEvent::KeyPressed)
			{
				if (theEvent.key.code == CKeyboard::Left
					|| theEvent.key.code == CKeyboard::A)
				{
					SetCurrent(mCurrent - mStep);
					messageEaten = true;
				}
				else if (theEvent.key.code == CKeyboard::Right
						 || theEvent.key.code == CKeyboard::D)
				{
					SetCurrent(mCurrent + mStep);
					messageEaten = true;
				}
			}
			else if (theEvent.type == CEvent::MouseButtonPressed)
			{
				if (theEvent.mouseButton.button == CMouse::Left)
				{
					// Make sure the cursor is inside the bar
					CVector2i windowPos;
					windowPos.x = theEvent.mouseButton.x;
					windowPos.y = theEvent.mouseButton.y;
					CVector2f viewPos = SystemUtilities::GetViewPosition(windowPos);
					if (mBar.getGlobalBounds().contains(viewPos))
					{
						mState = kSliderWidgetStateSliding;
						messageEaten = true;
					}
				}
			}
			break;
			
		case kSliderWidgetStateSliding:
			if (theEvent.type == CEvent::MouseButtonReleased)
			{
				if (theEvent.mouseButton.button == CMouse::Left)
				{
					mState = kSliderWidgetStateNormal;
					messageEaten = true;
				}
			}
			else if (theEvent.type == CEvent::MouseMoved)
			{
				CVector2i windowPos = CVector2i(theEvent.mouseMove.x, theEvent.mouseMove.y);
				float viewX = SystemUtilities::GetViewPosition(windowPos).x;
				SetCurrentForMouseX(viewX);
				messageEaten = true;
			}
			break;
	}
	
	return messageEaten;
}

bool CSliderWidget::IsBlockingFocusChange()
{
	return mState == kSliderWidgetStateSliding;
}

int CSliderWidget::GetValue()
{
	return mCurrent;
}

void CSliderWidget::SetCurrent(int c)
{
	int oldCurrent = mCurrent;
	mCurrent = c;
	Clamp();
	
	if (oldCurrent != mCurrent)
	{
		PositionBar();
		mOptionText.setString(std::to_string(mCurrent));
	}
}

void CSliderWidget::SetCurrentForMouseX(float x)
{
	CFloatRect lineBounds = mLine.getGlobalBounds();
	CFloatRect barBounds = mBar.getGlobalBounds();
	float start = lineBounds.left;
	float end = start + lineBounds.width - barBounds.width;
	
	float fromStart = x - start;
	float percent = fromStart / (end - start);
	
	int range = mMax - mMin;
	int newCurrent = mMin + percent * range;
	SetCurrent(newCurrent);
}

void CSliderWidget::PositionBar()
{
	CFloatRect lineBounds = mLine.getGlobalBounds();
	CFloatRect barBounds = mBar.getGlobalBounds();
	float start = lineBounds.left;
	float end = start + lineBounds.width - barBounds.width;
	
	int range = mMax - mMin;
	float percent = (float)(mCurrent - mMin) / (float)range;
	
	float position = start + percent*(end - start);
	mBar.setPosition(position, barBounds.top);
}

void CSliderWidget::Clamp()
{
	mCurrent = std::min(mMax, mCurrent);
	mCurrent = std::max(mMin, mCurrent);
	
	if (mCurrent != mMin && mCurrent != mMax)
	{
		for (int prev = mMin; prev <= mMax; prev += mStep)
		{
			int next = prev + mStep;
			if (prev < mCurrent && next > mCurrent)
			{
				int prevDiff = mCurrent - prev;
				int nextDiff = mCurrent - next;
				if (prevDiff < nextDiff)
				{
					mCurrent = prev;
				}
				else
				{
					mCurrent = next;
				}
			}
		}
	}
}
