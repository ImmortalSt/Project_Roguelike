#pragma once
#include "Scene.h"

class RunnerSceneBase : Scene
{
public:
	virtual Map* GetMap() = 0;


	int StartScene() override {
		Map map = *GetMap();

		Display* _display = Display::getDisplay();
		FrameComponent fieldComponent;
		std::vector<FrameComponent*> components;
		components.push_back(&fieldComponent);

		fieldComponent.x = 4;
		fieldComponent.y = 24;

		FrameComponent CharactComponent;
		components.push_back(&CharactComponent);
		CharactComponent.lines.push_back(L"");
		CharactComponent.lines.push_back(L"");
		CharactComponent.x = 4;
		CharactComponent.y = 27;


		while (true)
		{
			if (GetAsyncKeyState(VK_UP)) map.MovePlayer('u');
			else if (GetAsyncKeyState(VK_DOWN)) map.MovePlayer('d');
			else if (GetAsyncKeyState(VK_LEFT)) map.MovePlayer('l');
			else if (GetAsyncKeyState(VK_RIGHT)) map.MovePlayer('r');
			else if (GetAsyncKeyState('U') & 0x8000) {
				//if (abs(map.GetPlayer()->GetY() - ShopXY.second) + abs(map.GetPlayer()->GetX() - ShopXY.first) < 4) {
					std::exception("pass");
				//}
			}

			if (map.GetCatchByEnemy() != -1) {

			}


			fieldComponent.lines = RebuildFieldInStrings(&map.RebuildFieldWithFOV(9));
			//fieldComponent.lines = RebuildFieldInStrings(map.GetField());

			CharactComponent.lines[0] = L"Your hp : " + std::to_wstring(map.GetPlayer()->getCurHP());
			CharactComponent.lines[1] = L"Your armor : " + std::to_wstring(map.GetCatchByEnemy());

			_display->printFrame(FrameNames::Main, components);

			Sleep(100);
		}
	}

};
