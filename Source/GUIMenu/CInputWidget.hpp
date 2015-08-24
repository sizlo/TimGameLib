//
//  CInputWidget.hpp
//  MenuTest
//
//  Created by Tim Brier on 14/05/2015.
//
//

#ifndef __MenuTest__CInputWidget__
#define __MenuTest__CInputWidget__

#include "CWidget.hpp"
#include "CInput.hpp"

enum EInputWidgetState
{
    kInputWidgetStateNormal,
    kInputWidgetStateCapturing
};

class CInputWidget : public CWidget
{
public:
    CInputWidget(float left,
                  float top,
                  float width,
                  float height,
                  std::string label,
                  CInput currentInput);
    ~CInputWidget();
    
    virtual void Update(CTime elapsedTime);
    virtual void Draw(CWindow *theWindow);
    
    virtual bool HandleMessage(CEvent theEvent);
    bool IsBlockingFocusChange();
    
    CInput GetCurrentInput();
    void SetDisallowedInputs(std::list<CInput> theInputs);
    
private:
    void StartCapturing();
    void StopCapturing();
    void TrySetNewInput(CInput theInput);
    
    CInput mCurrentInput;
    EInputWidgetState mState;
    CText mInputText;
    std::list<CInput> mDisallowedInputs;
};

#endif /* defined(__MenuTest__CInputWidget__) */
