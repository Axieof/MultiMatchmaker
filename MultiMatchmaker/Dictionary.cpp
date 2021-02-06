#include <iomanip>
#include "Dictionary.h"
using namespace std;

Dictionary::Dictionary() {
	size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = NULL;
	}
}

Dictionary::~Dictionary() {
	Node* temp;
	for (int i = 0; i < size; i++) {
		if (items[i] != NULL) {
			while (items[i]->next != NULL) {
				temp = items[i];
				items[i] = items[i]->next;
				temp->next = NULL;
				delete temp;
			}
			delete items[i];
		}
	}
	size = 0;
}

int charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int)'A';
		else
			return (int)c - (int)'a' + 26;
	}
	else
		return -1;
}

int Dictionary::hash(KeyType key) {
	int total = charvalue(key[0]);
	for (int i = 1; i < key.size(); i++)
	{
		if (charvalue(key[i]) < 0)  // not an alphabet
			continue;
		total = total * 52 + charvalue(key[i]);

		total %= MAX_SIZE;
	}
	return total;
}

bool Dictionary::add(KeyType newKey, ItemType newItem) {
	int pos = hash(newKey);
	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->key = newKey;
	newNode->next = NULL;
	if (items[pos] != NULL)
	{
		Node* temp = items[pos];
		while (temp->next != NULL)
		{
			if (temp->key == newKey)
			{
				cout << "\nKey \"" << temp->key << "\" already exists, rejecting duplicate entry.\n";
				return false;
			}
			temp = temp->next;
		}
		if (temp->key == newKey)
		{
			cout << "\nKey \"" << temp->key << "\" already exists, rejecting duplicate entry.\n";
			return false;
		}
		temp->next = newNode;
	}
	else
	{
		items[pos] = newNode;
	}
	size++;
	return true;
}

void Dictionary::remove(KeyType key) {
	int pos = hash(key);
	Node* current = items[pos];
	if (items[pos] != NULL) {
		// Checks first item only
		if (current->key == key) {
			items[pos] = current->next;
			current->next = NULL;
			delete current;
		}
		else {
			// Checks second onwards
			Node* prev = current;
			current = current->next;
			while (current != NULL) {
				if (current->key == key) {
					prev->next = current->next;
					current->next = NULL;
					delete current;
				}
				else {
					prev = current;
					current = current->next;
				}
			}
		}
		size--;
	}
	else {
		cout << "\nItem not found, remove failed.\n";
	}
}

ItemType Dictionary::get(KeyType key) {
	int pos = hash(key);
	Node* temp = items[pos];
	if (temp->key == key)
	{
		return temp->item;
	}
		
	if (temp == NULL) {
		cout << "\nCannot get item, key does not exist.\n";
		return Player();
	}
	else 
	{
		while (temp->next != NULL) {
			if (temp->key == key) {
				return temp->item;
			}
			temp = temp->next;
		}
		cout << "\nCannot get item, key does not exist.\n";
		return Player();
	}
}

bool Dictionary::isEmpty() {
	return size == 0;
}

int Dictionary::getLength() {
	return size;
}

void Dictionary::print() {
	cout << "\n===Print Dictionary===\n";
	for (int i = 0; i < MAX_SIZE; i++) {
		if (items[i] != NULL) {
			cout << "Index " << i << ": \n";
			Node* temp = items[i];
			while (true) {
				cout << "{ " << temp->key << " : " << temp->item.getUsername() << " } ";
				cout << "{ " << temp->key << " : " << temp->item.getmatchCount() << " } ";
				cout << "{ " << temp->key << " : " << temp->item.getMatchWon() << " } ";
				cout << "{ " << temp->key << " : " << temp->item.getMatchLoss() << " } ";
				cout << "{ " << temp->key << " : " << temp->item.getwinRate() << " } ";
				cout << "{ " << temp->key << " : " << temp->item.getskillLevel() << " } ";
				if (temp->next == NULL)
					break;
				temp = temp->next;
			}
			cout << "\n\n";
		}
	}
	cout << "\n";
}

void Dictionary::printPlayers()
{
	for (int i = 0; i < MAX_SIZE; i++) {
		if (items[i] != NULL)
		{
			Node* temp = items[i];
			cout << right << setw(2) << i << " |";
			cout << left << setw(15) << temp->item.getUsername() << "|";
			cout << left << setw(13) << temp->item.getmatchCount() << "|";
			cout << left << setw(4) << temp->item.getMatchWon() << "|";
			cout << left << setw(5) << temp->item.getMatchLoss() << "|";
			cout << left << setw(9) << temp->item.getwinRate() << "|";
			cout << left << setw(13) << temp->item.getskillLevel() << endl;
		}
	}
}