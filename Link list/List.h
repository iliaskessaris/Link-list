#ifndef LIST_H
#define LIST_H


class List {

public:
	List();
	void insertInList(int addData);
	void AddAtEnd(int addData);
	void AddInAscOrder(int addData);
	void AddInDescOrder(int addData);
	void readFromFile();
	void storeInFile();
	void searchList(int searchData);
	void DeleteNode(int delData);
	void PrintList();
	void MenuForListOrder();
	bool MenuList();

private:
	typedef struct node {
		int data;
		struct node* next;
	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
	void searchListRecursively(nodePtr position, int s);	
};

#endif;
