/*
 * Node.hpp
 *
 *  Created on: Nov 3, 2016
 *      Author: David Heck
 *
 */

#ifndef NODE_HPP_
#define NODE_HPP_

using namespace std;

class Node {
	friend class BST;
	friend class LLPQ;
	friend class Book;
	string firstName;
	string lastName;
	string phoneNumber;
	int height;
public:
	Node *left;
	Node *right;
	Node *next;
	Node *prev;
	Node(); //Constructor
	Node(string first_Name, string last_Name, int phone_Number); //Constuctor
	~Node(); //Destructor
};
#endif /* NODE_HPP_ */
