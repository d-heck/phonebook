/*
 * Book.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: David Heck
 *
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <limits>
#include <fstream>
#include "Book.hpp"
#include "BST.hpp"
using namespace std;


Book::Book(){
	phoneBook = new BST();
}//Constructor

Book::~Book(){
	phoneBook->~BST();
	delete phoneBook;
}//Destructor

string Book::generateNumber(){
	int x;
	string number = "+1(";
	for (int i = 0; i < 10; i++){
		if ( i == 3){
			number += ")";
		}//if
		x = rand() % 10;
		number += intToString(x);
	}//for
	return number;
}//generateNumber

string Book::intToString(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}//intToString

string Book::readInNames(const std::string& filename, int lnNo) {
	string Name;

	ifstream file(filename.c_str());
	if (!file.is_open()) {
		cerr << "Could not open file." << filename << endl;
		return "";
	}
	for (; lnNo > 1; --lnNo)
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	string line;
	if (!getline(file, line)) {
		cerr << "Could not read file." << filename << endl;
		return "";
	}
	Name = line;
	return Name;
}//readInNames

void Book::printPhoneBook(){
	phoneBook->printTreeio(phoneBook->root);
}//printPhoneBook;

void Book::insertionSort(Node arr[], int length) {
	int j;
	Node * tmp = new Node();
	for (int i = 0; i < length; i++) {
		j = i;
		while (j > 0 && arr[j].lastName < arr[j - 1].lastName) {
			//swap
			tmp->firstName = arr[j].firstName;
			tmp->lastName = arr[j].lastName;
			tmp->phoneNumber = arr[j].phoneNumber;

			arr[j].firstName = arr[j - 1].firstName;
			arr[j].lastName = arr[j - 1].lastName;
			arr[j].phoneNumber = arr[j - 1].phoneNumber;

			arr[j - 1].firstName = tmp->firstName;
			arr[j - 1].lastName = tmp->lastName;
			arr[j - 1].phoneNumber = tmp->phoneNumber;

			j--;
		}//while
	}//for
}//insertionSort


void Book::generatePhoneBook(int x){
	//Initialize
	srand (time(NULL));
	Node* array = new Node[x];
	int size = x;
	int lnNo1 = 0;
	int lnNo2 = 0;

	//Create Randomized Data And Insert into Array
	for (int i = 0; i < size; i++){
		lnNo1 = rand() % 5164;
		lnNo2 = rand() % 88800;
		array[i].firstName = readInNames("firstnames.txt", lnNo1);
		array[i].lastName = readInNames("lastnames.txt", lnNo2);
		array[i].phoneNumber = generateNumber();
	}//for

/*  This section contains some testing elements I used.
    Everything is functional, and I felt it a shame to delete it all.


	//sort LLPQ
	//insertionSort(array, x); // Used in testing for comparison to the in order AVL sort

	cout << endl;

	//Print Array (formatted)
	for (int i = 0; i < size; i++){
		if((array[i].lastName.length() + array[i].firstName.length()) > 24){
			cout << array[i].lastName << ", " << array[i].firstName << "\t" << array[i].phoneNumber << endl;
		}//if
		else if((array[i].lastName.length() + array[i].firstName.length()) >= 14){
			cout << array[i].lastName << ", " << array[i].firstName << "\t \t" << array[i].phoneNumber << endl;
		}//if
		else{
			cout << array[i].lastName << ", " << array[i].firstName << "\t \t \t" << array[i].phoneNumber << endl;
		}//else
	}//for

*/

	//Create AVL Tree
	for(int i = 0; i < size; i++){
		Node *n = new Node();
		*n = array[i];
		phoneBook->root = phoneBook->insert(phoneBook->root, n);
	}//for

	delete[] array; // Free up space
	return;
}//generatePhoneBook

void Book::startSearch(){
	string input;
	string option;
	string search;
	string again = "y";
	int size;
	int loopTrig = 0;
	int miniLoop = 0;

	//Welcome Splash
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "  Welcome to Amber Pages, a phone book simulator! " << endl;
	cout << "\t" << "Created By: David Heck" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl;
	cout << endl;

	//User Input / Create Phone Book
	cout << "Please specify how large you would like the phonebook to be (Natural Numbers Only): ";
	cin >> input;
	cout << endl;
	size = atoi(input.c_str());
	cout << "Generating..." << endl;
	generatePhoneBook(size);
	cout << "Done!" << endl;
	cout << endl;

	//Search Input
	while(loopTrig == 0){
		//Initialize Looping
		loopTrig = 1;
		miniLoop = 0;

		cout << "Search By First Name (a) | Search By Last Name (b) | Search By Number (c) | Print Phonebook (d)" << endl;
		cout << "How would you like to interact with your phonebook?" << endl;
		cin >> option;
		if(option == "a" || option == "A"){
			cout << endl;
			cout << "\t Search By First Name" << endl;
			cout << "Please enter a First Name to search for (Please use all CAPS): ";
			cin >> search;
			cout << "Results:" << endl;
			cout << endl;
			phoneBook->searchFirst(phoneBook->root, search);
		}//if
		else if(option == "b" || option == "B"){
			cout << endl;
			cout << "\t Search By Last Name" << endl;
			cout << "Please enter a Last Name to search for (Please use all CAPS): ";
			cin >> search;
			cout << "Results:" << endl;
			cout << endl;
			phoneBook->searchLast(phoneBook->root, search);
		}//else if
		else if(option == "c" || option ==  "C"){
			cout << endl;
			cout << "\t Search By Phone Number" << endl;
			cout << "Please enter a Phone Number to search for (Format: +1(xxx)xxxxxxx) : ";
			cin >> search;
			cout << "Results:" << endl;
			cout << endl;
			phoneBook->searchNum(phoneBook->root, search);
		}//else if
		else if(option == "d" || option == "D"){
			cout << "Printing Phone Book..." << endl;
			cout << endl;
			phoneBook->printTreeio(phoneBook->root);
			cout << endl;
			cout << "Done!" << endl;
			cout << endl;
		}//else if
		else{
			cout << "I'm sorry that is not an option, did you mistype?" << endl;
			loopTrig = 0;
			cout << endl;
		}//else

		//Return to menu
		while(miniLoop == 0){
			cout << endl;
			cout << "Return to selection screen? (y/n): ";
			cout << endl;
			cin >> again;
			if(again == "y" || again == "Y"){
				miniLoop = 1;
				loopTrig = 0;
			}//if
			else if(again == "n" || again == "N"){
				miniLoop = 1;
				loopTrig = 1;
				cout << endl;
				cout << "Goodbye!" << endl;
			}//else if
			else{
				cout << "I'm sorry that is not an option, did you mistype? (options are y or n)" << endl;
			}//else
		}//while
	}//while
}//startSearch
