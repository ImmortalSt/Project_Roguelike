#ifndef DISPLAY_H
#define DISPLAY_H

#include "Frames/IncludeAllFrames.h"
#include "FrameComponent.h"
#include <vector>

class Display {
private:
    static Display* _display;
    std::map<FrameNames, FrameBase*> _frames;

    Display() {
        _frames = IncludeAllFrames().InitAll();
    }

    Display( const Display& );  
    Display& operator=( Display& );


public:    
    static Display* getDisplay();

    void printFrame(FrameNames name, std::vector<FrameComponent> frameComponents = std::vector<FrameComponent>());

};

#endif