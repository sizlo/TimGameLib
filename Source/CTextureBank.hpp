//
//  CTextureBank.hpp
//  TimGameLib
//
//  Created by Tim Brier on 04/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__CTextureBank__
#define __TimeGameLib__CTextureBank__

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "SFMLIntegration/SFMLIntegration.hpp"

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CTextureBank
{
public:
    // Load or get a loaded texture
    static CTexture * GetTexture(std::string filename);
    static CTexture * GetTexture(std::string filename, bool flipX, bool flipY);
    // Delete all loaded textures
    static void Cleanup();
    
private:
    static std::map<std::string, CTexture *> smTextures;
};

#endif /* defined(__TimeGameLib__CTextureBank__) */
