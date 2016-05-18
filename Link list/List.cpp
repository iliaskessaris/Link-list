#include <iostream>
#include <cstdlib>
#include <fstream>
#include "List.h"
using namespace std;

//Constuctor for the List class.
List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

//Read data from file and bulds up a list
void List::readFromFile() {
	int addData;
	ifstream readFromFileToList("ListFile.txt");
	
	while (!readFromFileToList.eof()) {
		readFromFileToList >> addData;
		if (addData != ' ') {
			AddAtEnd(addData); //Can be changed by AddInAscOrder e.t.c. depending on the type of list I want to create.
		}
	}
	readFromFileToList.close();
}

//Stores the list in a file.
void List::storeInFile() {
	ofstream storeListToFile("ListFile.txt");
	curr = head;

	while (curr != NULL) {
		storeListToFile << curr->data << endl;
		curr = curr->next;
	}
	storeListToFile.close();
}

//Insert node in the list.
void List::insertInList(int addData) {
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	//Insert node in emty list.
	if (head == NULL) {
		head = n;   
	}
	else {
		//Insert node at the beggining of the list.
		if (curr == head) {
			head = n;
			n -> next = curr;
		}
		else {
			//Insert node at the end of  the list.
			if (curr == NULL) {
				temp->next = n;
			}
			else {
				//Insert node between first and last node of the list.
				n->next = curr;
				temp->next = n;
			}
		}
	}
}

//AddS a node in its ascending order in the List.
void List::AddInAscOrder(int addData) {
	curr = head;

	while (curr != NULL && curr->data < addData) {
		temp = curr;
		curr = temp->next;
	}
	if (curr == NULL || head == NULL) {
		insertInList(addData);
	}
	else {
		if (curr->data != addData) {
			insertInList(addData);
		}
		else {
			cout << "The item: " << addData << " exists in the list\n";
		}
	}
}

//Adds a node in its descending order in the list.
void List::AddInDescOrder(int addData) {
	curr = head;

	while (curr != NULL && curr->data > addData) {
		temp = curr;
		curr = temp->next;
	}
	if (curr == NULL || head == NULL) {
		insertInList(addData);
	}
	else {
		if (curr->data != addData) {
			insertInList(addData);
		}
		else {
			cout << "The item: " << addData << " exists in the list\n";
		}
	}
}

//Adds a node at the end of the List.
void List::AddAtEnd(int addData) {
	curr = head;

	while (curr != NULL && curr->data != addData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		insertInList(addData);
	}
	else {
		cout << "The item: " << addData << " exists in the list\n";
	}
}

//Dletes node from the List.
void List::DeleteNode(int delData) {
	temp = head;
	curr = head;
	while(curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << delData << " was not in the list" << endl;
	}
	else {
		if (head == curr) 
		{
			head = head->next;
			
		}
		else 
		{
			temp->next = curr->next;
		}
		delete curr;
		cout << "The value " << delData << " was deleted" << endl;
	}
}

//Displays nodes from the List.
void List::PrintList() {
	curr = head;
	while (curr != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}

//Searches the List for a particular element using searchListRecursively.
void List::searchList(int searchData) {
	searchListRecursively(head, searchData);
};

//Search the List for a particular element using recursion.
void List::searchListRecursively(nodePtr position, int s) {
	
	if (position == NULL) {
		cout << s << " does not exits in the list.\n";
	}
	else 
		if (position->data == s) {
		cout << "The value " << s << " is in the list." << endl;
		}
		else {
			searchListRecursively(position->next,  s);
		}
};