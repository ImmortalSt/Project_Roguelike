#include "utils.h"

std::wstring repeat(std::wstring a, unsigned int b)
{
    std::wstring output = L"";
    while (b--) {
        output += a;
    }
    return output;
}

void Clear()
{
#ifdef _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

void FillSquare(Field* _field, int h1, int w1, int h2, int w2, CellState _state) {

	if ((h1 > h2) || (w1 > w2)) {
		throw "Error! Incorrect values! The First Two are the Upper Left corner; The Second Two are the Lower Left corner!";
	}

	if ((h1 > _field->GetHeight() || h2 > _field->GetHeight()) || (w1 > _field->GetWidth() || w2 > _field->GetWidth())) {
		throw "You set Incorrect values! One of values is higher than limit of the Field";
	}

	if (h1 < 0 || h2 < 0 || w1 < 0 || w2 < 0) {
		throw "All values must be 0 or higher";
	}

	for (int i = h1; i <= h2; i++) {
		for (int j = w1; j <= w2; j++) {
			_field->SetCell(i, j, _state);
		}
	}
};

Field GetTestField() {
	Field _field = Field(7, 12);
	FillSquare(&_field, 0, 0, 6, 11, wall);
	FillSquare(&_field, 1, 1, 5, 10, pass);
	_field.SetCell(2, 2, player);
	_field.SetCell(2, 8, enemy);
	_field.SetCell(4, 8, shop);
	return _field;
};

void PrintField(Field _field) {
	for (int i = 0; i < _field.GetHeight(); i++) {
		for (int j = 0; j < _field.GetWidth(); j++) {
			std::cout << _field.GetCellChar(i, j);
		}
		std::cout << std::endl;
	}
};

vector<string> RebuildFieldInStrings(Field _field) {
	vector<string> field;
	field.resize(_field.GetHeight());
	for (int i = 0; i < _field.GetHeight(); i++) {
		for (int j = 0; j < _field.GetWidth(); j++) {
			field[i] += _field.GetCellChar(i, j);
		}
	}
	return field;
};

void PrintFieldInStrings(vector<string> _field) {
	for (int i = 0; i < _field.size(); i++) {
		cout << _field[i] << std::endl;
	}
};