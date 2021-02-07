#include <iostream>
#include <string>
#include "Champion.h"
using namespace std;

Champion::Champion() {}
Champion::Champion(string tp, int at, int hp, int hl, int mb, int rn) {
	Type = tp;
	Attack = at;
	Hp = hp;
	Heal = hl;
	Mobility = mb;
	Range = rn;

	if (Type == "Assassin")
	{
		Id = 0;
	}
	else if (Type == "Fighter")
	{
		Id = 1;
	}
	else if (Type == "Enchanter")
	{
		Id = 2;
	}
	else if (Type == "Mage")
	{
		Id = 3;
	}
	else if (Type == "Marksman")
	{
		Id = 4;
	}
	else if (Type == "Support")
	{
		Id = 5;
	}
	else if (Type == "Tank")
	{
		Id = 6;
	}
}

string Champion::getType() { return Type; }
int Champion::getAttack() { return Attack; }
int Champion::getHp() { return Hp; }
int Champion::getHeal() { return Heal; }
int Champion::getMobility() { return Mobility; }
int Champion::getRange() { return Range; }
int Champion::getId() { return Id; }

void Champion::print() {
	cout << "Type: " << Type << endl;
	cout << "Attack: " << Attack << endl;
	cout << "HP: " << Hp << endl;
	cout << "Heal: " << Heal << endl;
	cout << "Mobility: " << Mobility << endl;
	cout << "Range: " << Range << endl;
}

