#include "CTweener.hpp"
#include "Easings/Linear.hpp"

CTweener::CTweener()
: CTweener(Easings::Linear::easeIn, 0.0f, 1.0f, CTime::Seconds(1.0f))
{
    
}

CTweener::CTweener(TEasingFunction theFunction, float startValue, float endValue, CTime duration)
{
    mEasingFunction = theFunction;
    mStartValue = startValue;
    mEndValue = endValue;
    mRange = endValue - startValue;
    mDuration = duration;
    mReversible = false;
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
    if (mCurrentTime > mDuration && mReversible)
    {
        Reverse();
    }
    
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
        mCurrentValue =  mEasingFunction(mCurrentTime.asSeconds(), mStartValue, mRange, mDuration.asSeconds());
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

void CTweener::SetReversible(bool reversible)
{
    mReversible = reversible;
}

bool CTweener::IsDone()
{
    return mCurrentTime >= mDuration;
}

void CTweener::Reverse()
{
    mCurrentTime -= mDuration;
    float temp = mStartValue;
    mStartValue = mEndValue;
    mEndValue = temp;
    mRange = mEndValue - mStartValue;
}