/*
 * BST.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: David Heck
 *
 */


#include <iostream>
#include <stdlib.h>
#include "BST.hpp"
#include <string>
#include "Node.hpp"

using namespace std;

BST::BST(){
	root = NULL;
	count = 0;
}//BSTB

BST::~BST(){
	recDest(root); // See function bellow
	return;
}//~BSTB

//Recursively deletes a BST
void BST::recDest(Node *n){
	if(n != NULL){
		recDest(n->left);
		recDest(n->right);
		delete n;
	}//if
	return;
}//recDest

void BST::printTreeio(Node *n) {
	if(n != NULL){
		printTreeio(n->left);
		//Print information (formatted nicely)
		printInfo(n);
		printTreeio(n->right);
	}
	return;
} //printTreeio

void BST::printInfo(Node* n){
	if ((n->lastName .length() + n->firstName .length()) > 21) {
		cout << n->lastName << ", " << n->firstName << "\t" << n->phoneNumber << endl;
	}//if
	else if ((n->lastName .length() + n->firstName .length()) >= 14) {
		cout << n->lastName << ", " << n->firstName << "\t \t" << n->phoneNumber << endl;
	}//else if
	else if ((n->lastName .length() + n->firstName .length()) < 6){
		cout << n->lastName << ", " << n->firstName << "\t \t \t \t" << n->phoneNumber << endl;
	}//else if
	else {
		cout << n->lastName << ", " << n->firstName << "\t \t \t" << n->phoneNumber << endl;
	} //else
}//printInfo

bool BST::searchLast(Node *n, string x){
	if (n != NULL){
		if (n->lastName == x){
			cout << "Last name found! Here is the information relating to Mr./Mrs. " << x << ": " << endl;
			printInfo(n);
			return true;
		}//if
		else if(x < n->lastName){
			return searchLast(n->left, x);
		}//else if
		else{
			return searchLast(n->right, x);
		}//else
	}//if
	else{
		return false;
	}//else
}//search

bool BST::searchFirst(Node *n, string x){
	//Has to be witten to search the whole tree since tree is not sorted by first name
	if (n->firstName == x){
		cout << "First name found! Here is the information related to " << x << ": " << endl;
		printInfo(n);
		return true;
	}//if
    if (n->left != NULL){
    	searchFirst(n->left, x);
    }//if
    if (n->right != NULL){
    	searchFirst(n->right, x);
    }//if
    return false;
}//searchFirst

bool BST::searchNum(Node *n, string x){
	//Has to be witten to search the whole tree since tree is not sorted by number
	if (n->phoneNumber == x){
		cout << "Number found! Here is the information related to the number " << x << ": " << endl;
		printInfo(n);
		return true;
	}//if
    if (n->left != NULL){
        searchNum(n->left, x);
    }//if
    if (n->right != NULL){
        searchNum(n->right, x);
    }//if
    return false;
}//searchNum

int BST::max(int x, int y){
	if( x > y ){
		return x;
	}//if
	else{
		return y;
	}//else
}//max

int BST::setHeight(Node* n){
    int h = 0;
    if (n != NULL){
        int lft = setHeight(n->left);
        int rgt = setHeight(n->right);
        int maxHeight = max(lft, rgt);
        h = maxHeight + 1;
    }//if
    return h;
}//setHe3ight

int BST::getBal(Node* n){
    int lft = setHeight(n->left);
    int rgt = setHeight(n->right);
    int bFactor= lft - rgt;
    return bFactor;
}//getBal

Node* BST::rrRotate(Node* n){
    Node *tmp = new Node();
    tmp = n->right;
    n->right = tmp->left;
    tmp->left = n;
    return tmp;
}//rrRotate

Node* BST::llRotate(Node* n){
    Node *tmp = new Node();
    tmp = n->left;
    n->left = tmp->right;
    tmp->right = n;
    return tmp;
}//llRotate

Node* BST::lrRotate(Node* n){
    Node *tmp = new Node();
    tmp = n->left;
    n->left = rrRotate(tmp);
    return llRotate(n);
}//lrRotate

Node* BST::rlRotate(Node* n){
	Node *tmp = new Node();
    tmp = n->right;
    n->right = llRotate(tmp);
    return rrRotate(n);
}//rlRotate

Node* BST::balance(Node* n){
    int bFactor = getBal(n);
    if (bFactor > 1){
        if (getBal(n->left) > 0){
            n = llRotate(n);
        }
        else{
            n = lrRotate(n);
        }
    }
    else if (bFactor < -1){
        if (getBal(n->right) > 0){
            n = rlRotate(n);
        }//if
        else{
            n = rrRotate(n);
        }//else
    }//else if
    return n;
}//balance

Node* BST::insert(Node* rootNode, Node* node){
    if (rootNode == NULL){;
    	rootNode = node;
        return rootNode;
    }//if
    else if (node->lastName < rootNode->lastName){
        rootNode->left = insert(rootNode->left, node);
        rootNode = balance(rootNode);
    }//else if
    else if (node->lastName >= rootNode->lastName){
        rootNode->right = insert(rootNode->right, node);
        rootNode = balance (rootNode);
    }//else if
    return rootNode;
}//insert

