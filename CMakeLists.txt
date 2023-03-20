cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME Project_Roguelike)
set(CMAKE_BUILD_TYPE "Debug")

project(${PROJECT_NAME})

add_library(frameBase src/components/Screen/Frames/FrameBase.h)
set_target_properties(frameBase PROPERTIES LINKER_LANGUAGE CXX)

add_library(testFrame src/components/Screen/Frames/test/TestFrame.h)
set_target_properties(testFrame PROPERTIES LINKER_LANGUAGE CXX)

add_library(includeAllFrames src/components/Screen/Frames/IncludeAllFrames.h)
set_target_properties(includeAllFrames PROPERTIES LINKER_LANGUAGE CXX)


add_library(display SHARED src/components/Screen/display.h src/components/Screen/display.cpp)

add_executable(Rogulike src/main.cpp)

target_link_libraries(testFrame frameBase)
target_link_libraries(includeAllFrames testFrame)
target_link_libraries(display includeAllFrames)
target_link_libraries(Rogulike PUBLIC display)
