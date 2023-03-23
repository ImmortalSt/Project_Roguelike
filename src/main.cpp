#include <windows.h>
#include "components/Screen/display.h"
#include "components/utills/utils.h"
#include <fcntl.h>
#include <io.h>
#include <fstream>


int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    Display* display = Display::getDisplay();
    std::vector<FrameComponent> temp;
    std::vector<std::wstring> templist;
    temp.push_back(FrameComponent());
    templist.push_back(L"");
    temp[0].x = 7;
    temp[0].y = 26;
    for (int i = 0;true; i++) {
        templist[0] = repeat(L"\x2588", i % 30);
        temp[0].lines = templist;
        display->printFrame(FrameNames::Test, temp, 500);
    }

    return 0;
}

