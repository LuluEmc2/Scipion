#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

#include "Reading.hpp"

int file_lines(ifstream* file)
{
    string s;
    int i = 0;
    while(getline(*file, s))
    {
        i++;
    }

    (*file).clear();
    (*file).seekg(0, ios::beg);
    return i;
}

string random_line(string file_path)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    ifstream file(file_path);

    if(file)
    {
        string line = "";
        uniform_int_distribution<int> distrib {1, file_lines(&file)};
        int rndLine = distrib(rand_eng);
        for(int i = 0; i < rndLine; i++)
        {
            getline(file, line);
        }
        return line;
    }
    else
    {
        return "";
    }
}
