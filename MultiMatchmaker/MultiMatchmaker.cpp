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
#include "Colours.h"
using namespace std;

void readPlayersFromFile(string file_name, Dictionary &players)
{
    ifstream file;
    file.open(file_name);

    string name, matchCount, matchesWon, matchesLoss, winRate, skillLevel;
    int count = 0;

    while (getline(file, name, ','))
    {
        count += 1;
        getline(file, matchCount, ',');
        getline(file, matchesWon, ',');
        getline(file, matchesLoss, ',');
        getline(file, winRate, ',');
        getline(file, skillLevel);

        if (count > 1)
        {
            int MatchCount = stol(matchCount);
            int MatchesWon = stol(matchesWon);
            int MatchesLoss = stol(matchesLoss);
            int WinRate = stol(winRate);
            int SkillLevel = stol(skillLevel);

            cout << "Name: " << name << endl;
            cout << "MatchCount: " << MatchCount << endl;
            cout << "MatchesWon: " << MatchesWon << endl;
            cout << "MatchesLoss: " << MatchesLoss << endl;
            cout << "WinRate: " << WinRate << endl;
            cout << "SkillLevel: " << SkillLevel << endl;

            Player temp = Player(name, MatchCount, MatchesWon, MatchesLoss, WinRate, SkillLevel);
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

void getChampionSelection(vector<Champion> championList, Champion& selectedChampion) {
    cout << BOLDYELLOW << "---------------- Select a Champion ----------------" << WHITE << endl;
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


    cout << "Select champion [1-7]: ";
    int index;
    cin >> index;
    while (!(index >= 1 && index <= 7)) {
        cout << BOLDRED << "Invalid input! Please try again!" << RESET << endl;
        cout << "Select champion [1-7]: ";
        cin >> index;
    }
    selectedChampion = championList[index - 1];
    cout << BOLDGREEN << "You have selected: " << selectedChampion.getType() << RESET << endl;
}

int main()
{
    Dictionary players;
    readPlayersFromFile("../Players.csv", players);

    cout << "--------------------------" << endl << endl;

    vector<Champion> championList = initChampions("../Champions.csv");

    Champion selectedChampion;
    getChampionSelection(championList, selectedChampion);
    
    selectedChampion.print();
    
    return 0;
}
