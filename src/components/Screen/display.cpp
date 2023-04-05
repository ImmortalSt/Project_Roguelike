#define FMT_HEADER_ONLY

#include "display.h"
#include <iostream>
#include <Windows.h>
#include "../utills/utils.h"
#include "../fastprint/include/fmt/core.h"
#include "../fastprint/include/fmt/xchar.h"
#include "../fastprint/include/fmt/args.h"
#include "../fastprint/include/fmt/format.h"
#include "../fastprint/include/fmt/chrono.h"
#include "../fastprint/include/fmt/compile.h"
#include "../fastprint/include/fmt/format-inl.h"
#include "../fastprint/include/fmt/os.h"
#include "../fastprint/include/fmt/ostream.h"
#include "../fastprint/include/fmt/printf.h"
#include "../fastprint/include/fmt/ranges.h"
#include "../fastprint/include/fmt/std.h"
#include "../fastprint/include/fmt/color.h"
#include "include/fmt/core.h"
#include "include/fmt/format.h"
#include "include/fmt/format-inl.h"
#include "src/format.cc"

Display* Display::_display = 0;

static std::vector<std::wstring> _currentFrame;

void Display::printFrame(FrameNames name, std::vector<FrameComponent*> frameComponents, int freeze) {
    FrameBase* frame = _frames[name];

    _currentFrame = std::vector<std::wstring>(frame->GetFrame());


    for (int i = 0; i < frameComponents.size(); i++) {
        auto& frameComponent = frameComponents[i];
        int componentHeight = frameComponent->lines.size();
        for (int j = 0; j < componentHeight; j++) {
            int lenght = frameComponent->lines.at(componentHeight - j - 1).size();
            wcsncpy(&_currentFrame.at(frameComponent->y - j - 1).at(frameComponent->x - 1), frameComponent->lines.at(componentHeight - j - 1).c_str(), lenght);
        }
    }
    _final_string = L"";
    for (int i = 0; i < frame->HEIGHT; i++)
        _final_string.append(_currentFrame[i]);
    Clear();
    fmt::print( L"{}", fmt::styled(_final_string, fmt::fg(fmt::color::green)));
    Sleep(freeze);
}
Display* Display::getDisplay(){
    if(!_display)           
        _display = new Display();
    return _display;
}