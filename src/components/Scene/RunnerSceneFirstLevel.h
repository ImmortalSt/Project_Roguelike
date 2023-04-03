#pragma once
#include "RunnerSceneBase.h"
#include "../MapGenerator/MapGenerate.h"

class RunnerSceneFirstLevel : RunnerSceneBase {
	Map* GetMap() override {
		Map* map = new Map()
		map.
		return (new ())->Generate(3, 3);
	}
};