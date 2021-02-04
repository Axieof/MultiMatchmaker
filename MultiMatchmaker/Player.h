#pragma once
#include<string>
#include<iostream>
using namespace std;

class Player
{
	public:
		string username;
		int matchcount;
		int winrate;
		int skilllevel;

		Player();

		Player(string _username, int _matchcount, int _winrate, int _skilllevel);

		~Player();

		string getUsername();

		int getmatchCount();

		int getwinRate();

		int getskillLevel();

		void print();
};

