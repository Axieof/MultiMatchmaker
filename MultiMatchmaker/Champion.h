// Champion.h : This file contains the header information for the champion class structure
// Done by Caleb & Pritheev
// DSA Assignment
// School Project for Ngee Ann Polytechnic
// School of ICT
// Credit if any parts of the code are used

#pragma once
#include <string>
using namespace std;

class Champion {
private:
	string Type;
	int Attack;
	int Hp;
	int Heal;
	int Mobility;
	int Range;
	int Id;

public:
	Champion();
	Champion(string type, int attack, int hp, int Heal, int mobility, int range);

	string getType();
	int getAttack();
	int getHp();
	int getHeal();
	int getMobility();
	int getRange();
	int getId();

	void print();
};