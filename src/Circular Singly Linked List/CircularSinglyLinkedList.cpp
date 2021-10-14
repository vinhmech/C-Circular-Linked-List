#include "CircularSinglyLinkedList.h"

CircularLinkedList::CircularLinkedList() {
	currentSize = 0;					// initialize currentSize to 0
	current = NULL;						// current is set to NULL
}


Node* CircularLinkedList::createNode(int n) {
	Node* p = new Node;					// allocate memeory pointer p on the heap
	if (p == NULL) {
		cout << "\nNot enough memory to initialize a node";
		return NULL;
	}
	else {
		p->data = n;
		p->next = NULL;
		return p;
	}
}

void CircularLinkedList::insertAfterCurrent(int n) {
	Node* p = createNode(n);			// create a node from an integer value n
	if (currentSize == 0) {				// list is empty
		current = p;
		current->next = current;
	}
	else {								// list has more than 1 node
		p->next = current->next;
		current->next = p;
		current = p;
	}
	currentSize++;
}

void CircularLinkedList::insertBeforeCurrent(int n) {
	Node* p = createNode(n);			// create a node from an integer value n
	if (currentSize == 0) {				// list is empty
		current = p;
		current->next = current;
	}
	else {								// list has more than 1 node
		p->next = current;
		for (int i = 1; i < currentSize; i++) {
			current = current->next;
		}
		current->next = p;
		current = p;
	}
	currentSize ++;
}

Node* CircularLinkedList::search(int n) {
	if (currentSize == 0) {
		return NULL;
	}
	for (int i = 1; i <= currentSize; i++) {
		if (current->data == n) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

bool CircularLinkedList::update(int o, int n) {
	Node* nodeToChange = search(o);
	if (nodeToChange == NULL) {
		return false;
	}
	else {
		nodeToChange->data = n;
		return true;
	}
}

bool CircularLinkedList::deleteNode(int n) {
	Node* nodeToDelete = search(n);
	if (nodeToDelete == NULL) {
		return false;
	}
	else {
		Node* nodeAfterCurrent = current->next;
		for (int i = 1; i < currentSize; i++) {
			current = current->next;
		}
		current->next = nodeAfterCurrent;
		current = current->next;
		delete nodeToDelete;
		currentSize--;
		return true;
	}
}

void CircularLinkedList::printSize() {
	if (currentSize <= 1) {
		cout << "\nThe list has " << currentSize << " element";
	}
	else {
		cout << "\nThe list has " << currentSize << " elements";
	}
}


void CircularLinkedList::printCurrent() {
	if (currentSize == 0) {
		cout << "\nEmpty List";
	}
	else {
		cout << "\nThe current element is " << current->data;
	}
}


void CircularLinkedList::printList() {
	if (currentSize == 0) {
		cout << "\nEmpty List";
	}
	else {
		cout << endl;
		for (int i = currentSize; i > 0; i--) {
			cout << current->data << " ";
			current = current->next;
		}
	}
}


// automatically free all memory allocated on the heap after the program is finished if the user didn't call deleteAll() before quitting, clearMemory() is identical to deleteAll()
void CircularLinkedList::clearMemory() {
	if (currentSize == 0) {
		return;
	}
	Node* temp = NULL;
	int i = 1;
	while (i < currentSize) {
		temp = current;
		current = current->next;
		delete temp;
		i++;
		if (i == currentSize) {
			delete current;
			return;
		}
	}

	for (int i = 1; i < currentSize; i++) {
		temp = current;
		current = current->next;
		delete temp;
	}
}



void Menu(CircularLinkedList &l) {
	int selection;
	do {
		system("CLS");
		cout << "\n\n========== Menu ==========";
		cout << "\n1.	Insert After Current";
		cout << "\n2.	Search";
		cout << "\n3.	Insert Before Current";
		cout << "\n4.	Update";
		cout << "\n5.	Delete";
		cout << "\n6.	Print Size";
		cout << "\n7.	Print Current";
		cout << "\n8.	Print List";
		cout << "\n0.	Quit";
		cout << "\n\n========== End ==========";
		do {
			cout << "\nEnter selection: ";
			cin >> selection;
			if (selection < 0 || selection > 8) {
				cout << "\nInvalid selection, please choose between 0 and 8";
			}
		} while (selection < 0 || selection > 8);

		if (selection == 1) {
			cout << "\nEnter element to add: ";
			int n;
			cin >> n;
			l.insertAfterCurrent(n);
		}

		else if (selection == 2) {
			int val;
			cout << "\nEnter search value: ";
			cin >> val;
			Node* result = l.search(val);
			if (l.currentSize == 0) {
				cout << "\nEmpty list, element not found";
			}
			else if (result == NULL) {
				cout << "\nElement not found";
			}
			else {
				cout << "\nElement " << result->data << " was found";
			}
		}

		else if (selection == 3) {
			cout << "\nEnter node to add: ";
			int n;
			cin >> n;
			l.insertBeforeCurrent(n);
		}

		else if (selection == 4) {
			int o, n;
			cout << "\nEnter value to update: ";
			cin >> o;
			cout << "\nUpdate to new value: ";
			cin >> n;
			bool result = l.update(o,n);
			if (l.currentSize == 0) {
				cout << "\nEmpty list, value to update not found";
			}
			else if (result == false) {
				cout << "\nFail to update, value to update not found";
			}
			else {
				cout << "\nUpdate successful";
			}
		}

		else if (selection == 5) {
			int n;
			cout << "\nEnter value to delete: ";
			cin >> n;
			if (l.currentSize == 0) {
				cout << "\nEmpty list, value to delete not found";
			}
			else {
				bool result = l.deleteNode(n);
				if (result == false) {
					cout << "\nFail to delete, value to delete not found";
				}
				else {
					cout << "\nDelete successful";
				}
			}
		}

		else if (selection == 6) {
			l.printSize();
		}

		else if (selection == 7) {
			l.printCurrent();
		}

		else if (selection == 8) {
			l.printList();
		}
		cout << endl;
		system("pause");
	} while (selection != 0);
};