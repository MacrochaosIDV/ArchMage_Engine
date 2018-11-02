cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(UNITTESTING_VERSIO_MAJOR 1)
set(UNITTESTING_VERSIO_MINOR 0)
set(LEARN_CMAKE_VERSION_PATCH 0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Set the dir for amUtilities source/include
# set(AM_UTILITIES_DIR "./amUtilities")

project(ArchMageEngine_Utilities_UnitTesting)

# install()

SET(TARGET_SRC  
	# AM_UTILITIES_DIR/Include/amPrerequisitesUtilities.h
	./amUtilities_UnitTest/Source/main.cpp
    )
# install
	
add_executable(ArchMageEngine_UnitTesting ${TARGET_SRC})

# 



