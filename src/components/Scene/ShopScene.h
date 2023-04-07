#pragma once
#define FMT_HEADER_ONLY
#include "Scene.h"
#include "../shop/shop.h"
#include "include/fmt/core.h"
#include "include/fmt/ranges.h"
#include "include/fmt/format.h"
#include "../items/HealthUp.h"
#include "../items/ArmorUp.h"
#include "../items/DamageUp.h"
#include "../items/MedKit.h"

class ShopScene : Scene {
private:
	Player* _player;
	std::vector<wstring> _show;
	std::vector<wstring> _items;

public:
	ShopScene(Player* player) {
		_player = player;
	}

	int StartScene() override {

		Store* shop1 = new Store(5, 5, 5, 5);
		_show = _player->showInventory();
		_items = shop1->countItems();
		FrameComponent ShopComponent = {2, 29, AssetsInstance->GetAsset(Assets::AssetsName::shop)};
		FrameComponent playerComponent = { 5, 10, _show };
		FrameComponent itemsComponent = { 20, 9, _items};
		FrameComponent BuyComponent = { 89, 19, std::vector<std::wstring>{L"     BUY      ", 
																	      L"--------------",
																		  L"Med Kit  = 50",L"",
																		  L"DamageUp = 100",L"",
																		  L"HpUp     = 100",L"",
																		  L"ArmorUp  = 100"}};
		FrameComponent SellComponent = { 116, 19, std::vector<std::wstring>{L"     SELL    ",
																		  L"--------------",
																		  L"Med Kit  = 25",L"",
																		  L"DamageUp = 50",L"",
																		  L"HpUp     = 50",L"",
																		  L"ArmorUp  = 50"} };

		FrameComponent boxComponent = { 88, 20, std::vector<std::wstring>{L"█", L"████████"} };

		std::vector<FrameComponent*> components;
		components.push_back(&ShopComponent);
		components.push_back(&playerComponent);
		components.push_back(&BuyComponent);
		components.push_back(&SellComponent);
		components.push_back(&boxComponent);
		components.push_back(&itemsComponent);
		
		HealthUp* hpup1 = new HealthUp("hpup2", 50);	
		DamageUp* dmgup1 = new DamageUp("dmgup2", 20);
		ArmorUp* armup1 = new ArmorUp("armup1", 5);
		Medkit* medkit = new Medkit("mkit");

		int choice = 0;
		while (true) {
			itemsComponent.lines = shop1->countItems();
			playerComponent.lines = _player->showInventory();;
			_display->printFrame(FrameNames::Main, components);

			//char key = _getchar();

			if ((GetAsyncKeyState('W') & 0x8000) && choice < 7) choice++;
			if ((GetAsyncKeyState('S') & 0x8000) && choice > 0) choice--;
			if ((GetAsyncKeyState('A') & 0x8000) && choice > 3) choice -= 4;
			if ((GetAsyncKeyState('D') & 0x8000) && choice < 4) choice += 4;
			if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000)) return 0;
			if ((GetAsyncKeyState(VK_RETURN) & 0x8000)) {
				if (choice == 0) {
					ArmorUp* armup1 = new ArmorUp("armup1", 5);
					shop1->buyItem(armup1, _player);
					_display->printFrame(FrameNames::Main, components);
				}
				if (choice == 1) {
					HealthUp* hpup1 = new HealthUp("hpup1", 50);
					shop1->buyItem(hpup1, _player);
					_display->printFrame(FrameNames::Main, components);
				}
				if (choice == 2) {
					DamageUp* dmgup1 = new DamageUp("dmgup1", 10);
					shop1->buyItem(dmgup1, _player);
				}
				if (choice == 3) {
					Medkit* medkit = new Medkit("mkit");
					shop1->buyItem(medkit, _player);
				}
				if (choice == 4) {
					shop1->sellItem(armup1, _player);
				}
				if (choice == 5) {
					shop1->sellItem(hpup1, _player);
				}
				if (choice == 6) {
					shop1->sellItem(dmgup1, _player);
				}
				if (choice == 7) {
					shop1->sellItem(medkit, _player);
				}

			}
			boxComponent.x = 88 + (27 * (choice / 4));
			boxComponent.y = 20 - 2 * (choice % 4);

		}
	}
};