#pragma once
#include<string>
#include<iostream>
#include "Champion.h"
#include "Player.h"
#include "PlayerChampion.h"
using namespace std;

class List
{
private:
	struct Node
	{
		PlayerChampion pc;
		Node* next;
	};

	Node* firstNode;
	int size;

public:
	List();

	~List();

	bool add(PlayerChampion);

	void remove(int);

	PlayerChampion get(int);

	bool isEmpty();

	int getLength();

	void print();

	bool playerInQueue(Player);

	int getPlayerQueueIndex(Player);

	int searchNext(Champion champion);
};

