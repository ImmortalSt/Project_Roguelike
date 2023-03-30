#pragma once
#include "IAction.h"

class OnButtonClickHandler : IAction<char> {
	virtual void OnButtonClick(char button) = 0;

	void OnAction(char button) {
		OnButtonClick(button);
	}

};