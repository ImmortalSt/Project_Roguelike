#pragma once


#include "Scene.h"

class BattleScene : Scene {
public:
	Player* _player;
	Enemy* _enemy;
	Display* _display;
	BattleScene(Player* player, Enemy* enemy) {
		_player = player;
		_enemy = enemy;
	}
	int StartScene() override {
		_display = Display::getDisplay();

		FrameComponent _playerComponent;
		FrameComponent _EnemyComponent;
		std::vector<FrameComponent*> components;
		FrameComponent _PlayerParameters = { 46, 6, std::vector<std::wstring>(3)};

		components.push_back(&_playerComponent);
		components.push_back(&_EnemyComponent);
		components.push_back(&_PlayerParameters);

		while (true) {

			_playerComponent.x = 3;
			_playerComponent.y = 23;

			_EnemyComponent.x = 110;
			_EnemyComponent.y = 23;

			_playerComponent.lines = AssetsInstance->GetAsset(Assets::AssetsName::Player1);
			_EnemyComponent.lines = _enemy->GetSprite();
			_PlayerParameters.lines[0] = L"HP: " + std::to_wstring(_player->getHP());
			_PlayerParameters.lines[1] = L"Armor: " + std::to_wstring(_player->getArmor());
			_PlayerParameters.lines[2] = L"Your damege: " + std::to_wstring(_player->getDamage());

			_display->printFrame(FrameNames::Main, components);

			Sleep(20);
		}
	}
};