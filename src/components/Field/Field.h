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
	Field(int _width, int _height) {
		width = _width;
		height = _height;
		field.resize(height);
		for (int i = 0; i < height; i++) {
			field[i].resize(width);
		}
	}

	void SetCell(int h, int w, char c) {
		field[h][w].SetSymbol(c);
	}

	char GetCell(int h, int w) {
		return field[h][w].GetSymbol();
	}
	void PrintField() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::cout << field[i][j].GetSymbol() << "\t";
			}
			std::cout << std::endl;
		}
	}
};

#endif


