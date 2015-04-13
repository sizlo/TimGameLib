//
//  CAnimatedSprite.cpp
//  TimGameLib
//
//  Created by Tim Brier on 13/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CAnimatedSprite.hpp"

CAnimatedSprite::CAnimatedSprite(std::string textureFileName)
:   CSprite(textureFileName)
{
    mPaused = true;
}

CAnimatedSprite::~CAnimatedSprite()
{
    
}

void CAnimatedSprite::Update(CTime elapsedTime)
{
    if (!mPaused)
    {
        mTotalElapsedTime += elapsedTime;
        
        while (mTotalElapsedTime >= mCurrentFrame->duration)
        {
            AdvanceFrame();
        }
    }
}

void CAnimatedSprite::Play()
{
    mPaused = false;
}

void CAnimatedSprite::Pause()
{
    mPaused = true;
}

void CAnimatedSprite::Start()
{
    mCurrentFrame = mFrames.begin();
    setTextureRect(mCurrentFrame->textureRect);
    mTotalElapsedTime = CTime::Zero;
    Play();
}

void CAnimatedSprite::AddFrame(CIntRect theRect, CTime theDuration)
{
    SAnimationFrame theFrame;
    theFrame.textureRect = theRect;
    theFrame.duration = theDuration;
    
    mFrames.push_back(theFrame);
}

void CAnimatedSprite::AdvanceFrame()
{
    mTotalElapsedTime -= mCurrentFrame->duration;
    mCurrentFrame++;
    if (mCurrentFrame == mFrames.end())
    {
        mCurrentFrame = mFrames.begin();
    }
    
    setTextureRect(mCurrentFrame->textureRect);
}