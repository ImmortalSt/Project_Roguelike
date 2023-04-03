#pragma once
#include "Scene.h"
#include "../Screen/display.h"

class RunnerSceneBase : Scene
{
private:
	std::pair<int, int> ShopXY;
public:
	virtual Map* GetMap() = 0;


	int StartScene() override {
		Map map = *GetMap();
		map.GetField()->SetCell(map.GetPlayer()->GetY() - 1, map.GetPlayer()->GetX(), CellState::shop);
		ShopXY.first = map.GetPlayer()->GetX();
		ShopXY.second = map.GetPlayer()->GetY() - 1;

		Display* _display = Display::getDisplay();
		FrameComponent fieldComponent;
		std::vector<FrameComponent*> components;
		components.push_back(&fieldComponent);

		fieldComponent.x = 4;
		fieldComponent.y = 24;

		FrameComponent CharactComponentHp;
		components.push_back(&CharactComponentHp);
		CharactComponentHp.x = 5;
		CharactComponentHp.y = 24;
		std::vector<std::wstring> CharactHp;
		CharactHp.push_back(L"");

		FrameComponent CharactComponentArmor;
		components.push_back(&CharactComponentArmor);
		CharactComponentArmor.x = 5;
		CharactComponentArmor.y = 26;
		std::vector<std::wstring> CharactArmor;
		CharactArmor.push_back(L"");

		while (true)
		{
			if (GetAsyncKeyState(VK_UP)) map.MovePlayer('u');
			else if (GetAsyncKeyState(VK_DOWN)) map.MovePlayer('d');
			else if (GetAsyncKeyState(VK_LEFT)) map.MovePlayer('l');
			else if (GetAsyncKeyState(VK_RIGHT)) map.MovePlayer('r');
			else if (GetAsyncKeyState('U') & 0x8000) {
				if (abs(map.GetPlayer()->GetY() - ShopXY.second) + abs(map.GetPlayer()->GetX() - ShopXY.first) < 4) {
					return ToShop;
				}
			}

			//fieldComponent.lines = RebuildFieldInStrings(&map.RebuildFieldWithFOV());
			fieldComponent.lines = RebuildFieldInStrings(map.GetField());

			CharactHp[0] = L"Your hp : " + std::to_wstring(map.GetPlayer()->getHP());
			CharactArmor[0] = L"Your armor : " + std::to_wstring(map.GetPlayer()->getArmor());
			CharactComponentHp.lines = CharactHp;
			CharactComponentArmor.lines = CharactArmor;

			_display->printFrame(FrameNames::Main, components);

			Sleep(100);
		}
	}

};
