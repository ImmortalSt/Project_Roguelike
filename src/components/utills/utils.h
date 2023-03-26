#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <filesystem>
#include <Windows.h>
#include <vector>
#include <string>
#include "../Field/Field.h"
using namespace std;

std::wstring repeat(std::wstring a, unsigned int b);

void Clear();

void FillSquare(Field* _field, int h1, int w1, int h2, int w2, CellState _state);

Field GetTestField();

void PrintField(Field _field);

vector<string> RebuildFieldInStrings(Field _field);

void PrintFieldInStrings(vector<string> _field);

#endif