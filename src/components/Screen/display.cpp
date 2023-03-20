#include "display.h"

Display* Display::_display = 0;

static std::vector<std::wstring> _currentFrame;
void Display::printFrame(FrameNames name, std::vector<FrameComponent> frameComponents) {
    FrameBase* frame = _frames[name];

    _currentFrame = std::vector<std::wstring>(frame->GetFrame());


    for (int i = 0; i < frameComponents.size(); i++) {
        auto& frameComponent = frameComponents[i];
        for (int j = 0; j < frameComponent.lines.size(); j++) {
            wcsncpy(&_currentFrame.at(frameComponent.y - j - 1).at(frameComponent.x - 1), &frameComponent.lines[j][0], frameComponent.lines[j].size());
        }
    }
    
    for (int i = 0; i < frame->HEIGHT; i++)
        std::wcout << _currentFrame[i];
}
Display* Display::getDisplay(){
    if(!_display)           
        _display = new Display();
    return _display;
}