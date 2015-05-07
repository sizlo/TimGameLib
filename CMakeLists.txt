cmake_minimum_required (VERSION 3.2)

# Use c++11
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

# Set up project
project (TimGameLib)

# CCMake modules
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

# We want to use cotire for precompiled header
include(cotire)

# Set root folder
set(TIM_GAME_LIB_ROOT "$ENV{TIM_GAME_LIB_ROOT}")
if (NOT TIM_GAME_LIB_ROOT)
	message(FATAL_ERROR "TIM_GAME_LIB_ROOT not defined")
endif()

# Set up source file list
include(TimGameLib)

# Find SFML
set(SFML_ROOT "$ENV{SFML_ROOT}")
if (SFML_ROOT)
	find_package(SFML 2.2 COMPONENTS graphics window system audio network)
else()
	message(FATAL_ERROR "SFML_ROOT not defined")
endif()

# Include SFML
include_directories(${SFML_INCLUDE_DIR})

# Include self
include_directories(Source)

# Compile as a library
add_library(TimGameLib ${TIM_GAME_LIB_SOURCES})

if (WIN32)
	# Link Shlwapi.lib for finding exe path
	target_link_libraries(TimGameLib Shlwapi.lib)
endif()

# Link SFML
target_link_libraries(TimGameLib ${SFML_LIBRARIES})

# Use cotire for precompiled header
set_target_properties(TimGameLib PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "Source/TimGameLib_Prefix.pch")
cotire(TimGameLib)