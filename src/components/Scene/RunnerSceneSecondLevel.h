#pragma once
#include "RunnerSceneBase.h"
#include "../MapGenerator/MapGenerate.h"

class RunnerSceneSecondLevel : RunnerSceneBase {
private:
	Player* _player;
public:
	RunnerSceneSecondLevel(Player* player) {
		_player = player;
	}
	Map* GetMap() override {
		Map_gen* map_gen = new Map_gen();
		map_gen->Generate(6, _player, 3, 3, 2);

		Map* map = new Map(map_gen->GetField(), _player, map_gen->GetEnemies(), map_gen->GetStore());

		return map;
	}
};
