#pragma once
#include "Scene.h"

class ShopScene : Scene {
private:
	Player* _player;

public:
	ShopScene(Player* player) {
		_player = player;
	}

	int StartScene() override {
		FrameComponent ShopComponent = {2, 29, AssetsInstance->GetAsset(Assets::AssetsName::shop)};
		FrameComponent BuyComponent = { 89, 19, std::vector<std::wstring>{L"     BUY      ", 
																	      L"--------------",
																		  L"Med Kit  = 10m",L"",
																		  L"DamageUp = 10m",L"",
																		  L"HpUp     = 10m",L"",
																		  L"ArmorUp  = 10m"}};
		FrameComponent SellComponent = { 116, 19, std::vector<std::wstring>{L"     SELL    ",
																		  L"--------------",
																		  L"Med Kit  = 10m",L"",
																		  L"DamageUp = 10m",L"",
																		  L"HpUp     = 10m",L"",
																		  L"ArmorUp  = 10m"} };

		FrameComponent boxComponent = { 88, 20, std::vector<std::wstring>{L"█", L"████████"} };

		std::vector<FrameComponent*> components;
		components.push_back(&ShopComponent);
		components.push_back(&BuyComponent);
		components.push_back(&SellComponent);
		components.push_back(&boxComponent);

		int choice = 0;
		while (true) {

			_display->printFrame(FrameNames::Main, components);

			char key = _getchar();

			if (key == 'w' && choice < 7) choice++;
			if (key == 's' && choice > 0) choice--;
			if (key == 'a' && choice > 3) choice -= 4;
			if (key == 'd' && choice < 4) choice += 4;
			if (key == '\x1b') return 0;

			boxComponent.x = 88 + (27 * (choice / 4));
			boxComponent.y = 20 - 2 * (choice % 4);

		}
	}
};