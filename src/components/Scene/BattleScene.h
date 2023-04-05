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

		components.push_back(&_playerComponent);

		while (true) {

			_playerComponent.x = 3;
			_playerComponent.y = 23;

			_EnemyComponent.x = 100;
			_EnemyComponent.y = 23;

			_playerComponent.lines = _player->GetSprite();


			_display->printFrame(FrameNames::Main, components);
		}
	}
};