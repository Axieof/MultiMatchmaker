#pragma once
#include<string>
#include<iostream>
using namespace std;

class Player
{
	public:
		string username;
		int matchcount;
		int matchwon;
		int matchloss;
		float winrate;
		int skilllevel;

		Player();

		Player(string _username, int _matchcount, int _matchwon, int _matchloss, float _winrate, int _skilllevel);

		~Player();

		string getUsername();

		int getmatchCount();

		int getMatchWon();

		int getMatchLoss();

		float getwinRate();

		int getskillLevel();

		void setWinRate(float _winRate);

		void print();
};

