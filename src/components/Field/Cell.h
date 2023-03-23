#ifndef CELL_H
#define CELL_H
#include <iostream>

class Cell {
private:
	char symbol;

public:
	Cell() {

	}
	Cell(char _symbol) {
		symbol = _symbol;
	}

	char GetSymbol() {
		return symbol;
	}

	void SetSymbol(char _symbol) {
		symbol = _symbol;
	}
};

#endif
