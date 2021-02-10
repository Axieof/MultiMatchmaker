// MultiMatchmaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Done by Caleb & Pritheev
// DSA Assignment

// Imports
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // read and write to files
#include <vector> // store the string
#include <sstream> // stringstream
#include <stdio.h>
#include "List.h"
#include "Dictionary.h"
#include "Champion.h"
#include "Player.h"
#include "PlayerChampion.h"
#include "Colours.h"
#include "Web.h"
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
            float WinRate = stof(winRate);
            int SkillLevel = stol(skillLevel);

            Player temp = Player(name, MatchCount, MatchesWon, MatchesLoss, WinRate, SkillLevel);
            players.add(name, temp);
        }
    }
    file.close();
}

// Read champion data from csv, create Champion objects and add to vector
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

// Display champion stats in tabular format, then prompt user to select champion
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

    cout << "\nSelect champion [1-7]: ";
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

int MainMenu(string username = "Player")
{
    int option;
    cout << BOLDYELLOW << "----------------- Welcome " << username << "! -----------------" << WHITE << endl << endl;
    cout << BOLDGREEN << "Common Functions" << RESET << endl;
    cout << "0) Leave Game" << endl;
    cout << "1) Create an Account" << endl;
    cout << "2) Select an Account" << endl;
    cout << "3) Get Player Stats" << endl << endl;

    cout << BOLDGREEN << "List Functions" << RESET << endl;

    cout << "4) Join Queue" << endl;
    cout << "5) Queue Status" << endl;
    cout << "6) Change Champion" << endl;
    cout << "7) Leave Queue" << endl;
    cout << "8) Initialise List Data" << endl << endl;

    cout << BOLDGREEN "Web Functions" << RESET << endl;

    cout << "9) Join Queue (Web)" << endl;
    cout << "10) Queue Status (Web)" << endl;
    cout << "11) Print Chain" << endl;
    cout << "12) Initialise Web Data" << endl << endl;

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
    bool success = players.add(username, newPlayer);

    if (success)
    {
        cout << BOLDGREEN << "\nNew account created successfully!" << RESET << endl << endl;
    }
    else
    {
        cout << RED << "\nNew account created unsuccessfully!" << RESET << endl << endl;
    }
    
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
    cout << endl;

    Player selectedPlayer = players.get(selected);
    return selectedPlayer;
}

void UpdatePlayer(Player& currentPlayer)
{
    int matcheswon = currentPlayer.getMatchWon();
    int matchCount = currentPlayer.getmatchCount();

    if (matchCount == 0)
    {
        return;
    }
    else
    {
        int newWinRate = matcheswon / matchCount;

        newWinRate *= 100;

        currentPlayer.setWinRate(newWinRate);
    }
}

void Update(int _matchcount, int _matchwon, int _matchloss, Player &player)
{
    player.setMatchCount(_matchcount);
    player.setMatchWon(_matchwon);
    player.setMatchLoss(_matchloss);
}

void RandomMatchResult(Player &p1, Player &p2, Player &p3, Player &p4)
{
    int team1result = rand() % 2;
    int team2result = 1;

    if (team1result == 1)
    {
        team2result = 0;
        cout << "\nTeam 1 won!" << endl;
        cout << "Team 2 loss!" << endl;

        Update(p1.getmatchCount() + 1, p1.getMatchWon() + 1, p1.getMatchLoss(), p1);
        Update(p2.getmatchCount() + 1, p2.getMatchWon() + 1, p2.getMatchLoss(), p2);
        Update(p3.getmatchCount() + 1, p3.getMatchWon(), p3.getMatchLoss() + 1, p3);
        Update(p4.getmatchCount() + 1, p4.getMatchWon(), p4.getMatchLoss() + 1, p4);
    }
    else
    {
        cout << "\nTeam 2 won!" << endl;
        cout << "Team 1 loss!" << endl;

        Update(p1.getmatchCount() + 1, p1.getMatchWon(), p1.getMatchLoss() + 1, p1);
        Update(p2.getmatchCount() + 1, p2.getMatchWon(), p2.getMatchLoss() + 1, p2);
        Update(p3.getmatchCount() + 1, p3.getMatchWon() + 1, p3.getMatchLoss(), p3);
        Update(p4.getmatchCount() + 1, p4.getMatchWon() + 1, p4.getMatchLoss(), p4);
    }

    UpdatePlayer(p1);
    UpdatePlayer(p2);
    UpdatePlayer(p3);
    UpdatePlayer(p4);
}

void matchPlayers(List& playerQueue, vector<PlayerChampion>& team1, vector<PlayerChampion>& team2) {
    playerQueue.print(); //temp

    cout << BOLDMAGENTA << "Attempting to match teams..." << RESET << endl;

    int currentIndex = 0;

    while (true) {
        if (team1.size() == 2) {
            cout << BOLDYELLOW << "TEAM 1" << RESET << endl;
            cout << BOLDCYAN << "Player 1: " << team1[0].player.getUsername() << "\tChampion: " << team1[0].champion.getType() << RESET << endl;
            cout << BOLDCYAN << "Player 2: " << team1[1].player.getUsername() << "\tChampion: " << team1[1].champion.getType() << RESET << endl << endl;
            cout << BOLDYELLOW << "TEAM 2" << RESET << endl;
            cout << BOLDCYAN << "Player 1: " << team2[0].player.getUsername() << "\tChampion: " << team2[0].champion.getType() << RESET << endl;
            cout << BOLDCYAN << "Player 2: " << team2[1].player.getUsername() << "\tChampion: " << team2[1].champion.getType() << RESET << endl << endl;

            /*Player p1 = team1[0].getPlayer();
            Player p2 = team1[1].getPlayer();
            Player p3 = team2[0].getPlayer();
            Player p4 = team2[2].getPlayer();

            RandomMatchResult(p1, p2, p3, p4);*/

            team1.clear();
            team2.clear();
            break;
        }

        PlayerChampion first = playerQueue.get(currentIndex);
        int nextPlayerIndex = playerQueue.searchNext(first.champion);

        // match found
        if (nextPlayerIndex != -1) {
            team1.push_back(playerQueue.get(currentIndex));
            team2.push_back(playerQueue.get(nextPlayerIndex - 1));
            playerQueue.remove(currentIndex);
            playerQueue.remove(nextPlayerIndex - 2);
            currentIndex = 0;
        }
        // no match found
        else {
            currentIndex++;
            if (currentIndex > playerQueue.getLength()) {
                cout << RED << "Matchmaking failed" << RESET << endl << endl;
                break;
            }
        }
    }
}

void webMatchPlayers(Web& web, vector<PlayerChampion>& team1, vector<PlayerChampion>& team2) {
    web.print(); //temp

    cout << BOLDMAGENTA << "Attempting to match teams..." << RESET << endl;

    int currentIndex = 0;

    while (true) {
        if (team1.size() == 2) {
            cout << BOLDYELLOW << "TEAM 1" << RESET << endl;
            cout << BOLDCYAN << "Player 1: " << team1[0].player.getUsername() << "\tChampion: " << team1[0].champion.getType() << RESET << endl;
            cout << BOLDCYAN << "Player 2: " << team1[1].player.getUsername() << "\tChampion: " << team1[1].champion.getType() << RESET << endl << endl;
            cout << BOLDYELLOW << "TEAM 2" << RESET << endl;
            cout << BOLDCYAN << "Player 1: " << team2[0].player.getUsername() << "\tChampion: " << team2[0].champion.getType() << RESET << endl;
            cout << BOLDCYAN << "Player 2: " << team2[1].player.getUsername() << "\tChampion: " << team2[1].champion.getType() << RESET << endl << endl;

            /*Player p1 = team1[0].getPlayer();
            Player p2 = team1[1].getPlayer();
            Player p3 = team2[0].getPlayer();
            Player p4 = team2[1].getPlayer();

            RandomMatchResult(p1, p2, p3, p4);*/

            team1.clear();
            team2.clear();
            break;
        }

        PlayerChampion first = web.get(currentIndex);
        int nextPlayerIndex = web.getPlayerQueueIndex(web.searchNext(first.champion));

        // match found
        if (nextPlayerIndex != -1) {
            team1.push_back(web.get(currentIndex));
            team2.push_back(web.get(nextPlayerIndex - 1));
            web.remove(currentIndex);
            web.remove(nextPlayerIndex - 2);
            currentIndex = 0;
        }
        // no match found
        else {
            currentIndex++;
            if (currentIndex >= web.getLength()) {
                cout << RED << "Matchmaking failed" << RESET << endl;
                break;
            }
        }
    }
}

int main()
{
    //Initializations
    Dictionary players;
    Player currentPlayer;
    List playerQueue;
    Web webPlayerQueue;
    bool continueLoop = true;
    bool accountSelected = false;
    vector<PlayerChampion> team1;
    vector<PlayerChampion> team2;

    //Reading CSV Data
    readPlayersFromFile("../Players.csv", players);
    vector<Champion> championList = initChampions("../Champions.csv");

    //Calling Main Menu Option
    while (continueLoop)
    {
        int option = MainMenu(accountSelected ? currentPlayer.getUsername() : "Player");

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
            }
            else
            {
                cout << RED << "No account selected! Use option |1| to create a new account or option |2| to select one!" << RESET << endl << endl;
            }
        }
        else if (option == 4)
        {
            // Join Queue

            if (accountSelected)
            {
                // Selected player is in player queue
                if (playerQueue.playerInQueue(currentPlayer)) {
                    cout << RED << "Player is already in queue!" << RESET << endl;
                }
                // Selected player is not in player queue (Run champion selection function)
                else {
                    Champion selectedChampion = getChampionSelection(championList);
                    playerQueue.add(PlayerChampion(currentPlayer, selectedChampion));
                    cout << BOLDCYAN << currentPlayer.getUsername() << " has joined the queue with " << selectedChampion.getType() << RESET << endl << endl;

                    cout << BOLDBLUE <<  "--------------- Player Queue ---------------" << endl << endl;
                    matchPlayers(playerQueue, team1, team2);
                }
            }
            else {
                cout << RED << "No account selected! Use option |1| to create a new account or option |2| to select one!" << RESET << endl << endl;
            }
        }
        else if (option == 5)
        {
            // Queue status

            cout << BOLDBLUE << "Number of players in queue: " << playerQueue.getLength() << RESET << endl;

            playerQueue.print();

            if (accountSelected) {
                if (playerQueue.playerInQueue(currentPlayer)) {
                    int queueIndex = playerQueue.getPlayerQueueIndex(currentPlayer);
                    cout << BOLDBLUE << currentPlayer.getUsername() << " is at position " << queueIndex << " in player queue " << RESET << endl << endl;
                }
                else {
                    cout << RED << "Current player is not in queue!" << RESET << endl << endl;
                }
            }
        }
        else if (option == 6)
        {
            // Change champion
            if (accountSelected) {
                if (playerQueue.playerInQueue(currentPlayer)) {
                    cout << RED << "Are you sure you want to change champion? You will leave the queue and be added at the back! [Y/N]: " << RESET;
                    string confirmChange;
                    cin >> confirmChange;

                    if (confirmChange == "Y") {
                        playerQueue.remove(playerQueue.getPlayerQueueIndex(currentPlayer) - 1);
                        Champion selectedChampion = getChampionSelection(championList);
                        playerQueue.add(PlayerChampion(currentPlayer, selectedChampion));
                        cout << BOLDGREEN << currentPlayer.getUsername() << " has joined the queue with " << selectedChampion.getType() << RESET << endl;
                    }
                }
                else {
                    cout << RED << "Current player is not in queue!" << RESET << endl;
                }
            }
            else {
                cout << RED << "No account selected! Use option |1| to create a new account or option |2| to select one!" << RESET << endl << endl;
            }
        }
        else if (option == 7)
        {
            // Leave queue
            if (accountSelected) {
                if (playerQueue.playerInQueue(currentPlayer)) {
                    cout << RED << "Are you sure you want to leave the queue? [Y/N]: " << RESET;
                    string confirmLeave;
                    cin >> confirmLeave;

                    if (confirmLeave == "Y") {
                        playerQueue.remove(playerQueue.getPlayerQueueIndex(currentPlayer) - 1);
                    }
                }
                else {
                    cout << RED << "Current player is not in queue!" << RESET << endl << endl;
                }
            }
            else {
                cout << RED << "No account selected! Use option |1| to create a new account or option |2| to select one!" << RESET << endl << endl;
            }
        }
        else if (option == 8)
        {
            Player p1 = Player("Andy", 0, 0, 0, 0, 0);
            Player p2 = Player("Ben", 0, 0, 0, 0, 0);
            Player p3 = Player("Charlie", 0, 0, 0, 0, 0);
            Player p4 = Player("Delta", 0, 0, 0, 0, 0);
            Player p5 = Player("Eddie", 0, 0, 0, 0, 0);
            playerQueue.add(PlayerChampion(p1, championList[0]));
            playerQueue.add(PlayerChampion(p2, championList[1]));
            playerQueue.add(PlayerChampion(p3, championList[2]));
            playerQueue.add(PlayerChampion(p4, championList[3]));
            playerQueue.add(PlayerChampion(p5, championList[4]));
        }
        else if (option == 9)
        {
            // Join Queue

            if (accountSelected)
            {
                // Selected player is in player queue
                if (webPlayerQueue.playerInQueue(currentPlayer)) {
                    cout << RED << "Player is already in queue!" << RESET << endl;
                }
                // Selected player is not in player queue (Run champion selection function)
                else {
                    Champion selectedChampion = getChampionSelection(championList);
                    PlayerChampion newPC = PlayerChampion(currentPlayer, selectedChampion);
                    webPlayerQueue.add(newPC);
                    cout << BOLDGREEN << currentPlayer.getUsername() << " has joined the queue with " << selectedChampion.getType() << RESET << endl;

                    cout << "-------------------------------------------------" << endl;
                    webMatchPlayers(webPlayerQueue, team1, team2);
                }
            }
            else {
                cout << RED << "No account selected! Use option |1| to create a new account or option |2| to select one!" << RESET << endl << endl;
            }
        }
        else if (option == 10)
        {
            // Queue status for web

            cout << BOLDBLUE << "Number of players in web queue: " << webPlayerQueue.getLength() << RESET << endl;

            webPlayerQueue.print();

            if (accountSelected) {
                if (webPlayerQueue.playerInQueue(currentPlayer)) {
                    int queueIndex = webPlayerQueue.getPlayerQueueIndex(currentPlayer);
                    cout << BOLDBLUE << currentPlayer.getUsername() << " is at position " << queueIndex << " in player queue " << RESET << endl << endl;
                }
                else {
                    cout << RED << "Current player is not in queue!" << RESET << endl << endl;
                }
            }
		}
        else if (option == 11)
        {
            Champion champion = getChampionSelection(championList);
            webPlayerQueue.printChain(champion);
        }
        else if (option == 12)
        {
            Player p1 = Player("Alice", 0, 0, 0, 0, 0);
            PlayerChampion pc = PlayerChampion(p1, championList[0]);
            Player p2 = Player("Bob", 0, 0, 0, 0, 0);
            PlayerChampion pc2 = PlayerChampion(p2, championList[1]);
            Player p3 = Player("Carly", 0, 0, 0, 0, 0);
            PlayerChampion pc3 = PlayerChampion(p3, championList[1]);
            Player p4 = Player("Danny", 0, 0, 0, 0, 0);
            PlayerChampion pc4 = PlayerChampion(p4, championList[0]);
            Player p5 = Player("Ethan", 0, 0, 0, 0, 0);
            PlayerChampion pc5 = PlayerChampion(p5, championList[2]);
            Player p6 = Player("Felix", 0, 0, 0, 0, 0);
            PlayerChampion pc6 = PlayerChampion(p6, championList[0]);
            /*Player p7 = Player("g", 0, 0, 0, 0, 0);
            PlayerChampion pc7 = PlayerChampion(p7, championList[1]);
            Player p8 = Player("h", 0, 0, 0, 0, 0);
            PlayerChampion pc8 = PlayerChampion(p8, championList[2]);*/

            webPlayerQueue.add(pc);
            webPlayerQueue.add(pc2);
            webPlayerQueue.add(pc3);
            webPlayerQueue.add(pc4);
            webPlayerQueue.add(pc5);
            webPlayerQueue.add(pc6);

            /*web.add(pc7);
            web.add(pc8);*/

            webPlayerQueue.print();
		}
    }
    return 0;
}
