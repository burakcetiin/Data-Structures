#include "stdafx.h"
#include "List.h"
#include "Node.h"
#include <string>

using namespace std;

List::List():head(NULL), current(NULL), sizeRight(0), sizeBelow(0) {

}

List::~List() {

}

void List::printRight() const {

	Node *walk = head;

	while (walk != NULL) {

		cout << " -> " << walk->data;

		walk = walk->next;
	}
}

void List::printBelow() const {

	Node *walk = head;
	Node *b_walk = current;
	int count = 0;

	while (walk != NULL)
		{
			b_walk = walk;
			while (b_walk != NULL) {

				cout << " -> " << b_walk->data;

				b_walk = b_walk->below;
			}

			cout << endl;

		count++;
		walk = walk->next;
	}
}

int List::getsizeRight()const {
	return sizeRight;
}

void List::appendRight(string s) {

	Node *newptr = new Node(s);
	Node *walk = head;

	if (head == NULL && sizeRight == 0 ) {

		head = newptr;
		current = head;
	}

	else {

		while(walk != NULL) {

			if (walk->next == NULL) {

				walk->next = newptr;
				break;
			}

			walk = walk->next;
		}
	}

	current = newptr;
	sizeRight++;
}

bool List::appendBelow(string s) {

	Node *newptr = new Node(s);
	Node *walk = current;

	if (current == NULL) {
		return false;
	}

	else {

		while (walk != NULL) {

			if (walk->below == NULL) {

				walk->below = newptr;
				break;
			}

			walk = walk->below;
		}
	}
}
