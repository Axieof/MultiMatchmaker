#pragma once
#include<string>
#include<iostream>
#include "Champion.h"
#include "Player.h"
#include "PlayerChampion.h"
using namespace std;

class Web
{
private:
	struct Node
	{
		PlayerChampion pc;
		Node* next;
		Node* nextChampPlayer;
	};

	Node* firstNode;
	int size;
	Node* lastPlayerChampionIndex[7];


public:

	Web();

	~Web();

	bool add(PlayerChampion &playerChampion);

	void remove(int);

	bool isEmpty();

	string returnLastArray(int index);

	int getLength();

	void print();

	bool playerInQueue(Player);

	int getPlayerQueueIndex(Player);

	int searchNext(Champion);

};

