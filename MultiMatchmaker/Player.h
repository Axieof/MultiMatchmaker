// Player.h : This file contains the header information for the player class structure
// Done by Caleb & Pritheev
// DSA Assignment
// School Project for Ngee Ann Polytechnic
// School of ICT
// Credit if any parts of the code are used

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

		void setMatchCount(int _mathcount);

		void setMatchWon(int _matchwon);

		void setMatchLoss(int _matchloss);

		void print();
};

