//
//  CPickerWidget.hpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#ifndef __MenuTest__CPickerWidget__
#define __MenuTest__CPickerWidget__

#include "CWidget.hpp"

class CPickerWidget : public CWidget
{
public:
    CPickerWidget(float left,
                  float top,
                  float width,
                  float height,
                  std::string label,
                  int currentIndex);
    ~CPickerWidget();
    
    virtual void Update(CTime elapsedTime);
    virtual void Draw(CWindow *theWindow);
    
    virtual bool HandleMessage(CEvent theEvent);
    
    void SetCurrentIndex(int index);
    int GetCurrentIndex();
    void AddOption(std::string theOption);
    
private:
    void GoBackSelection();
    void GoForwardSelection();
    
    int mCurrentIndex;
    std::vector<std::string> mOptions;
    
    CConvexShape mLeftButton;
    CConvexShape mRightButton;
    CText mOptionText;
};

#endif /* defined(__MenuTest__CPickerWidget__) */
