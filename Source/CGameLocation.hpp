//
//  CGameLocation.hpp
//  TimGameLib
//
//  Created by Tim Brier on 04/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef TimeGameLib_CGameLocation_hpp
#define TimeGameLib_CGameLocation_hpp

// =============================================================================
// Game location enum
// -----------------------------------------------------------------------------
enum EGameLocation
{
    kGameLocationDummy
};

// =============================================================================
// Abstract class definition
// -----------------------------------------------------------------------------
class CGameLocation
{
public:
    virtual ~CGameLocation(){};
    
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    
    virtual void ReactToFocusLost(){};
    virtual void ReactToFocusGained(){};
};

// =============================================================================
// Dummy Game Location
// -----------------------------------------------------------------------------
class CDummyGameLocation : public CGameLocation
{
public:
    CDummyGameLocation(){};
    ~CDummyGameLocation(){};
    
    virtual void Enter(){};
    virtual void Exit(){};
};

#endif
