#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

#include "Style.hpp"

void rotating_loading_bar(int time, int iteration)
{
    for(int i = 0; i < iteration; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(time));
        cout << "/";
        cout << "\b";
    
        this_thread::sleep_for(chrono::milliseconds(time));
        cout << "|";
        cout << "\b";
    
        this_thread::sleep_for(chrono::milliseconds(time));
        cout << "\\";
        cout << "\b";
    
        this_thread::sleep_for(chrono::milliseconds(time));
        cout << "-";
        cout << "\b";
    }
    
    this_thread::sleep_for(chrono::milliseconds(time));
    cout << " \n";
}

void progressing_loading_bar(int time, int iteration)
{
    cout << "[";
    for(int i = 0; i < iteration; i++)
    {
        cout << " ";
    }
    cout << "]";
    for(int i = 0; i < iteration+1; i++)
    {
        cout << "\b";
    }

    for(int i = 0; i < iteration; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(time));
        cout << "=";
    }

    cout << "]\n";
}
