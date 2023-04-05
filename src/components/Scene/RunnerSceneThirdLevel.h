#pragma once
#include "RunnerSceneBase.h"
#include "../MapGenerator/MapGenerate.h"

class RunnerSceneThirdLevel : RunnerSceneBase {
private:
	Player* _player;
public:
	RunnerSceneThirdLevel(Player* player) {
		_player = player;
	}
	Map* GetMap() override {
		Map_gen* map_gen = new Map_gen();
		map_gen->Generate(10, _player, 2, 8, 5);

		Map* map = new Map(map_gen->GetField(), _player, map_gen->GetEnemies());

		return map;
	}
};
