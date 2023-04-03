#pragma once
#include "Scene.h"
#include "../Screen/display.h"
#include "../utills/utils.h"

class RunnerScene : Scene
{
public:


	int StartScene(Map map) override {
		Display* _display = Display::getDisplay();
		FrameComponent fieldComponent;
		std::vector<FrameComponent*> components;
		components.push_back(&fieldComponent);

		fieldComponent.x = 0;
		fieldComponent.y = 35;
		while (true)
		{
			if (GetAsyncKeyState('w')) map.MovePlayer('u');
			else if (GetAsyncKeyState('a')) map.MovePlayer('a');
			else if (GetAsyncKeyState('s')) map.MovePlayer('d');
			else if (GetAsyncKeyState('d')) map.MovePlayer('r');

			fieldComponent.lines = RebuildFieldInStrings(map.GetField());

			_display->printFrame(FrameNames::Main, components);

			Sleep(500);
		}
	}

};
