// Web.cpp : This file contains the data and class structure for the Web data structure
// Done by Caleb & Pritheev
// DSA Assignment
// School Project for Ngee Ann Polytechnic
// School of ICT
// Credit if any parts of the code are used

#include<string>
#include<iostream>
#include "Web.h"

Web::Web() {
	firstNode = NULL;
	size = 0;
	for (int i = 0; i < 7; i++) {
		lastPlayerChampionIndex[i] = NULL;
	}
};

Web::~Web() {
	Node* current = firstNode;
	while (current != NULL) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	firstNode = NULL;
	size = 0;
}

bool Web::add(PlayerChampion &playerchampion) {
	Node* newNode = new Node;
	newNode->pc = playerchampion;
	newNode->next = NULL;
	newNode->nextChampPlayer = NULL;
	Node* current = firstNode;
	if (size == 0) {
		firstNode = newNode;
	}
	else 
	{
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

	int id = newNode->pc.champion.getId();

	if (lastPlayerChampionIndex[id] != NULL)
	{
		lastPlayerChampionIndex[id]->nextChampPlayer = newNode;
	}
	lastPlayerChampionIndex[id] = newNode;
	size++;
	return true;
}

void Web::remove(int index) {
	if (index >= 0 && index < size) {
		if (index == 0) {
			firstNode = firstNode->next;
		}
		else {
			Node* temp = firstNode;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			Node* previous = temp;
			Node* deleteNode = temp->next;

			previous->next = deleteNode->next;

			int id = deleteNode->pc.champion.getId();

			if (deleteNode->nextChampPlayer != NULL)
			{
				lastPlayerChampionIndex[id] = deleteNode->nextChampPlayer;
			}
			else {
				lastPlayerChampionIndex[id] = NULL;
			}
		}
		size--;
	}
}

PlayerChampion Web::get(int index) {
	if (index >= 0 && index < size) {
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->pc;
	}
}

bool Web::isEmpty() {
	return size == 0;
}

string Web::returnLastArray(int index)
{
	Node* temp;
	temp = lastPlayerChampionIndex[index];
	return temp->pc.player.getUsername();
}

int Web::getLength() {
	return size;
}

void Web::print() {
	Node* temp = firstNode;
	while (temp != NULL) {
		cout << temp->pc.player.getUsername() << endl;
		cout << temp->pc.champion.getType() << endl;
		cout << endl;
		temp = temp->next;
	}
	cout << endl << endl;
}

void Web::printChain(Champion champion) {
	Node* temp = firstNode;
	Node* startNode;
	while (temp != NULL) {
		if (temp->pc.champion.getType() == champion.getType()) {
			startNode = temp;
			while (startNode != NULL) {
				cout << startNode->pc.player.getUsername() << endl;
				cout << startNode->pc.champion.getType() << endl;
				cout << endl;
				startNode = startNode->nextChampPlayer;
			}
			break;
		}
		temp = temp->next;
	}
	cout << endl << endl;
}

bool Web::playerInQueue(Player player) {
	Node* temp = firstNode;
	while (temp != NULL) {
		if (temp->pc.player.getUsername() == player.getUsername()) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int Web::getPlayerQueueIndex(Player player) {
	Node* temp = firstNode;
	int queueIndex = 1;
	while (temp != NULL) {
		if (temp->pc.player.getUsername() == player.getUsername()) {
			return queueIndex;
		}
		temp = temp->next;
		queueIndex++;
	}
	return -1;
}

Player Web::searchNext(Champion champion) {
	int id = champion.getId();

	Node* current = firstNode;

	while (current != NULL) {
		if (current->pc.champion.getType() == champion.getType()) {
			if (current->nextChampPlayer != NULL) {
				return current->nextChampPlayer->pc.player;
			}
			else {
				return Player();
			}
		}
		current = current->next;
	}
}