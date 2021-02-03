#include "Player.h"
using namespace std;

Player::Player()
{

}

Player::Player(string _username, int _matchcount, int _winrate, int _skilllevel)
{
	username = _username;
	matchcount = _matchcount;
	winrate = _winrate;
	skilllevel = _skilllevel;
}

Player::~Player()
{

}

string Player::getUsername()
{
	return username;
}

int Player::getmatchCount()
{
	return matchcount;
}

int Player::getwinRate()
{
	return winrate;
}

int Player::getskillLevel()
{
	return skilllevel;
}
