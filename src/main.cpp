#include <windows.h>
#include "components/Screen/display.h"
#include "components/utills/utils.h"
#include <locale.h>
#include <synchapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <io.h>
#include <nlohmann/json.hpp>
#include <fstream>

int main() {

    std::wcout.imbue(std::locale("en_US.UTF-16"));
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
        Sleep(5000);
        Clear();
    }

    return 0;
}

