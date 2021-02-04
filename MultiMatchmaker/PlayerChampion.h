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
};

