#pragma once
#include "../Map/Map.h"

enum SceneState {
	ToShop
};

class Scene {
public:
	virtual int StartScene() = 0;

};