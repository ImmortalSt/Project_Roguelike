#ifndef INCLUDEALLFRAMES_H
#define INCLUDEALLFRAMES_H

#include "test/TestFrame.h"

enum FrameNames {
    Test
};

class IncludeAllFrames {
public:
    std::map<FrameNames, FrameBase*> InitAll() {
        std::map<FrameNames, FrameBase*> result;
        result[FrameNames::Test] = new TestFrame();
        return result;
    }
};

#endif