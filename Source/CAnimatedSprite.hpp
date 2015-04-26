//
//  CAnimatedSprite.hpp
//  TimGameLib
//
//  Created by Tim Brier on 13/04/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __TimGameLib__CAnimatedSprite__
#define __TimGameLib__CAnimatedSprite__

#include "SFMLIntegration/SFMLIntegration.hpp"
#include "CUpdateable.hpp"

struct SAnimationFrame
{
    CIntRect    textureRect;
    CTime       duration;
};

class CAnimatedSprite : public CSprite, public CUpdateable
{
public:
    CAnimatedSprite(std::string textureFileName);
    ~CAnimatedSprite();
    
    void Update(CTime elapsedTime);
    
    void Play();
    void Pause();
    void Start();
    
    void AddFrame(CIntRect theRect, CTime theDuration);
    
    int GetCurrentFrameIndex();
    
private:
    void AdvanceFrame();
    
    std::vector<SAnimationFrame>              mFrames;
    std::vector<SAnimationFrame>::iterator    mCurrentFrame;
    
    CTime mTotalElapsedTime;
    
    bool mPaused;
};

#endif /* defined(__TimGameLib__CAnimatedSprite__) */
