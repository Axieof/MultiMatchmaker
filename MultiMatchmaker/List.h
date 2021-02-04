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

	void remove(int index);

	PlayerChampion get(int index);

	bool isEmpty();

	int getLength();

	void print();

	//PlayerChampion searchNext(Champion champion);
};

