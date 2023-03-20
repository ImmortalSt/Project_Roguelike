#include "components/Screen/display.h"
#include "components/utills/utils.h"

int main() {
    setlocale(LC_ALL, "");
    Display* display = Display::getDisplay();
    std::vector<FrameComponent> temp;
    std::vector<std::wstring> templist;
    temp.push_back(FrameComponent());
    templist.push_back(L"");
    temp[0].x = 6;
    temp[0].y = 26;
    for (int i = 0;true; i++) {
        
        templist[0] = repeat(L"█", i % 30);
        temp[0].lines = templist;
        display->printFrame(FrameNames::Test, temp);
        usleep(100000);
        Clear();
    }
    return 0;
}