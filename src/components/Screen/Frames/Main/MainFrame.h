#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "../FrameBase.h"

class MainFrame : public FrameBase {
public:
    MainFrame() {
        InitFrame();
    }
    std::string getName() override {
        return "MainFrame";
    }

    std::string getReletiveFilePath() override {
        return "src\\components\\screen\\frames\\Main\\MainFrame.txt"; // It shows Visual Studio, when you click on the file
    }
};

#endif