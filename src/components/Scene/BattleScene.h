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

	// 0 - Победил
	// 1 - Убежал
	// 2 - Умер
	int StartScene() override {
		_display = Display::getDisplay();

		FrameComponent _playerComponent;
		FrameComponent _enemyComponent;
		std::vector<FrameComponent*> components;
		FrameComponent _playerParameters = { 50, 6, std::vector<std::wstring>(4)};
		FrameComponent _enemyParameters = { 80, 6, std::vector<std::wstring>(4) };
		FrameComponent _choiceComponent = { 52, 20, std::vector<std::wstring>{L"Attack", L"", L"Use medkit", L"", L"Run away"}};
		FrameComponent _boxComponent = { 50, 21, std::vector<std::wstring>{L"████████████", L"█", L"████████████"} };

		components.push_back(&_playerComponent);
		components.push_back(&_enemyComponent);
		components.push_back(&_playerParameters);
		components.push_back(&_enemyParameters);
		components.push_back(&_choiceComponent);
		components.push_back(&_boxComponent);


		int choice = 0;
		while (true) {
			_playerComponent.x = 3;
			_playerComponent.y = 23;

			_enemyComponent.x = 110;
			_enemyComponent.y = 23;

			_playerComponent.lines = _player->GetSprite(1);
			_enemyComponent.lines = _enemy->GetSprite();

			_playerParameters.lines[0] = L"Player";
			_playerParameters.lines[1] = L"HP: " + std::to_wstring(_player->getCurHP());
			_playerParameters.lines[2] = L"Armor: " + std::to_wstring(_player->getArmor());
			_playerParameters.lines[3] = L"Damege: " + std::to_wstring(_player->getDamage());
			_enemyParameters.lines[0] = L"Write A Zombie Name";
			_enemyParameters.lines[1] = L"Armor: " + std::to_wstring(_enemy->getArmor());
			_enemyParameters.lines[2] = L"HP: " + std::to_wstring(_enemy->getHp());
			_enemyParameters.lines[3] = L"Damage: " + std::to_wstring(_enemy->getDamage());


			_display->printFrame(FrameNames::Main, components);
			
			char key = _getchar();

			if (key == 'w' && choice < 2) choice++;
			if (key == 's' && choice > 0) choice--;

			_boxComponent.y = 21 - 2 * choice;

			if (key == VK_RETURN) {
				Sleep(300);

				if (choice == 0) return 1;
				else if (choice == 1) {
					
				}
				else if (choice == 2) {
					_playerComponent.x = 15;
					_playerComponent.lines = _player->GetSprite(2);
					_display->printFrame(FrameNames::Main, components);
					Sleep(300);
					_playerComponent.x = 30;
					_playerComponent.lines = _player->GetSprite(3);
					_display->printFrame(FrameNames::Main, components);
					Sleep(300);
					_enemy->takeDamage(_player->getDamage());

					if (_enemy->getHp() <= 0) {
						return 0;
					}

				}


				_enemyComponent.x = 90;
				_player->takeDamage(_enemy->getDamage());
				_display->printFrame(FrameNames::Main, components);

				Sleep(300);

				if (_player->getCurHP() <= 0) return 2;
			}


		}
	}
};