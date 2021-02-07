#include "Player.h"
using namespace std;

Player::Player()
{
}

Player::Player(string _username, int _matchcount, int _matchwon, int _matchloss, float _winrate, int _skilllevel)
{
	username = _username;
	matchcount = _matchcount;
	matchloss = _matchloss;
	matchwon = _matchwon;
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

int Player::getMatchWon()
{
	return matchwon;
}

int Player::getMatchLoss()
{
	return matchloss;
}

float Player::getwinRate()
{
	return winrate;
}

int Player::getskillLevel()
{
	return skilllevel;
}

void Player::print() {
	cout << "Username: " << username << endl;
	cout << "Match Count: " << matchcount << endl;
	cout << "Match Won: " << matchwon << endl;
	cout << "Match Loss: " << matchloss << endl;
	cout << "Win Rate: " << winrate << "%" << endl;
	cout << "Skill Level: " << skilllevel << endl;
}

void Player::setWinRate(float _winRate)
{
	winrate = _winRate;
}
