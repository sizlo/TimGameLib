//
//  Macros.hpp
//  TimGameLib
//
//  Created by Tim Brier on 25/09/2014.
//  Copyright (c) 2014 tbrier. All rights reserved.
//

#ifndef TimeGameLib_Macros_hpp
#define TimeGameLib_Macros_hpp

// =============================================================================
// Allocation
// -----------------------------------------------------------------------------
#define SAFE_DELETE(ptr)    \
    if (ptr != NULL)        \
    {                       \
        delete ptr;         \
        ptr = NULL;         \
    }

// =============================================================================
// Logging
// -----------------------------------------------------------------------------
#if TGL_DEBUG
#define DEBUG_LOG(...)                      \
    printf("%s:%d ", __FILE__, __LINE__);   \
    printf(__VA_ARGS__);                    \
    printf("\n");
#else
#define DEBUG_LOG(fmt, ...)
#endif

// =============================================================================
// Iterate over lists
// -----------------------------------------------------------------------------
#define FOR_EACH_IN_LIST(type, listName)                            \
    for (std::list<type>::iterator it = listName.begin();           \
         it != listName.end();                                      \
         ++it)

// =============================================================================
// Free the contents of a list
// -----------------------------------------------------------------------------
#define FREE_LIST_CONTENTS(listName)                                \
    while (!listName.empty())                                       \
    {                                                               \
        auto removed = listName.front();                            \
        listName.remove(removed);                                   \
        SAFE_DELETE(removed);                                       \
    }

#endif
