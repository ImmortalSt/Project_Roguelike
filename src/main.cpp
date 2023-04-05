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
#include "components/shop/shop.h"
#include "components/items/HealthUp.h"
#include "components/items/ArmorUp.h"
#include "components/items/DamageUp.h"
#include "components/items/MedKit.h"

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
    Player* player = new Player("Player", 100, 100, 15, 3, inventory, 0, 0);
    Enemy* zombie = new Common_Zombie(0, 0);
    Store* store = new Store(2, 2, 2, 2);
    HealthUp* hpup = new HealthUp("healthup", 40);
    ArmorUp* armorUp = new ArmorUp("armorUp", 10);
    Medkit* mkit = new Medkit("medkit");
    store->buyItem(hpup, player);
    store->buyItem(armorUp, player);
    store->sellItem(hpup, player);
    store->buyItem(mkit, player);
    player->Heal(mkit);





    Scene* battleScene = (Scene*) new RunnerSceneFirstLevel(player);
    //Scene* battleScene = (Scene*) new RunnerSceneFirstLevel(player);
    battleScene->StartScene();


    return 0;
}

