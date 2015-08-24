#include "CInput.hpp"

CInput::CInput()
{
    
}

CInput::CInput(CKeyboard::Key theKey)
{
    mType = kKeyboardInput;
    mKey = theKey;
}

CInput::CInput(CMouse::Button theButton)
{
    mType = kMouseInput;
    mButton = theButton;
}

CInput::~CInput()
{
    
}

bool CInput::IsPressed()
{
    bool isPressed = false;
    
    switch (mType)
    {
        case kMouseInput: isPressed =  CMouse::isButtonPressed(mButton); break;
        case kKeyboardInput: isPressed = CKeyboard::isKeyPressed(mKey); break;
    }
    
    return isPressed;
}

bool CInput::WasPressedInEvent(CEvent theEvent)
{
    bool wasPressed = false;
    
    switch (mType)
    {
        case kMouseInput:
            wasPressed = theEvent.type == CEvent::MouseButtonPressed && theEvent.mouseButton.button == mButton;
            break;
            
        case kKeyboardInput:
            wasPressed = theEvent.type == CEvent::KeyPressed && theEvent.key.code == mKey;
            break;
    }
    
    return wasPressed;
}

bool CInput::WasReleasedInEvent(CEvent theEvent)
{
    bool wasReleased = false;
    
    switch (mType)
    {
        case kMouseInput:
            wasReleased = theEvent.type == CEvent::MouseButtonReleased && theEvent.mouseButton.button == mButton;
            break;
            
        case kKeyboardInput:
            wasReleased = theEvent.type == CEvent::KeyReleased && theEvent.key.code == mKey;
            break;
    }
    
    return wasReleased;
}