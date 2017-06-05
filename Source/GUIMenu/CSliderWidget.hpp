//
//  CSliderWidget.hpp
//  MenuTest
//
//  Created by Tim Brier on 02/06/2017.
//
//

#ifndef __MenuTest__CSliderWidget__
#define __MenuTest__CSliderWidget__

#include "CWidget.hpp"

enum ESliderWidgetState
{
	kSliderWidgetStateNormal,
	kSliderWidgetStateSliding
};

class CSliderWidget : public CWidget
{
public:
	CSliderWidget(float left,
				  float top,
				  float width,
				  float height,
				  std::string label,
				  int min,
				  int max,
				  int step,
				  int current);
	~CSliderWidget();
	
	virtual void Draw(CWindow *theWindow);
	
	virtual bool HandleMessage(CEvent theEvent);
	bool IsBlockingFocusChange();
	
	int GetValue();
	
private:
	void SetCurrent(int c);
	void SetCurrentForMouseX(float x);
	void PositionBar();
	void Clamp();
	
	int mMin;
	int mMax;
	int mStep;
	int mCurrent;
	
	CConvexShape mLine;
	CConvexShape mBar;
	CText mOptionText;
	ESliderWidgetState mState;
};

#endif /* defined(__MenuTest__CSliderWidget__) */
