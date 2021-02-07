#include<string>
#include<iostream>
#include "List.h"
using namespace std;

List::List() {
	firstNode = NULL;
	size = 0;
};

List::~List() {
	Node* current = firstNode;
	while (current != NULL) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	firstNode = NULL;
	size = 0;
}

bool List::add(PlayerChampion playerchampion){
	Node* newNode = new Node;
	newNode->pc = playerchampion;
	newNode->next = NULL;
	if (size == 0) {
		firstNode = newNode;
	}
	else {
		Node* current = firstNode;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
	return true;
}

void List::remove(int index) {
	if (index >= 0 && index < size) {
		if (index == 0) {
			Node* temp = firstNode;
			temp->next = NULL;
			delete temp;
			firstNode = firstNode->next;
		}
		else {
			Node* current = firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
			}
			Node* temp = current;
			temp->next = NULL;
			delete temp;
			current->next = current->next->next;
		}
		size--;
	}
}

PlayerChampion List::get(int index) {
	if (index >= 0 && index < size) {
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->pc;
	}
}

bool List::isEmpty() {
	return size == 0;
}

int List::getLength() {
	return size;
}

void List::print() {
	Node* temp = firstNode;
	while (temp != NULL) {
		temp->pc.player.print();
		temp->pc.champion.print();
		cout << endl;
		temp = temp->next;
	}
	cout << endl << endl;
}

bool List::playerInQueue(Player player) {
	Node* temp = firstNode;
	while (temp != NULL) {
		if (temp->pc.player.getUsername() == player.getUsername()) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int List::getPlayerQueueIndex(Player player) {
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