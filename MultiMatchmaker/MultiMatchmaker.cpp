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
#include "List.h"
#include "Dictionary.h"
#include "Champion.h"
#include "Player.h"
#include "PlayerChampion.h"
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

            //cout << "Name: " << name << endl;
            //cout << "MatchCount: " << MatchCount << endl;
            //cout << "MatchesWon: " << MatchesWon << endl;
            //cout << "MatchesLoss: " << MatchesLoss << endl;
            //cout << "WinRate: " << WinRate << endl;
            //cout << "SkillLevel: " << SkillLevel << endl;

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

Champion getChampionSelection(vector<Champion> championList) {
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
    Champion selectedChampion = championList[index - 1];
    cout << BOLDGREEN << "\nYou have selected: " << selectedChampion.getType() << RESET << endl << endl;
    return selectedChampion;
}

int MainMenu()
{
    int option;
    cout << BOLDYELLOW << "----------------- Welcome Player! -----------------" << WHITE << endl << endl;
    cout << "1) Create an Account" << endl;
    cout << "2) Select an Account" << endl;
    cout << "3) Get Player Stats" << endl;
    cout << "4) Join Queue" << endl;
    cout << "5) Queue Status" << endl;
    cout << "6) Leave Queue" << endl;
    cout << "0) Leave Game" << endl << endl;

    cout << "Enter an option: ";
    cin >> option;
    cout << "" << endl;
    return option;
}

Player CreateAccount(Dictionary &players)
{
    string username;
    cout << BOLDYELLOW << "----------------- Create a new Account -----------------" << WHITE << endl << endl;

    cout << "Enter username: ";
    cin >> username;

    Player newPlayer = Player(username, 0, 0, 0, 0, 0);
    players.add(username, newPlayer);
    cout << "\nNew Account Created Successfully!" << endl << endl;
    return newPlayer;
}

Player SelectAccount(Dictionary &players)
{
    string selected;
    cout << BOLDYELLOW << "---------------- Select an Account ----------------" << WHITE << endl;
    cout << right << setw(2) << "#" << " |" << left << setw(15) << "Username" << "|" << left << setw(13) << "Match Count" << "|" << left << setw(4) << "Won" << "|" << left << setw(5) << "Loss" << "|" << left << setw(9) << "Win Rate" << "|" << left << setw(13) << "Skill Level" << endl;
    cout << "---|---------------|-------------|----|-----|---------|------" << endl;
    players.printPlayers();

    cout << "\nSelect an account name: ";
    cin >> selected;

    Player selectedPlayer = players.get(selected);
    return selectedPlayer;
}



int main()
{
    //Initializations
    Dictionary players;
    Player currentPlayer;
    List playerQueue;
    bool continueLoop = true;
    bool accountSelected = false;

    //Reading CSV Data
    readPlayersFromFile("../Players.csv", players);
    vector<Champion> championList = initChampions("../Champions.csv");

    //Calling Main Menu Option
    while (continueLoop)
    {
        int option = MainMenu();

        if (option == 0)
        {
            //Exit Game
            continueLoop = false;
        }
        else if (option == 1)
        {
            // Create a new account
            currentPlayer = CreateAccount(players);
            accountSelected = true;
        }
        else if (option == 2)
        {
            // Select an account
            currentPlayer = SelectAccount(players);
            accountSelected = true;
        }
        else if (option == 3)
        {
            // Get player stats

            if (accountSelected)
            {
                cout << BOLDYELLOW << "---------------- Player stats ----------------" << WHITE << endl << endl;
                currentPlayer.print();
                cout << "" << endl;
                continue;
            }
            else
            {
                cout << RED << "No account selected! Use option |1| to create a new account or option |2| to select one!" << RESET << endl << endl;
                continue;
            }
        }
        else if (option == 4)
        {
            // Join Queue

            if (accountSelected)
            {
                if (playerQueue.playerInQueue(currentPlayer)) {
                    cout << RED << "Player is already in queue!" << RESET << endl;
                }
                else {
                    Champion selectedChampion = getChampionSelection(championList);
                    playerQueue.add(PlayerChampion(currentPlayer, selectedChampion));
                    cout << GREEN << currentPlayer.getUsername() << " has joined the queue with " << selectedChampion.getType() << RESET << endl;
                }
            }
        }
        else if (option == 5)
        {
            // Queue status

            cout << "Number of players in queue: " << playerQueue.getLength() << endl;
            playerQueue.print();
            
        }
        else if (option == 6)
        {

        }
        else if (option == 7)
        {

        }
    }
    return 0;
}
