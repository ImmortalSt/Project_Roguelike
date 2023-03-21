#ifndef TESTFRAME_H
#define TESTFRAME_H

#include "../FrameBase.h"

class TestFrame : public FrameBase {
public:
    TestFrame() {
        InitFrame();
    }
    std::string getName() override {
        return "Test";
    }

    std::string getReletiveFilePath() override {
        return "src\\components\\screen\\frames\\test\\Test.txt"; // It shows Visual Studio, when you click on the file
    }
};

#endif