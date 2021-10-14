#pragma once
#include <iostream>
using namespace std;


class Node {
	public:
		int data;
		class Node* next;
};


class CircularLinkedList {
	public:

		// attributes
		int currentSize;
		Node* current;

		// default constructor
		CircularLinkedList();

		// methods
		Node* createNode(int);
		void insertAfterCurrent(int);

		void printSize();
		void printCurrent();
		void printList();

		Node* search(int);
		void insertBeforeCurrent(int);
		bool update(int, int);
		bool deleteNode(int);
		void clearMemory();
};

// control menu 
void Menu(CircularLinkedList &);