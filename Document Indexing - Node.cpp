#include "stdafx.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

Node::Node(string s):next(NULL), below(NULL), data(s){

}


Node::~Node() {

}
