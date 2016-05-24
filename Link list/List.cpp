#include <iostream>
#include <cstdlib>
#include <fstream>
#include "List.h"
#include <string>
using namespace std;

//Constuctor for the List class.
List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

//Checks whether or not a particular file exists.
bool List::FileExists(char s[]) {
	ifstream CheckTheFile(s);
	return CheckTheFile.is_open();
}

//Gets the type of stored list order from file TypeOfListOrder.txt.
void List::FindListOrderInFile(char s[]) {
	ifstream typeOfListOrderFile(s);

	typeOfListOrderFile >> typeOfListOrder;
	switch (typeOfListOrder) {
	case 1:
		cout << "The list in the file is not orderred\n";
		break;
	case 2:
		cout << "The list in the file is in ascending order\n";
		break;
	case 3:
		cout << "The list in the file is in descending order\n";
		break;
	default:
		cout << "The file is empty\n";
		break;
	}

	typeOfListOrderFile.close();
}

//Provides you the ability to choose the way the list will be build from the file*.
void List::MenuForListOrderFromFile() {
	char choice;
	

	if (FileExists("ListFile.txt")) {
		if (FileExists("TypeOfListOrder.txt")) {
			FindListOrderInFile("TypeOfListOrder.txt");
		}
		else {
			cout << "The file with the list exists but the file that keeps the order of the list has been destroyed\n";
		}
			cout << "\nChoose the way you want to build your list from the File\n";
			cout << "For no order press: 1\n";
			cout << "For Ascending order press: 2\n";
			cout << "For Descending order press: 3\n";
			cout << "To exit this menu press any other character\n";
			cin >> choice;
			switch (choice) {
			case '1':
				typeOfListOrder = 1;
				readFromFile();
				break;
			case '2':
				typeOfListOrder = 2;
				readFromFile();
				break;
			case '3':
				typeOfListOrder = 3;
				readFromFile();
				break;
			default:
				cout << "The item you typed just dropped\n";
				break;
			}
	}
	else {
		cout << "The list has not been stored in a file previously or the file is erased\n";
	}
}

//Provides you the ability to choose the type of order you want for the list.
void List::MenuForListOrderFromUser(int addData) {
	char choice;

	cout << "\nChoose the way you want to add the item in the list\n";
	cout << "For no order press: 1\n";
	cout << "For Ascending order press: 2\n";
	cout << "For Descending order press: 3\n";
	cout << "To descard the item you just typed press any other character\n";
	cin >> choice;

	switch (choice) {
	case '1':
		if (typeOfListOrder == 0 || typeOfListOrder == 1) {
			typeOfListOrder = 1;
			AddAtEnd(addData);
		}
		else {
			cout << "You can not build unordered list. Choose another type of order.\n";
		}
		break;
	case '2':
		if (typeOfListOrder == 0 || typeOfListOrder == 2) {
			typeOfListOrder = 2;
			AddInAscOrder(addData);
		}
		else {
			cout << "The order of the list is not Ascending. Choose another type of order.\n";
		}
		break;
	case '3':
		if (typeOfListOrder == 0 || typeOfListOrder == 3) {
			typeOfListOrder = 3;
			AddInDescOrder(addData);
		}
		else {
			cout << "The order of the list is not Descending. Choose another type of order.\n";
		}
		break;
	default:
		cout << "The item you typed just dropped\n";
		break;
	}
}

//Provides you the ability to choose the type of operation to perform on the list.
bool List::MenuList() {
	char choice;
	int	addData;
	bool status = false;
	
	cout << "\nType Of List Order menu: " << typeOfListOrder << endl;
	cout << "Choose operation:\n";
	cout << "To add item in the list press:  1\n";
	cout << "To search for an item in the list press:  2\n";
	cout << "To delete item from the list press:  3\n";
	cout << "To display the list press:  4\n";
	cout << "To save the list in a file press:  5\n";
	cout << "To build up the list from a file press:  6\n";
	cout << "To stop the program press any other key\n";
	cin >> choice;

	switch (choice) {
	case '1':
		cout << "Type the item to add in the list\n";
		cin >> addData;
		MenuForListOrderFromUser(addData);
		break;
	case '2':
		cout << "Type the item to serch for in the list\n";
		cin >> addData;
		searchList(addData);
		break;
	case '3':
		cout << "Type the item to delete from the list\n";
		cin >> addData;
		DeleteNode(addData);
		break;
	case '4':
		PrintList();
		break;
	case '5':
		storeInFile();
		break;
	case '6':
		MenuForListOrderFromFile();
		break;
	default:
		status = true;
		break;
	}
	return status;
}

//Read data from file and build up a list depending on the value of typeOfListOrder variable.
void List::readFromFile() {
	ifstream readFromFileToList("ListFile.txt");
	int addData;
		
	while (!readFromFileToList.eof()) {
		readFromFileToList >> addData;
		switch (typeOfListOrder) {
		case 1:
			AddAtEnd(addData); 
			break;
		case 2:
			AddInAscOrder(addData);
			break;
		case 3:
			AddInDescOrder(addData);
			break;
		default:
			break;
		}
	}
	readFromFileToList.close();
}

//Stores the list in a file.
void List::storeInFile() {
	ofstream storeListToFile("ListFile.txt");
	ofstream typeOfListOrderFile("TypeOfListOrder.txt");
	
	curr = head;

	
	while (curr != NULL) {
		storeListToFile << curr->data;
		curr = curr->next;
		if (curr != NULL) { //avoid the addition of space at the end of the file.
			storeListToFile << endl;
		}
	}
	
	typeOfListOrderFile << typeOfListOrder;
	storeListToFile.close();
	typeOfListOrderFile.close();
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