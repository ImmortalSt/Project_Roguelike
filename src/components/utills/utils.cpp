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

	if ((h1 >= _field->GetHeight() || h2 >= _field->GetHeight()) || (w1 >= _field->GetWidth() || w2 >= _field->GetWidth())) {
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

const int* Massive_of_rand_l() {
	int l1 = 10 + rand() % 11;
	int l2 = 20 + rand() % 21;
	int l3 = 25 + rand() % 50;
	int l4 = 134 - (l1 + l2 + l3);
	int* arr = new int[4];
	arr[0] = l1;
	arr[1] = l2;
	arr[2] = l3;
	arr[3] = l4;
	if ((l1 + l2 + l3 + l4) == 134) {
		return arr;
	}
	else {
		std::cout << "Oops! Some error in function \"Massive_of_rand_l\"" << std::endl;
	}
}

const int* Massive_of_rand_h() {
	int h1 = 5 + rand() % 3;
	int h2 = 4 + rand() % 5;
	int h3 = 22 - h1 - h2;
	int* arr = new int[3];
	arr[0] = h1;
	arr[1] = h2;
	arr[2] = h3;
	if (h1 + h2 + h3 == 22) {
		return arr;
	}
	else {
		std::cout << "Oops! Some error in function \"Massive_of_rand_h\"" << std::endl;
		return arr;
	}
}

Field* Make_border(const int* arr_h, const int* arr_l) {
	int a = 0, b = 0;
	for (int i = 0; i < 4; i++)
		a += arr_l[i];
	for (int i = 0; i < 3; i++)
		b += arr_h[i];
	Field* mafield = new Field(b, a);
	return mafield;
}

int* rand_arr(const int a) {
	int* arr = new int[a];
	arr[0] = 1 + rand() % 12;
	for (int i = 0; i < a + 1; i++) {
		arr[i + 1] = 1 + rand() % 12;
		if (arr[i + 1] != arr[i]) {

		}
		else {
			i = 0;
		}

	}
	return arr;
}
