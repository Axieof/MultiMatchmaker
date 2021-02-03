#pragma once
#include <string>
using namespace std;

class Champion {
private:
	string Type;
	int Attack;
	int Hp;
	int Healing;
	int Mobility;
	int Range;

public:
	Champion(string type, int attack, int hp, int healing, int mobility, int range);

	string getType();
	int getAttack();
	int getHp();
	int getHealing();
	int getMobility();
	int getRange();
};