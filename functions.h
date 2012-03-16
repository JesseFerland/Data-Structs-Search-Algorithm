#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include "bst.h"

using namespace std;

enum Letters 
{
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z
};

int findFirst(string &temp);
void initializeNumTree(BST<int, string>* numTree);
void initializeAlphabet(char alphabet[], int size);
void pushNumTrees(BST<int, string>* numTrees[], int size);
void readInWords(BST<int, string>* numTrees[]);
void doSearch(BST<int, string>* numTrees[], int size);

#endif

