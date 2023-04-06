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
#include "components/Scene/RunnerSceneSecondLevel.h"
#include "components/Scene/RunnerSceneThirdLevel.h"
#include <time.h>
#include "components/Scene/BattleScene.h"
#include "components/shop/shop.h"


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
    Inventory inventory(std::vector<Item*>(), 500);
    Player* player = new Player("Player", 100, 100, 999, 3, inventory, 0, 0);

    player->showInventory();

    //Scene* battleScene = (Scene*) new ShopScene(player);
    Scene* battleScene;
    int level = 1;
    while (level <= 3) {
        if (level == 1) {
            Inventory inventory(std::vector<Item*>(), 500);
            player = new Player("Player", 100, 50, 999, 3, inventory, 0, 0);
            battleScene = (Scene*) new RunnerSceneFirstLevel(player);
        }
        else if (level == 2) {
            battleScene = (Scene*) new RunnerSceneSecondLevel(player);
        }
        else if (level == 3) {
            battleScene = (Scene*) new RunnerSceneThirdLevel(player);
        }
        auto result = battleScene->StartScene();
        if (result == 1) {
            level = 1;
        }
        else if (result == 2) {
            level++;
        }
    }

    return 0;
}

