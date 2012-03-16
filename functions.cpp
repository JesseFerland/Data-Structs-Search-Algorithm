#include "functions.h"
#include "bst.cpp"
#include <string>
#include <iostream>


int findFirst(string &temp)
{
	char firstLetter = temp[0];

	if(firstLetter >= 97) //If the letter is lowercase
	{
		firstLetter -= 32; //Will make it uppercase
	}

	return firstLetter - 'A';	//Returns the array location associated with the letter, A = 0, B = 1, etc.
}

/*      Pre:  BST is created
 *     Post:  A BST has been initiliazed 
 *  Purpose:  To further organize into word length
 ******************************************************************************/
void initializeNumTree(BST<int, string>* numTree)
{
	numTree->insert(22);
	numTree->insert(11);
	numTree->insert(5);
	numTree->insert(2);
	numTree->insert(1);
	numTree->insert(3);
	numTree->insert(4);
	numTree->insert(6);
	numTree->insert(8);
	numTree->insert(7);
	numTree->insert(10);
	numTree->insert(9);
	numTree->insert(16);
	numTree->insert(13);
	numTree->insert(12);
	numTree->insert(14);
	numTree->insert(15);
	numTree->insert(19);
	numTree->insert(17);
	numTree->insert(18);
	numTree->insert(20);
	numTree->insert(21);
	numTree->insert(26);
	numTree->insert(24);
	numTree->insert(23);
	numTree->insert(25);
	numTree->insert(28);
	numTree->insert(27);
	numTree->insert(45);

	return;	
}

/*      Pre:  BST is created
 *     Post:  A BST has been initiliazed 
 *  Purpose:  To further organize into alphabetize
 ******************************************************************************/
void initializeAlphabet(char alphabet[], int size)
{
	for(int i = 0; i < size; i++)
	{
		alphabet[i] = i + 'A'; //char to int for A.
	}

	return;
}

void pushNumTrees(BST<int, string>* numTrees[], int size)
{
	for(int i = 0; i < size; i++)
	{
		BST<int, string>* numTree = new BST<int, string>();
		numTrees[i] = numTree;
		initializeNumTree(numTrees[i]);		
	}
	return;
}

void readInWords(BST<int, string>* numTrees[])
{
	ifstream words;
	words.open("words.txt");
	string tempWord; 
	int arrayLoc;
	int wordLength;
	
	if(words.is_open())
	{
		while(words.good())
		{
			getline (words, tempWord); 
			arrayLoc = findFirst(tempWord);
			wordLength = tempWord.length();
			numTrees[arrayLoc]->pushWord(tempWord, wordLength);
		}

		words.close();
	}
	else
		cout << "Unable to open file." << endl;

	numTrees[0]->displayWords();
	return;
}

void doSearch(BST<int, string>* numTrees[], int size)
{
	string searchWord = "";
	int arrayLoc;
	bool found;

	while(searchWord != "-1")
	{
		cout << "Enter a word to search for: ";
		cin >> searchWord;
		arrayLoc = findFirst(searchWord);
		numTrees[arrayLoc]->displayWords();
		found = numTrees[arrayLoc]->findWord(searchWord);
		if(found)
		{
			cout << searchWord << " was found." << endl;
		}
		else
		{
			cout << searchWord << " was not found." << endl;
		}
	}
}