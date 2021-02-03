#include <string>
#include "Champion.h"
using namespace std;

Champion::Champion(string tp, int at, int hp, int hl, int mb, int rn) {
	Type = tp;
	Attack = at;
	Hp = hp;
	Healing = hl;
	Mobility = mb;
	Range = rn;
}

string Champion::getType() { return Type; }
int Champion::getAttack() { return Attack; }
int Champion::getHp() { return Hp; }
int Champion::getHealing() { return Healing; }
int Champion::getMobility() { return Mobility; }
int Champion::getRange() { return Range; }


