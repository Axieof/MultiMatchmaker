// MultiMatchmaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Done by Caleb & Pritheev
// DSA Assignment

// Imports
#include <iostream>
#include <string>
#include <fstream> // read and write to files
#include <vector> // store the string
#include <sstream>// stringstream
using namespace std;

vector<string> readRecordFromFile(string file_name)
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

    return record;
}


int main()
{
    vector<string> Champion = readRecordFromFile("../Champions.csv");

    return 0;
}
