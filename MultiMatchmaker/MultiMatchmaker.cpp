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
#include "Player.h"
using namespace std;

void readPlayersFromFile(string file_name, Dictionary &players)
{
    ifstream file;
    file.open(file_name);

    string name, matchCount, winRate, skillLevel;
    int count = 0;

    while (getline(file, name, ','))
    {
        count += 1;
        getline(file, matchCount, ',');
        getline(file, winRate, ',');
        getline(file, skillLevel);

        if (count > 1)
        {
            int MatchCount = stol(matchCount);
            int WinRate = stol(winRate);
            int SkillLevel = stol(skillLevel);

            cout << "Name: " << name << endl;
            cout << "MatchCount: " << MatchCount << endl;
            cout << "WinRate: " << WinRate << endl;
            cout << "SkillLevel: " << SkillLevel << endl;

            Player temp = Player(name, MatchCount, WinRate, SkillLevel);
            players.add(name, temp);
        }
    }
    file.close();
}


int main()
{
    Dictionary players;
    readPlayersFromFile("../Players.csv", players);

    players.print();

    return 0;
}
