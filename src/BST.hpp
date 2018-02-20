/*
 * BST.hpp
 *
 *  Created on: Nov 3, 2016
 *      Author: David Heck
 *
 */

#ifndef BST_HPP_
#define BST_HPP_

#include "Node.hpp"
#include <string>
using namespace std;

class BST {
	friend class Node;
	friend class Book;
	friend class LLPQ;
	Node *root;
	int count; // the count of the number of Nodes in the AVL tree
	BST(); // constructor sets root to NULL
	~BST(); // destructor deletes tree
public:
	void recDest(Node *n); //Helper function for deleting tree
	Node *insert(Node *rootNode, Node *node); //Inserts a node into the bst
	Node *balance(Node* n); // balance tree
	int max(int x, int y); //helper function
	int getBal(Node *n); //findes the bfactor of a node
	void printTreeio(Node *n); // Prints the contents of each node in the tree
	bool searchLast(Node *n, string x); //Searches tree for a particular last name
	bool searchFirst(Node *n, string x);//Searches tree for a particular first name
	bool searchNum(Node *n, string x); //Searches tree for a particular phone number
	void adjustBalances(Node *n); // adjusts heights of trees
	Node *rrRotate(Node *n); //used for rotation
	Node *llRotate(Node *n); //used for rotation
	Node *lrRotate(Node *n); //used for rotation
	Node *rlRotate(Node *n); //used for rotation
	Node *newLeaf(Node* n); // Helper for insert
	int setHeight(Node* n); // Helper fn
	void printInfo(Node* n); //Prints formatted information
};

#endif /* BST_HPP_ */
