#pragma once
#include "Scene.h"
#include "BattleScene.h"

class RunnerSceneBase : Scene
{
public:
	virtual Map* GetMap() = 0;

	// 1 - Умер
	// 2 - Убил всех
	int StartScene() override {
		Map map = *GetMap();

		Display* _display = Display::getDisplay();
		FrameComponent fieldComponent;
		std::vector<FrameComponent*> components;
		components.push_back(&fieldComponent);

		fieldComponent.x = 4;
		fieldComponent.y = 24;

		FrameComponent CharactComponent = {4, 29, std::vector<std::wstring>(3)};
		components.push_back(&CharactComponent);


		int timeOut = 0;
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000) map.MovePlayer('u');
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) map.MovePlayer('d');
			else if (GetAsyncKeyState(VK_LEFT) & 0x8000) map.MovePlayer('l');
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) map.MovePlayer('r');
			else if (GetAsyncKeyState('U') & 0x8000) {
				//if (abs(map.GetPlayer()->GetY() - ShopXY.second) + abs(map.GetPlayer()->GetX() - ShopXY.first) < 4) {
				std::exception("pass");
				//}
			}

			if (map.GetCatchByEnemy() != -1 && timeOut == 0) {
				auto _battleScene = new BattleScene(map.GetPlayer(), map.GetEnemies()->at(map.GetCatchByEnemy()));
				auto result = _battleScene->StartScene();
				if (result == 1) {
					timeOut = 10;
				}
				else if (result == 2) return 1;
			}


			//fieldComponent.lines = RebuildFieldInStrings(&map.RebuildFieldWithFOV(9));
			fieldComponent.lines = RebuildFieldInStrings(map.GetField());

			CharactComponent.lines[0] = L"Your hp : " + std::to_wstring(map.GetPlayer()->getCurHP()) + L"/" + std::to_wstring(map.GetPlayer()->getMaxHP());
			CharactComponent.lines[1] = L"Your armor : " + std::to_wstring(map.GetPlayer()->getArmor());
			CharactComponent.lines[2] = L"Your damage : " + std::to_wstring(map.GetPlayer()->getDamage());

			for (int i = 0; i < (*map.GetEnemies()).size() && timeOut == 0; i++) {
				if (abs(map.GetPlayer()->GetX() - map.GetEnemies()->at(i)->GetX()) +
					abs((map.GetPlayer()->GetY() - map.GetEnemies()->at(i)->GetY())) <= pow(map.GetEnemies()->at(i)->GetFOV(), 2)) {
					map.MoveEnemy(i, map.GetEnemies()->at(i)->StepToGo(map.GetPlayer()->GetX(), map.GetPlayer()->GetY()));
				}
			}

			_display->printFrame(FrameNames::Main, components);
			timeOut = (timeOut <= 0) ? 0 : timeOut - 1;
			Sleep(100);
		}
	}

};
