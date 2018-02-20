/*
 * Node.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: David Heck
 *
 */

#include <iostream>
#include <stdlib.h>
#include "Node.hpp"

using namespace std;

Node::Node() {
	firstName = "";
	lastName = "";
	phoneNumber = "";
	height = 0;
	right = NULL;
	left = NULL;
	next = NULL;
	prev = NULL;
}//LLNode

Node::Node(string first_Name, string last_Name, int phone_Number){
	firstName = first_Name;
	lastName = last_Name;
	phoneNumber = phone_Number;
	height = 0;
	right = NULL;
	left = NULL;
	next = NULL;
	prev = NULL;
}

Node::~Node() {
	if (right != NULL || left != NULL) {
		cout << "deleting this Node may cause a memory leak" << endl;
	}//if
}//~LLNode
