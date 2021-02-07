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