#ifndef DISPLAY_H
#define DISPLAY_H

#include "Frames/IncludeAllFrames.h"
#include "FrameComponent.h"
#include <vector>
#include <map>
#include "Frames/FrameBase.h"
#include "Assets/Assets.h"
class Display {
private:
    static Display* _display;
    std::map<FrameNames, FrameBase*> _frames;
    std::wstring _final_string;

    Display() {
        _frames = IncludeAllFrames().InitAll();
        _final_string.resize(FrameBase::HEIGHT * FrameBase::WIDTH);
    }

    Display( const Display& );  
    Display& operator=( Display& );


public:    
    static Display* getDisplay();

    void printFrame(FrameNames name, std::vector<FrameComponent*> frameComponents = std::vector<FrameComponent*>(), int freeze = 0);

};

#endif