#ifndef CELL_H
#define CELL_H
#include <iostream>
enum CellState {
	wall = 'W',
	tunnel = 'T',
	pass = 'P'
};
class Cell {
private:
	CellState state;

public:
	Cell() {
		state = wall;
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
