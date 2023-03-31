#pragma once
#include "IEvent.h"
#include "IAction.h"

class ButtonClickEvent : IEvent<char> {
private:
	std::list<IAction<char>*>* _functions;
public:
	ButtonClickEvent() {
		_functions = new std::list<IAction<char>*>();
	}

	void Register(IAction<char>* action) override {
		_functions->push_back(action);
	}
	void UnRegister(IAction<char>* action) override {
		_functions->remove(action);
	}
	void Notice(char button) override {
		auto iterator = _functions->begin();
		while (iterator != _functions->end()) {
			(*iterator)->OnAction(button);
			iterator++;
		}
	}
};