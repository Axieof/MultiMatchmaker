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

	if (size == 0) {
		firstNode = newNode;
	}
	else 
	{
		Node* current = firstNode;

		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

	int id = newNode->pc.champion.getId();

	if (lastPlayerChampionIndex[id] != NULL)
	{
		lastPlayerChampionIndex[id] = newNode;
	}
	else
	{
		lastPlayerChampionIndex[id] = newNode;
	}
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
		}
		size--;
	}
}

//PlayerChampion Web::get(int index) {
//	if (index >= 0 && index < size) {
//		Node* current = firstNode;
//		for (int i = 0; i < index; i++)
//		{
//			current = current->next;
//		}
//		return current->pc;
//	}
//}

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
		/*temp->pc.player.print();
		temp->pc.champion.print();*/
		cout << temp->pc.player.getUsername() << endl;
		cout << temp->pc.champion.getType() << endl;
		cout << endl;
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

int Web::searchNext(Champion champion) {
	Node* current = firstNode;
	int queueIndex = 1;
	int found = 0;
	while (current != NULL) {
		if (current->pc.champion.getType() == champion.getType()) {
			found++;
		}
		if (found == 2) {
			return queueIndex;
		}
		current = current->next;
		queueIndex++;
	}
	return -1;
}