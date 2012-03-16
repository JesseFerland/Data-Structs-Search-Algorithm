/*
Author:      Jesse Ferland
Class: CS1 281 <Section 2>
Assignment:  pa 5
Date Assigned: 2/29/12
Due Date: 3/16/12 2:00pm
Description: Using Binary Search Trees to search for words
Certification of Authenticity:
I certify that this assignment is entirely my own work.
*/

#include <iostream>
#include "bst.h"
#include "bst.cpp"
#include "functions.h"
#include <string>

using namespace std;

void main()
{
	const int NUM_LETTERS = 26;

	//char alphabet[NUM_LETTERS];
	BST<int, string>* numTrees[NUM_LETTERS];

	/*BST<int>* numTree = new BST<int>;
	initializeNumTree( numTree );*/

	pushNumTrees( numTrees, NUM_LETTERS);	

	//initializeAlphabet( alphabet, NUM_LETTERS );
	
	readInWords(numTrees);

	doSearch(numTrees, NUM_LETTERS);

	/*
	numTrees[A].printPath(27);
	numTrees[Z].printPath(3);

	cout << alphabet[0] << endl << alphabet[25] << endl;
	
	numTree.printPath(27);
	cout << endl << endl;
	numTree.printPath(3);
	
	alphabet.printPath('A');
	cout << endl << endl;
	alphabet.printPath('Z');
	cout << endl << endl;
	alphabet.printPath('G');
	cout << endl << endl;
	alphabet.printPath('H');
	*/

	system("pause");


}