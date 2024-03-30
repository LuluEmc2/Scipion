#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

#include "Funcs.hpp"
#include "Obj/Device.hpp"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    Device current_device = Device();

    while(current_device.get_ip() != "0")
    {
        current_device = func(current_device);
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return 0;
}