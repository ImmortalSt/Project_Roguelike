#pragma once
#include "../Map/Map.h"
#include "../Screen/display.h"

class Scene {
public:
	Assets* AssetsInstance = Assets::GetInstance();
	virtual int StartScene() = 0;

};