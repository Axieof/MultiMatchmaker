// MultiMatchmaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Done by Caleb & Pritheev
// DSA Assignment

// Imports
#include <iostream>
#include <string>
#include <fstream> // read and write to files
#include <vector> // store the string
#include <sstream>// stringstream
#include "Dictionary.h"
using namespace std;

vector<string> readPlayersFromFile(string file_name)
{
    vector<string> record;

    ifstream file;
    file.open(file_name);

    string name, matchCount, winRate, skillLevel;

    while (getline(file, name))
    {
        getline(file, matchCount);
        getline(file, winRate);
        getline(file, skillLevel);

        cout << name << endl;
        cout << matchCount << endl;
        cout << winRate << endl;
        cout << skillLevel << endl;
    }

    file.close();

    return record;
}


int main()
{
    Dictionary players;

    vector<string> Champion = readPlayersFromFile("../Players.csv");

    return 0;
}
