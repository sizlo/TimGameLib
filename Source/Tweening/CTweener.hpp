#ifndef __TimGameLib__CTweener__
#define __TimGameLib__CTweener__

#include "SFMLIntegration/SFMLIntegration.hpp"

typedef float (*TEasingFunction)(float, float, float, float);

class CTweener
{
public:
    CTweener();
    CTweener(TEasingFunction theFunction, float startValue, float endValue, CTime duration);
    ~CTweener();
    
    void Reset();
    float Advance(CTime elapsedTime);
    float GetCurrentValue();
    CTime GetCurrentTime();
    CTime GetDuration();
    
private:
    TEasingFunction mEasingFunction;
    CTime mDuration;
    float mStartValue;
    float mEndValue;
    float mRange;
    CTime mCurrentTime;
    float mCurrentValue;
};

#endif // __TimGameLib__CTweener__
