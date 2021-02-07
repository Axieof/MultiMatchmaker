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

	PlayerChampion get(int);

	bool isEmpty();

	string returnLastArray(int index);

	int getLength();

	void print();

	void printChain(Champion champion);

	bool playerInQueue(Player);

	int getPlayerQueueIndex(Player);

	Player searchNext(Champion);

};

