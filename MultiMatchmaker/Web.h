// Web.h : This file contains the header information for the web data structure
// Done by Caleb & Pritheev
// DSA Assignment
// School Project for Ngee Ann Polytechnic
// School of ICT
// Credit if any parts of the code are used

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

