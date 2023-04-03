#pragma once
#include "../Map/Map.h"
#include "../Scene/Scene.h"
#include "../MapGenerator/MapGenerate.h"

class Engine {
private:
public:
	Engine() {}

	int StartScene(Scene* scene) {
		return scene->StartScene();
	}
};