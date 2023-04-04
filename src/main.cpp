#include <windows.h>
#include "components/Screen/display.h"
#include "components/utills/utils.h"
#include <fcntl.h>
#include <io.h>
#include "components/json/nlohmann/single_include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include "components/Engine/Engine.h"
#include "components/MapGenerator/MapGenerate.h"
#include "components/Scene/RunnerSceneFirstLevel.h"
#include <time.h>

BOOL ShowConsoleCursor(BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;
    if (!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    cci.bVisible = bShow;
    if (!SetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    return TRUE;
}

int main() {
    srand(time(0));

    ShowConsoleCursor(FALSE);
    ShowCursor(FALSE);
    _setmode(_fileno(stdout), _O_U16TEXT);

    Engine* engine = new Engine();
    Inventory inventory(std::vector<Item>(), 100);
    Player* player = new Player("Player", 100, 10, 0, inventory, 0, 0);

    RunnerSceneFirstLevel* firstScene = new RunnerSceneFirstLevel(player);
    
    engine->StartScene((Scene*)firstScene);


    return 0;
}

