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
#include "Champion.h"
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

vector<Champion> initChampions(string file_name)
{
    vector<Champion> champions;

    ifstream file;
    file.open(file_name);

    string type, attack, hp, healing, mobility, range;

    string header;
    getline(file, header);
    for (int i = 0; i < 7; i++)
    {
        getline(file, type, ',');
        getline(file, attack, ',');
        getline(file, hp, ',');
        getline(file, healing, ',');
        getline(file, mobility, ',');
        getline(file, range);
        
        Champion c = Champion(type, stoi(attack), stoi(hp), stoi(healing), stoi(mobility), stoi(range));
       
        champions.push_back(c);
    }
    file.close();

    return champions;
}


int main()
{
    Dictionary players;
    readPlayersFromFile("../Players.csv", players);

    vector<Champion> championList = initChampions("../Champions.csv");

    for (int i = 0; i < championList.size(); i++)
    {
        cout << championList[i].getType() << endl;
        cout << championList[i].getAttack() << endl;
        cout << championList[i].getHp() << endl;
        cout << championList[i].getHealing() << endl;
        cout << championList[i].getMobility() << endl;
        cout << championList[i].getRange() << endl;
        cout << "------------------------------" << endl;
    }

    return 0;
}
