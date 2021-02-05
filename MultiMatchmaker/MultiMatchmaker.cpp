// MultiMatchmaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Done by Caleb & Pritheev
// DSA Assignment

// Imports
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // read and write to files
#include <vector> // store the string
#include <sstream>// stringstream
#include <stdio.h>
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

void displayChampionSelection(vector<Champion> championList) {
    cout << "\033[33m" << "---------------- Select a Champion ----------------" << "\033[0m" << endl;
    cout << right << setw(2) << "#" << " |" << left << setw(10) << "Type" << "|" << left << setw(7) << "Attack" << "|" << left << setw(5) << "Hp" << "|" << left << setw(5) << "Heal" << "|" << left << setw(9) << "Mobility" << "|" << left << setw(6) << "Range" << endl;
    cout << "---|----------|-------|-----|-----|---------|------" << endl;

    for (int i = 0; i < championList.size(); i++) {
        
        cout << right << setw(2) << i + 1 << " |";
        cout << left << setw(10) << championList[i].getType() << "|";
        cout << left << setw(7) << championList[i].getAttack() << "|";
        cout << left << setw(5) << championList[i].getHp() << "|";
        cout << left << setw(5) << championList[i].getHeal() << "|";
        cout << left << setw(9) << championList[i].getMobility() << "|";
        cout << left << setw(6) << championList[i].getRange() << endl;
        
    }
}

int main()
{
    Dictionary players;
    readPlayersFromFile("../Players.csv", players);

    cout << "--------------------------" << endl << endl;

    vector<Champion> championList = initChampions("../Champions.csv");

    displayChampionSelection(championList);
    
    
    /*for (int i = 0; i < championList.size(); i++)
    {
        championList[i].print();
        cout << "--------------------" << endl;
    }*/

    return 0;
}
