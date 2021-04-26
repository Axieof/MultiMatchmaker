// List.h : This file contains the header information for the linked list data structure
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

	int searchNext(Champion);
};

