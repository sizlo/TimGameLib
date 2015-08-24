#ifndef __TimGameLib__CInput__
#define __TimGameLib__CInput__

#include "SFMLIntegration/SFMLIntegration.hpp"

enum EInputType
{
    kKeyboardInput,
    kMouseInput
};

class CInput
{
public:
    CInput();
    CInput(CKeyboard::Key theKey);
    CInput(CMouse::Button theButton);
    ~CInput();
    
    bool IsPressed();
    bool WasPressedInEvent(CEvent theEvent);
    bool WasReleasedInEvent(CEvent theEvent);
    
    std::string AsString();
    
private:
    EInputType mType;
    CKeyboard::Key mKey;
    CMouse::Button mButton;
};

#endif // __TimGameLib__CInput__
