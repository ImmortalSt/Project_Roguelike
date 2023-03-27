#ifndef FIELD_H
#define FIELD_H
#include <iostream>
#include <vector>
#include "Cell.h"

class Field {
private:
	int width;
	int height;
	std::vector<std::vector<Cell>> field;
public:
	Field(int _height, int _width) {
		width = _width;
		height = _height;
		field.resize(height);
		for (int i = 0; i < height; i++) {
			field[i].resize(width);
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				field[i][j] = Cell();
			}
		}
	}


	void SetCell(int h, int w, CellState _state) {
		field[h][w].SetState(_state);
	}

	char GetCellChar(int h, int w) {
		return field[h][w].GetChar();
	}

	CellState GetCellState(int h, int w) {
		return field[h][w].GetState();
	}

	int GetHeight() {
		return height;
	}

	int GetWidth() {
		return width;
	}
};

#endif


