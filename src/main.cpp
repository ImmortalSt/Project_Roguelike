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
#include "components/Scene/BattleScene.h"

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
    Inventory inventory(std::vector<Item*>(), 100);
    Player* player = new Player("Player", 100, 11, 3, inventory, 0, 0);
    Enemy* zombie = new Common_Zombie(0, 0);


    //Scene* battleScene = (Scene*) new BattleScene(player, zombie);
    Scene* battleScene = (Scene*) new RunnerSceneFirstLevel(player);
    engine->StartScene(battleScene);


    return 0;
}

