#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <filesystem>
#include <Windows.h>
#include <vector>
#include <string>
#include "../Field/Field.h"
#if defined(_WIN32) || defined(__CYGWIN__)
#include <conio.h>
#elif defined(__linux__)
#include <stdio.h>
#include <stdlib.h>
#endif

using namespace std;


std::wstring repeat(std::wstring a, unsigned int b);

void Clear();

void FillSquare(Field* _field, int h1, int w1, int h2, int w2, CellState _state);

Field GetTestField();

void PrintField(Field* _field);

vector<wstring> RebuildFieldInStrings(Field* _field);

void PrintFieldInStrings(vector<string> _field);

const int* Massive_of_rand_l();

const int* Massive_of_rand_h();

Field* Make_border(const int* arr_h, const int* arr_l);

int* rand_arr(const int a);

char _getchar();

#endif