#include <iostream>
#include <cstdlib>
#include <fstream>
#include "List.h"
using namespace std;

void menuorder() {

}

int main() {
	List ListOfNumbers;
	
	char choice;
	int	addData;
	bool exitcode = false;

	while (exitcode == false) {
		cout << "Choose operation:\n";
		cout << "To add item in the list press:  1\n";
		cout << "To search for an item in the list press:  2\n";
		cout << "To delete item from the list press:  3\n";
		cout << "To display the list press:  4\n";
		cout << "To save the list in a file press:  5\n";
		cout << "To build up the list from a file press:  6\n";
		cout << "To stop the program press any key\n";
		cin >> choice;

		switch (choice) {
		case '1':
			cout << "Type the item to add in the list\n";
			cin >> addData;
			ListOfNumbers.AddAtEnd(addData);
			menuorder();
			break;
		case '2':
			cout << "Type the item to serch for in the list\n";
			cin >> addData;
			ListOfNumbers.searchList(addData);
			break;
		case '3':
			cout << "Type the item to delete from the list\n";
			cin >> addData;
			ListOfNumbers.DeleteNode(addData);
			break;
		case '4':
			ListOfNumbers.PrintList();
			break;
		case '5':
			ListOfNumbers.storeInFile();
			break;
		case '6':
			ListOfNumbers.readFromFile();
			break;
		default:
			exitcode = true;
			break;
		}
	}



	//List ListOfNumbers;
	//int value;

	//Display menu with choices.
	

	//Builds up the List.
	/*ListOfNumbers.AddInDescOrder(5);
	ListOfNumbers.AddInDescOrder(7);
	ListOfNumbers.AddInDescOrder(3);
	ListOfNumbers.PrintList();
	cout << endl;
	system("pause");
	ListOfNumbers.storeInFile();*/
	//ListOfNumbers.readFromFile();

	//ListOfNumbers.AddInAscOrder(7);
	//Delete number from the List.
	//ListOfNumbers.DeleteNode(5);
	//ListOfNumbers.PrintList();

	//cout << "Type the number to search for:\n";
	//cin >> value;
	//ListOfNumbers.searchList(value);
	//ListOfNumbers.storeInFile();
	system("pause");
}