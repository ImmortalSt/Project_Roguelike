#pragma once
#pragma comment(lib, "user32")
#include "Scene.h"
#include "BattleScene.h"
#include "ShopScene.h"
#include <limits>
#include <Windows.h>
class RunnerSceneBase : Scene
{
public:
	virtual Map* GetMap() = 0;

	// 1 - Умер
	// 2 - Убил всех
	int StartScene() override {
		Map map = *GetMap();
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
			if (GetAsyncKeyState('W') & 0x8000) map.MovePlayer('u');
			else if (GetAsyncKeyState('S') & 0x8000) map.MovePlayer('d');
			else if (GetAsyncKeyState('A') & 0x8000) map.MovePlayer('l');
			else if (GetAsyncKeyState('D') & 0x8000) map.MovePlayer('r');
			else if (GetAsyncKeyState('Q') & 0x8000) {
				if (abs(map.GetPlayer()->GetY() - map.GetStore()->GetY()) + abs(map.GetPlayer()->GetX() - map.GetStore()->GetX()) < 4) {
					auto shopScene = new ShopScene(map.GetPlayer());
					shopScene->StartScene();
				}
			}

			if (map.GetCatchByEnemy() != -1 && timeOut == 0) {
				auto _battleScene = new BattleScene(map.GetPlayer(), map.GetEnemies()->at(map.GetCatchByEnemy()));
				auto result = _battleScene->StartScene();
				if (result == 1) {
					timeOut = 10;
				}
				else if (result == 2) {
					return 1;
				}
				else if (result == 0) {
					map.KillEnemy(map.GetCatchByEnemy());
					if (map.CheckEnemies() == 0) {
						return 2;
					}
				}
			}


			//fieldComponent.lines = RebuildFieldInStrings(&map.RebuildFieldWithFOV(9));
			fieldComponent.lines = RebuildFieldInStrings(map.GetField());

			CharactComponent.lines[0] = L"Your hp : " + std::to_wstring(map.GetPlayer()->getCurHP()) + L"/" + std::to_wstring(map.GetPlayer()->getMaxHP());
			CharactComponent.lines[1] = L"Your armor : " + std::to_wstring(map.GetPlayer()->getArmor());
			CharactComponent.lines[2] = L"Your damage : " + std::to_wstring(map.GetPlayer()->getDamage());

			for (int i = 0; i < (*map.GetEnemies()).size() && timeOut == 0; i++) {
				if (pow(map.GetPlayer()->GetX() - map.GetEnemies()->at(i)->GetX(), 2) + pow(map.GetPlayer()->GetY() - map.GetEnemies()->at(i)->GetY(), 2) <= pow(map.GetEnemies()->at(i)->GetFOV(), 2)) {
					map.MoveEnemy(i, map.GetEnemies()->at(i)->StepToGo(map.GetPlayer()->GetX(), map.GetPlayer()->GetY()));
				}
				else  {
					int ad = rand() % 4;
					switch (ad) {
					case 0:
						map.MoveEnemy(i, 'r');
						break;
					case 1:
						map.MoveEnemy(i, 'u');
						break;
					case 2:
						map.MoveEnemy(i, 'l');
						break;
					case 3:
						map.MoveEnemy(i, 'd');
						break;
					}
				}
			}

			_display->printFrame(FrameNames::Main, components);
			timeOut = (timeOut <= 0) ? 0 : timeOut - 1;
			Sleep(100);
		}
	}

};
