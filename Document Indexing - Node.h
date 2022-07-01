#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {

	public:
		Node(string s);
		~Node();

		Node *next;
		Node *below;

		string data;
};
