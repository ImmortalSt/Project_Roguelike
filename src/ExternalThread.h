#pragma once
#include "components/Events/ButtonClickEvent.h"

int EventsObservebleThreadFunction(ButtonClickEvent onClickEvent) {
	while (1) {
		auto button = _getch();
		onClickEvent.Notice(button);
	}
}