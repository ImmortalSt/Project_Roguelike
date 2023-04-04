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
		std::vector<FrameComponent*> components;

		components.push_back(&_playerComponent);

		while (true) {

			_playerComponent.x = 3;
			_playerComponent.y = 23;
			_playerComponent.lines = Assets::GetAsset(Assets::AssetsName::Player1);


			_display->printFrame(FrameNames::Main, components);
		}
	}
};