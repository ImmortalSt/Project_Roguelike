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
	Field GetTestField() {
		Field pole = Field(7, 12);
		pole.FillSquare(0, 0, 6, 11, wall);
		pole.FillSquare(1, 1, 5, 10, pass);
		pole.SetCell(2, 2, player);
		pole.SetCell(2, 8, enemy);
		pole.SetCell(4, 8, shop);
		return pole;

	}
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
		field[h][w].GetChar();
	}

	CellState GetCellState(int h, int w) {
		field[h][w].GetState();
	}

	void PrintField() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::cout << field[i][j].GetChar();
			}
			std::cout << std::endl;
		}
	}

	void FillSquare(int h1, int w1, int h2, int w2, CellState _state) {

		if ((h1 > h2) || (w1 > w2)) {
			throw "Error! Incorrect values! The First Two are the Upper Left corner; The Second Two are the Lower Left corner!";
		}

		if ((h1 > height || h2 > height) || (w1 > width || w2 > width)) {
			throw "You set Incorrect values! One of values is higher than limit of the Field";
		}
		if (h1 < 0 || h2 < 0 || w1 < 0 || w2 < 0) {
			throw "All values must be 0 or higher";
		}

		for (int i = h1; i <= h2; i++) {
			for (int j = w1; j <= w2; j++) {
				field[i][j].SetState(_state);
			}
		}
	}
};

#endif


