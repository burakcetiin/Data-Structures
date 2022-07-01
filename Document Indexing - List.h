#pragma once
#include "Node.h"
#include <string>

using namespace std;

class List {

	public:
		List();
		~List();
		int getsizeRight()const;		
		void appendRight(string s);
		bool appendBelow(string s);
		void printRight() const;
		void printBelow() const;

	private:
		Node *head;
		Node *current;
		int sizeRight;
		int sizeBelow;
};
