/* ***  Author:       Wei Kian Chen
     *  Class:        CSI 281
     *  Institute:    Champlain College
     *  Last Update:  February 13, 2012
     *
     *  Description:
     *      This class is to implement the templated Binary Search Tree.  The 
     *  operations
     *  available for this impementation are:
     *  
	  *  1.  insert
     *  2.  isEmpty
	  *  3.  isExists
     *  4.  remove
     *  5.  showInOrder
     *  6.  showPreOrder
     *  7.  showPostOrder
     *
     *  Certification of Authenticity:	
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/
#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <iomanip>
#include "Stack.cpp"

using namespace std;

template <class T1, class T2>
class BST
{
   private:
	  Stack<T2>* mWords;
      T1      mData;
      BST<T1, T2> *mLeft, *mRight;
      BST<T1, T2> *mRootNode;

      BST(T1 data, BST<T1, T2> *left, BST<T1, T2> *right);

	  int countLeaves(BST<T1, T2> *node);
	  int countNodes(BST<T1, T2> *node);
	  void destroySubtree(BST<T1, T2> *node);
      void displayInOrder(BST<T1, T2> *node);
      void displayPreOrder(BST<T1, T2> *node);
      void displayPostOrder(BST<T1, T2> *node);
      int height(BST<T1, T2> *node);
	  void insert(BST<T1, T2> *&node, T1 data);
	  void insertWord(string &word);
      void makeDeletion(BST<T1, T2> *&node);
      void remove(BST<T1, T2> *&node, T1 searchKey);
	  
   public:
      BST();
      ~BST();

	  int countLeaves();
	  int countNodes();
	  void displayWords();
	  bool findWord(string &word);
	  int height();	  
      void insert(T1 data);
      bool isEmpty();
      bool isExists(T1 searchKey);
	  bool search(T2 searchWord);
	  void printPath(T1 searchKey);
	  void pushWord(string &word, int wordLength);
      void remove(T1 searchKey);
      void showInOrder();
      void showPreOrder();
      void showPostOrder();
};

#endif