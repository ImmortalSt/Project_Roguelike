#ifndef CELL_H
#define CELL_H
#include <iostream>
enum CellState {
	wall = 'W',
	tunnel = '`',
	pass = '.',
	player = '@',
	enemy = 'E',
	enemy_dead = 'Ш',
	shop = 'S',
	emptyC = ' '
};
class Cell {
private:
	CellState state;

public:
	Cell() {
		state = CellState::emptyC;
	}

	CellState GetState() {
		return state;
	}

	void SetState(CellState _state) {
		state = _state;
	}

	char GetChar() {
		return state;
	}
};

#endif
