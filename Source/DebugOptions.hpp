//
//  DebugOptions.hpp
//  TimGameLib
//
//  Created by Tim Brier on 05/10/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef __TimeGameLib__DebugOptions__
#define __TimeGameLib__DebugOptions__

// =============================================================================
// Include Files
// -----------------------------------------------------------------------------
#include "CRenderable.hpp"
#include "CUpdateable.hpp"

// =============================================================================
// Macros
// -----------------------------------------------------------------------------
#define TOGGLE_DEBUG_OPTION(key, option)                        \
    if (SystemUtilities::WasKeyPressedThisCycle(CKeyboard::key))\
    {                                                           \
        option = !option;                                       \
    }

// =============================================================================
// namespace definition
// -----------------------------------------------------------------------------
namespace DebugOptions
{
    // Public globals
    extern bool showFramerate;
    extern bool drawBounds;
    extern bool drawOrigins;
    extern bool drawShapePoints;
    extern bool drawShapeNormals;
    extern bool useSlowMotion;
    extern bool showMouseCoords;
};

// =============================================================================
// Class definition
// -----------------------------------------------------------------------------
class CDebugHelper : public CUpdateable, public CRenderable
{
public:
    CDebugHelper();
    ~CDebugHelper();
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
    void AddShape(CConvexShape *theShape);
    void RemoveShape(CConvexShape *theShape);
    
    void AddLine(CLine theLine);
    void RemoveLine(CLine theLine);
    
private:
    std::list<CConvexShape *> mShapes;
    std::list<CLine> mLines;
};

#endif /* defined(__TimeGameLib__DebugOptions__) */
