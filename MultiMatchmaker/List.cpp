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

bool List::add(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
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

bool List::add(int index, ItemType item) {
	if (index >= 0 && index <= size) {
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 0) {
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else {
			Node* current = firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}
		size++;
		return true;
	}
	else {
		return false;
	}
}

void List::remove(int index) {
	if (index >= 0 && index < size) {
		if (index == 0) {
			firstNode = firstNode->next;
		}
		else {
			Node* current = firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
			}
			current->next = current->next->next;
		}
		size--;
	}
}

ItemType List::get(int index) {
	if (index >= 0 && index < size) {
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->item;
	}
	else {
		return "";
	}
}

bool List::isEmpty() {
	return size == 0;
}

int List::getLength() {
	return size;
}

void List::print() {
	Node* temp = new Node;
	temp = firstNode;
	while (temp != NULL) {
		cout << temp->item << endl;
		temp = temp->next;
	}
	cout << endl << endl;
}