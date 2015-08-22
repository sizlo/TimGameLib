#include "CTweener.hpp"

CTweener::CTweener(TEasingFunction theFunction, float startValue, float endValue, CTime duration)
{
    mEasingFunction = theFunction;
    mStartValue = startValue;
    mEndValue = endValue;
    mRange = endValue - startValue;
    mDuration = duration;
    Reset();
}

CTweener::~CTweener()
{
    
}

void CTweener::Reset()
{
    mCurrentTime = CTime::Zero;
    mCurrentValue = mStartValue;
}

float CTweener::Advance(CTime elapsedTime)
{
    mCurrentTime += elapsedTime;
    if (mCurrentTime < CTime::Zero)
    {
        mCurrentValue = mStartValue;
    }
    else if (mCurrentTime > mDuration)
    {
        mCurrentValue = mEndValue;
    }
    else
    {
        mCurrentValue =  mEasingFunction(mCurrentTime.asSeconds(), mStartValue, mEndValue, mDuration.asSeconds());
    }
    return mCurrentValue;
}

float CTweener::GetCurrentValue()
{
    return mCurrentValue;
}

CTime CTweener::GetCurrentTime()
{
    return mCurrentTime;
}

CTime CTweener::GetDuration()
{
    return mDuration;
}