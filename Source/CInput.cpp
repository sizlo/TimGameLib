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

std::string CInput::GetAsString()
{
    std::string theString;
    
    switch (mType)
    {
        case kMouseInput:
            switch (mButton)
            {
                case CMouse::Left: theString = "Left Mouse Button"; break;
                case CMouse::Right: theString = "Right Mouse Button"; break;
                case CMouse::Middle: theString = "Middle Mouse Button"; break;
                case CMouse::XButton1: theString = "Mouse Button 1"; break;
                case CMouse::XButton2: theString = "Mouse Button 2"; break;
                default: theString = "Unknown Mouse Button"; break;
            }
            break;
            
        case kKeyboardInput:
            switch (mKey)
            {
                case CKeyboard::A: theString = "A"; break;
                case CKeyboard::B: theString = "B"; break;
                case CKeyboard::C: theString = "C"; break;
                case CKeyboard::D: theString = "D"; break;
                case CKeyboard::E: theString = "E"; break;
                case CKeyboard::F: theString = "F"; break;
                case CKeyboard::G: theString = "G"; break;
                case CKeyboard::H: theString = "H"; break;
                case CKeyboard::I: theString = "I"; break;
                case CKeyboard::J: theString = "J"; break;
                case CKeyboard::K: theString = "K"; break;
                case CKeyboard::L: theString = "L"; break;
                case CKeyboard::M: theString = "M"; break;
                case CKeyboard::N: theString = "N"; break;
                case CKeyboard::O: theString = "O"; break;
                case CKeyboard::P: theString = "P"; break;
                case CKeyboard::Q: theString = "Q"; break;
                case CKeyboard::R: theString = "R"; break;
                case CKeyboard::S: theString = "S"; break;
                case CKeyboard::T: theString = "T"; break;
                case CKeyboard::U: theString = "U"; break;
                case CKeyboard::V: theString = "V"; break;
                case CKeyboard::W: theString = "W"; break;
                case CKeyboard::X: theString = "X"; break;
                case CKeyboard::Y: theString = "Y"; break;
                case CKeyboard::Z: theString = "Z"; break;
                case CKeyboard::Num0: theString = "0"; break;
                case CKeyboard::Num1: theString = "1"; break;
                case CKeyboard::Num2: theString = "2"; break;
                case CKeyboard::Num3: theString = "3"; break;
                case CKeyboard::Num4: theString = "4"; break;
                case CKeyboard::Num5: theString = "5"; break;
                case CKeyboard::Num6: theString = "6"; break;
                case CKeyboard::Num7: theString = "7"; break;
                case CKeyboard::Num8: theString = "8"; break;
                case CKeyboard::Num9: theString = "9"; break;
                case CKeyboard::Escape: theString = "Escape"; break;
                case CKeyboard::LControl: theString = "LControl"; break;
                case CKeyboard::LShift: theString = "LShift"; break;
                case CKeyboard::LAlt: theString = "LAlt"; break;
                case CKeyboard::LSystem: theString = "LSystem"; break;
                case CKeyboard::RControl: theString = "RControl"; break;
                case CKeyboard::RShift: theString = "RShift"; break;
                case CKeyboard::RAlt: theString = "RAlt"; break;
                case CKeyboard::RSystem: theString = "RSystem"; break;
                case CKeyboard::Menu: theString = "Menu"; break;
                case CKeyboard::LBracket: theString = "["; break;
                case CKeyboard::RBracket: theString = "]"; break;
                case CKeyboard::SemiColon: theString = ";"; break;
                case CKeyboard::Comma: theString = ","; break;
                case CKeyboard::Period: theString = "."; break;
                case CKeyboard::Quote: theString = "'"; break;
                case CKeyboard::Slash: theString = "/"; break;
                case CKeyboard::BackSlash: theString = "\\"; break;
                case CKeyboard::Tilde: theString = "~"; break;
                case CKeyboard::Equal: theString = "="; break;
                case CKeyboard::Dash: theString = "-"; break;
                case CKeyboard::Space: theString = "Space"; break;
                case CKeyboard::Return: theString = "Return"; break;
                case CKeyboard::BackSpace: theString = "BackSpace"; break;
                case CKeyboard::Tab: theString = "Tab"; break;
                case CKeyboard::PageUp: theString = "PageUp"; break;
                case CKeyboard::PageDown: theString = "PageDown"; break;
                case CKeyboard::End: theString = "End"; break;
                case CKeyboard::Home: theString = "Home"; break;
                case CKeyboard::Insert: theString = "Insert"; break;
                case CKeyboard::Delete: theString = "Delete"; break;
                case CKeyboard::Add: theString = "+"; break;
                case CKeyboard::Subtract: theString = "-"; break;
                case CKeyboard::Multiply: theString = "*"; break;
                case CKeyboard::Divide: theString = "/"; break;
                case CKeyboard::Left: theString = "Left"; break;
                case CKeyboard::Right: theString = "Right"; break;
                case CKeyboard::Up: theString = "Up"; break;
                case CKeyboard::Down: theString = "Down"; break;
                case CKeyboard::Numpad0: theString = "Numpad0"; break;
                case CKeyboard::Numpad1: theString = "Numpad1"; break;
                case CKeyboard::Numpad2: theString = "Numpad2"; break;
                case CKeyboard::Numpad3: theString = "Numpad3"; break;
                case CKeyboard::Numpad4: theString = "Numpad4"; break;
                case CKeyboard::Numpad5: theString = "Numpad5"; break;
                case CKeyboard::Numpad6: theString = "Numpad6"; break;
                case CKeyboard::Numpad7: theString = "Numpad7"; break;
                case CKeyboard::Numpad8: theString = "Numpad8"; break;
                case CKeyboard::Numpad9: theString = "Numpad9"; break;
                case CKeyboard::F1: theString = "F1"; break;
                case CKeyboard::F2: theString = "F2"; break;
                case CKeyboard::F3: theString = "F3"; break;
                case CKeyboard::F4: theString = "F4"; break;
                case CKeyboard::F5: theString = "F5"; break;
                case CKeyboard::F6: theString = "F6"; break;
                case CKeyboard::F7: theString = "F7"; break;
                case CKeyboard::F8: theString = "F8"; break;
                case CKeyboard::F9: theString = "F9"; break;
                case CKeyboard::F10: theString = "F10"; break;
                case CKeyboard::F11: theString = "F11"; break;
                case CKeyboard::F12: theString = "F12"; break;
                case CKeyboard::F13: theString = "F13"; break;
                case CKeyboard::F14: theString = "F14"; break;
                case CKeyboard::F15: theString = "F15"; break;
                case CKeyboard::Pause: theString = "Pause"; break;
                default: theString = "Unknown Key"; break;
            }
            break;
    }
    
    return theString;
}