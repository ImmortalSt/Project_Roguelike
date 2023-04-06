#pragma once
#include "RunnerSceneBase.h"
#include "../MapGenerator/MapGenerate.h"

class RunnerSceneFirstLevel : RunnerSceneBase {
private:
	Player* _player;
public:
	RunnerSceneFirstLevel(Player* player) {
		_player = player;
	}
	Map* GetMap() override {
		Map_gen* map_gen = new Map_gen();
		map_gen->Generate(3, _player, 1, 1, 1);

		Map* map = new Map(map_gen->GetField(), _player, map_gen->GetEnemies(), map_gen->GetStore());

		return map;
	}
};