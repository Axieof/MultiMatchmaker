// PlayerChampion.cpp : This file contains the class structure for combining player and champion
// Done by Caleb & Pritheev
// DSA Assignment
// School Project for Ngee Ann Polytechnic
// School of ICT
// Credit if any parts of the code are used

#include "PlayerChampion.h"
#include "Player.h"
#include "Champion.h"

PlayerChampion::PlayerChampion() {}
PlayerChampion::PlayerChampion(Player p, Champion c) {
	player = p;
	champion = c;
}

Player PlayerChampion::getPlayer()
{
	return player;
}

