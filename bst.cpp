/*
Author:      Jesse Ferland
Class: CS1 281 <Section 2>
Assignment:  pa 4
Date Assigned: 2/17/12
Due Date: 2/24/12 2:00pm
Description: Using Binary Search Trees
Certification of Authenticity:
I certify that this assignment is (where noted) entirely my own work.
*/

#include "bst.h"
#include "stack.cpp"
#include <string>



/*      Pre:  None
 *     Post:  The private members are initialized
 *  Purpose:  Default constructor for BST
 ******************************************************************************/
template <class T1, class T2>
BST<T1, T2>::BST()
{
   mRootNode = NULL;
   mLeft     = NULL;
   mRight    = NULL;
   mData     = T1();
   mWords	 = new Stack<T2>();
}


/*      Pre:  None
 *     Post:  The private members are initialized
 *  Purpose:  This is a private constructor for internal use
 ******************************************************************************/
template <class T1, class T2>
BST<T1, T2>::BST(T1 data, BST<T1, T2> *left = NULL, BST<T1, T2> *right = NULL)
{
   mRootNode = NULL;
   mLeft     = left;
   mRight    = right;
   mData     = data;
   mWords	 = new Stack<T2>();
}


/*      Pre:  The variable must be created
 *     Post:  The entire tree is deleted
 *  Purpose:  Deconstructor for BST
 ******************************************************************************/
template <class T1, class T2>
BST<T1, T2>::~BST()
{
   destroySubtree(mRootNode);
}


/*      Pre:  BST has been created
 *     Post:  Number of leaves is returned
 *  Purpose:  Count number of leaves in BST; this is a private recursive function
 ******************************************************************************/
template <class T1, class T2>
int BST<T1, T2>::countLeaves(BST<T1, T2> *node)
{
	int leaves = 0;
	
	if (isEmpty())
	{
		cout << "The BST has not yet been initialized with any data." << endl;
	}
	else if (node != NULL)
	{
		leaves += countLeaves(node->mLeft);
		
		//If the left node is null, it was counted as a leaf, so dont call the right on the same node.
		if(node->mLeft != NULL) 
		{
			leaves += countLeaves(node->mRight);
		}
	}
	else if (node == NULL )
	{
		leaves++;
	}

	return leaves;
}

/*      Pre:  BST has been created
 *     Post:  Number of leaves is returned
 *  Purpose:  To call the private recursive function countLeaves
 ******************************************************************************/
template <class T1, class T2>
int BST<T1, T2>::countLeaves()
{
	if(isEmpty())
		return 0;

	return countLeaves(mRootNode);
}


/*      Pre:  BST has been created
 *     Post:  Number of nodes is returned
 *  Purpose:  Count number of nodess in BST; this is a private recursive function
 ******************************************************************************/
template <class T1, class T2>
int BST<T1, T2>::countNodes(BST<T1, T2> *node)
{
	int nodes = 0;
	
	if (isEmpty())
	{
		cout << "The BST has not yet been initialized with any data." << endl;
	}
	else if (node != NULL)
	{
		nodes++;
		nodes += countNodes(node->mLeft);
		nodes += countNodes(node->mRight);
	}

	return nodes;
}

/*      Pre:  BST has been created
 *     Post:  Number of nodes is returned
 *  Purpose:  To call the private recursive function countNodes
 ******************************************************************************/
template <class T1, class T2>
int BST<T1, T2>::countNodes()
{
	if(isEmpty())
		return 0;

	return countNodes(mRootNode);
}

/*      Pre:  A BST exists
 *     Post:  A subtree is deleted
 *  Purpose:  Delete a subtree; this is a recursive private function
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::destroySubtree(BST<T1, T2> *node)
{
   if (node == NULL)
      return;

   destroySubtree(node->mLeft);
   destroySubtree(node->mRight);

   // Delete the node at the root.
   delete node;
}


/*      Pre:  A BST exists
 *     Post:  The tree is displayed in order to the screen
 *  Purpose:  To display the tree in in-order manner; this is a recursive
 *            private function
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::displayInOrder(BST<T1, T2> *node)
{
   if (node != NULL)
   {
      displayInOrder(node->mLeft);
      cout << node->mData << "  ";
      displayInOrder(node->mRight);
   }
}


/*      Pre:  A BST exists
 *     Post:  The tree is displayed pre oder to the screen
 *  Purpose:  To display the tree in preorder manner; this is a private recursive
 *            function.
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::displayPreOrder(BST<T1, T2> *node)
{
   if (node != NULL)
   {
      cout << node->mData << "  ";
      displayPreOrder(node->mLeft);		
      displayPreOrder(node->mRight);
   }
}


/*      Pre:  A BST exists
 *     Post:  The tree is displayed post order to the screen
 *  Purpose:  To display the tree is post-order manner; this is a private 
 *            recursive function
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::displayPostOrder(BST<T1, T2> *node)
{
   if (node != NULL)
   {
      displayPostOrder(node->mLeft);		
      displayPostOrder(node->mRight);
      cout << node->mData << "  ";
   }
}

template <class T1, class T2>
void BST<T1, T2>::displayWords()
{
	mWords->display();
}

template <class T1, class T2>
bool BST<T1, T2>::findWord(string &word)
{
	return mWords->isExist(word);
}

/*      Pre:  BST has been created
 *     Post:  Number of nodes high is returned
 *  Purpose:  To find the height of a BST; this is a private recursive function
 ******************************************************************************/
template <class T1, class T2>
int BST<T1, T2>::height(BST<T1, T2> *node) 
{
	int totalHeight = 0;
	int tempHeight1;
	int tempHeight2;
	
	if (isEmpty())
	{
		cout << "The BST has not yet been initialized with any data." << endl;
	}
	else if ( node != NULL )
	{
		totalHeight++;
		tempHeight1 = height(node->mLeft);
		tempHeight2 = height(node->mRight);

		//Find which side found the greatest height and add that to the total height
		if(tempHeight1 >= tempHeight2 && totalHeight <= tempHeight1)
		{
			totalHeight += tempHeight1;
		}
		else if(totalHeight <= tempHeight2)
		{
			totalHeight += tempHeight2;
		}
	}

	return totalHeight;
}

/*      Pre:  BST has been created
 *     Post:  Number of nodes high is returned
 *  Purpose:  To call the private recursive height
 ******************************************************************************/
template <class T1, class T2>
int BST<T1, T2>::height()
{
	if(isEmpty())
		return 0;
	
	return height(mRootNode);
}

/*      Pre:  Data to be inserted onto the tree
 *     Post:  The data is correctly placed onto the tree
 *  Purpose:  Insert a node onto the tree; this is a public function
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::insert(T1 data)
{
   insert(mRootNode, data);
}


/*      Pre:  A node where the data to be added and the data to be added
 *     Post:  The data is correctly placed onto the tree
 *  Purpose:  Insert a node onto the tree, this is a recursive private function
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::insert(BST<T1, T2> *&node, T1 data)
{
   // If the tree is empty, make a new node and make it 
   // the root of the tree.
   if (node == NULL)
   { 
      node = new BST<T1, T2>(data, NULL, NULL);
      return;
   }
		
   // If num is already in tree: return.
   if (node->mData == data)
      return;

   // The tree is not empty: insert the new node into the
   // left or right subtree.
   if (data < node->mData)
      insert(node->mLeft, data);
   else
      insert(node->mRight, data);
}

template <class T1, class T2>
void BST<T1, T2>::insertWord(string &word)
{
	mWords->push(word);
	//mWords->display();
}

/*      Pre:  None
 *     Post:  True if the tree is empty, otherwise false
 *  Purpose:  To determine if the tree is empty
 ******************************************************************************/
template <class T1, class T2>
bool BST<T1, T2>::isEmpty()
{
   return (mRootNode == NULL);
}


/*      Pre:  A search key
 *     Post:  True is the search key is found in the tree, otherwise false
 *  Purpose:  To determine if a give data exists in the tree or not
 ******************************************************************************/
template <class T1, class T2>
bool BST<T1, T2>::isExists(T1 searchKey)
{
   BST<T1, T2> *tmp;
   bool   found = false;

   tmp = mRootNode;
   while (tmp != NULL)
   {
      if (tmp->mData == searchKey)
      {
         found = true;
         break;
      }
      else if (tmp->mData > searchKey)
         tmp = tmp->mLeft;
      else
         tmp = tmp->mRight;
   }

   return found;
}


/*      Pre:  The node to be removed from the tree
 *     Post:  The node is removed from the tree correctly
 *  Purpose:  To remove a node from the tree and reroute the links of the 
 *            children correctly; this is a private function
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::makeDeletion(BST<T1, T2> *&node)
{
	BST<T1, T2> *nodeToDelete, *attachPoint;
	nodeToDelete = node;

	if(node->mRight == NULL)
	{
		node = node->mLeft; //Because node is passed is as a pointer reference, this makes the pointer point to the new location, fixing the link
	}
	else if(node->mLeft == NULL)
	{
		node = node->mRight;
	}
	else
	{
		attachPoint = node->mRight;
		while(attachPoint->mLeft != NULL)
		{
			attachPoint = attachPoint->mLeft;
		}
		attachPoint->mLeft = node->mLeft;
		node = node->mRight;
	}

	nodeToDelete->mLeft = NULL;
	nodeToDelete->mRight = NULL;
	delete nodeToDelete;
}

/*      Pre:  BST has been created
 *     Post:  The path is printed
 *  Purpose:  To show the path taken to find a variable BST
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::printPath(T1 searchKey)
{
	//Format so it looks like tree

	if(isExists(searchKey))
	{
		int printLocation = 20;
		int printIncrement = 5;
		BST<T1, T2> *tmp;
	 
		tmp = mRootNode;
		while (tmp != NULL)
		{
			if (tmp->mData == searchKey)
			{
				cout << right << setw(printLocation) << tmp->mData << endl;
				break;
			}
			else if (tmp->mData > searchKey)
			{
				//Print the node and line to next
				cout << right << setw(printLocation) << tmp->mData << endl;
				
				//change location of cursor, print last line to node
				printLocation -= printIncrement;

				//set temp to the left node
				tmp = tmp->mLeft;
			}
			else
			{
				//Print the node and line to next
				cout << right << setw(printLocation) << tmp->mData << endl;
				
				//change location of cursor, print last line to node
				printLocation += printIncrement; 

				//set temp to the right node
				tmp = tmp->mRight;
			}
		}
		tmp->displayWords();
	}

	else //If search key does not exist
	{
		cout << "Search key not found.." << endl;
	}
}

template <class T1, class T2>
void BST<T1, T2>::pushWord(string &word, int wordLength)
{
	if(isExists(wordLength))
	{
		 BST<T1, T2> *tmp;

	     tmp = mRootNode;
	     while (tmp != NULL)
	     {
		    if (tmp->mData == wordLength)
		    {		  	   
		  	   break;
		    }
		    else if (tmp->mData > wordLength)
			   tmp = tmp->mLeft;
		    else
			   tmp = tmp->mRight;
	     }

		 if(tmp != NULL)
		 {
			 tmp->insertWord(word);
		 }
	}

	else 
		cout << "There is no tree to put the word " << word << " into." << endl;

	return;
}


/*      Pre:  The node and a search key
 *     Post:  A node is removed from the tree, if exists
 *  Purpose:  To remove a node from the tree and reroute the links of the 
 *            children correctly; this is a private recursive function
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::remove(BST<T1, T2> *&node, T1 searchKey)
{
	if( node == NULL)
		return;

	if(node->mData > searchKey)
		remove(node->mLeft, searchKey);
	
	else if (node->mData < searchKey)
		remove(node->mRight, searchKey);

	else
		makeDeletion(node);
}


/*      Pre:  The search key to be removed from the tree
 *     Post:  A node is removed from the tree, if exist
 *  Purpose:  To remove a node from the tree
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::remove(T1 searchKey)
{
	if(isEmpty())
		return;
	else if (!isExists(searchKey))
		return;

	remove(mRootNode, searchKey);
}

template <class T1, class T2>
 bool BST<T1, T2>::search(T2 searchWord)
 {
	 bool found;
	 if(isExists(wordLength))
	 {
		 BST<T1, T2> *tmp;

	     tmp = mRootNode;
	     while (tmp != NULL)
	     {
		    if (tmp->mData == wordLength)
		    {		  	   
		  	   break;
		    }
		    else if (tmp->mData > wordLength)
			   tmp = tmp->mLeft;
		    else
			   tmp = tmp->mRight;
	     }

		 if(tmp != NULL)
		 {
			 found = tmp->findWord(word);
		 }
	}

	else 
		found = false;

	return found;
 }

/*      Pre:  A BST exists
 *     Post:  The tree is displayed in oder to the screen
 *  Purpose:  To display the tree in in-order manner;  This function is public
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::showInOrder()
{
   displayInOrder(mRootNode);
}


/*      Pre:  A BST exists
 *     Post:  The tree is displayed pre oder to the screen
 *  Purpose:  To display the tree in preorder manner;  This function is public
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::showPreOrder()
{
   displayPreOrder(mRootNode); 
}


/*      Pre:  A BST exists
 *     Post:  The tree is displayed poist oder to the screen
 *  Purpose:  To display the tree in post-order manner;  This function is public
 ******************************************************************************/
template <class T1, class T2>
void BST<T1, T2>::showPostOrder()
{
   displayPostOrder(mRootNode);
}