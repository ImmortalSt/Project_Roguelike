cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME Project_Roguelike)
set(CMAKE_BUILD_TYPE "Debug")

project(${PROJECT_NAME})

add_executable(Rogulike 
	src/main.cpp 
	src/components/Screen/display.h 
	src/components/Screen/display.cpp
	src/components/Screen/Frames/FrameBase.h
	src/components/Screen/Frames/test/TestFrame.h
	src/components/Screen/Frames/IncludeAllFrames.h
	src/components/utills/utils.cpp
	src/components/utills/utils.h
	)
