// PlayerChampion.h : This file contains the header information for the PlayerChampion class structure
// Done by Caleb & Pritheev
// DSA Assignment
// School Project for Ngee Ann Polytechnic
// School of ICT
// Credit if any parts of the code are used

#pragma once
#include "Player.h"
#include "Champion.h"

class PlayerChampion
{
	public:
		Player player;
		Champion champion;

		PlayerChampion();
		PlayerChampion(Player p, Champion c);

		Player getPlayer();
};

