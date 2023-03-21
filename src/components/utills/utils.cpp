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
