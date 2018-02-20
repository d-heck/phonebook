/*
 * Book.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: David Heck
 *
 */

#ifndef BOOK_HPP_
#define BOOK_HPP_
#include <iostream>
#include <string>
#include <limits>
using namespace std;
#include "BST.hpp"

class Book {
	friend class BST;
	friend class Node;
	BST *phoneBook; // the AVL tree (phone book)
public:
	Book(); //Constructor
	~Book(); //Destructor
	void startSearch(); /* The User Interface, allows the user to search for specific
	last names in the AVL tree. Returns all the information related to the searched item. */
	void printPhoneBook(); //Prints the entire contents of the phone books
	string readInNames(const std::string& filename, int lnNo); //Reads in each line of a file (containing names)
	string generateNumber(); // Generates a random phone number to be used
	string intToString(int x); //Helper function for generateNumber turns int into string
	void insertionSort(Node arr[], int length); //Insertion Sort Algorithm to sort the Phone Book;
	void generatePhoneBook(int x);
	/*Generates a phone book of a specified size. Generates names from two text files, a file containing
	 * common first names and a file containing common last names. The function will also generate a random
	 * phone number. It will then assign all of these attributes to an array of nodes, sort them, and insert into an AVL tree.
	 */
};


#endif /* BOOK_HPP_ */
