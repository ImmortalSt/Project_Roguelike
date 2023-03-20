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

    //std::map<std::string, Field> getFields() override {
    //    auto result = std::map<std::string, Field>();
    //    result["Load bar"] = {14, 26, 105}; 
    //    return result;
    //};

    std::string getFilePath() override {
        return "/home/ubuntu/git/Project_Roguelike/Project_Roguelike/src/components/Screen/Frames/test/Test.txt";
    }
};

#endif