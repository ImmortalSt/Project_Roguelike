#include "display.h"
#include <iostream>
#include <Windows.h>
#include "../utills/utils.h"


Display* Display::_display = 0;

static std::vector<std::wstring> _currentFrame;

void Display::printFrame(FrameNames name, std::vector<FrameComponent> frameComponents, int freeze) {
    FrameBase* frame = _frames[name];

    _currentFrame = std::vector<std::wstring>(frame->GetFrame());


    for (int i = 0; i < frameComponents.size(); i++) {
        auto& frameComponent = frameComponents[i];
        int componentHeight = frameComponent.lines.size();
        for (int j = 0; j < componentHeight; j++) {
            wcsncpy(&_currentFrame.at(frameComponent.y - j - 1).at(frameComponent.x - 1), &frameComponent.lines[componentHeight - j - 1][0], frameComponent.lines[j].size());
        }
    }
    _final_string.clear();
    for (int i = 0; i < frame->HEIGHT; i++)
        _final_string.append(_currentFrame[i]);
    Clear();
    std::wcout << _final_string;
    Sleep(freeze);
}
Display* Display::getDisplay(){
    if(!_display)           
        _display = new Display();
    return _display;
}