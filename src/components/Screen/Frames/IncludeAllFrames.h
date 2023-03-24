#ifndef INCLUDEALLFRAMES_H
#define INCLUDEALLFRAMES_H

#include "test/TestFrame.h"
#include "Main/MainFrame.h"

#include <map>

enum class FrameNames {
    Test = 0,
    Main
};

class IncludeAllFrames {
public:
    std::map<FrameNames, FrameBase*> InitAll() {
        std::map<FrameNames, FrameBase*> result;
        result[FrameNames::Test] = new TestFrame();
        result[FrameNames::Main] = new MainFrame();
        return result;
    }
};

#endif