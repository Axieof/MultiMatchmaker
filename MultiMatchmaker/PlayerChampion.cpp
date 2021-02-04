#include "PlayerChampion.h"
#include "Player.h"
#include "Champion.h"

PlayerChampion::PlayerChampion() {}
PlayerChampion::PlayerChampion(Player p, Champion c) {
	player = p;
	champion = c;
}

