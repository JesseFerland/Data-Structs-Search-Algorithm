/*
Author:      Jesse Ferland
Class: CS1 281 <Section 2>
Assignment:  pa 4
Date Assigned: 2/17/12
Due Date: 2/24/12 2:00pm
Description: Using Binary Search Trees
Certification of Authenticity:
I certify that this assignment is entirely my own work.
*/

#include <iostream>
#include <iomanip>
#include "bst.h"
#include "bst.cpp"

using namespace std;

int main()
{
   BST<int> tree;

   cout << "Inserting:  5\n";
   tree.insert(5);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  8\n";
   tree.insert(8);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  3\n";
   tree.insert(3);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  12\n";
   tree.insert(12);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  9\n";
   tree.insert(9);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   system("pause");
   system("cls");

   cout << "Testing isExist:\n";
   cout << "\tSearching for 10:  " << (tree.isExists(10) ? "Found" : "Not Found") << endl;
   cout << "\tSearching for 12:  " << (tree.isExists(12) ? "Found" : "Not Found") << endl;

   system("pause");
   system("cls");

   /////////////////////////// I added this code ///////////////////////////
   cout << "Testing countNodes:\n";
   cout << setw(25) << "Number of nodes: " << tree.countNodes() << endl;

   cout << "Testing countLeaves:\n";
   cout << setw(25) << "Number of leaves: " << tree.countLeaves() << endl;

   system("pause");
   system("cls");

   cout << "Testing height:\n";
   cout << setw(25) << "Height: " << tree.height() << endl;

   system("pause");
   system("cls");

   cout << "Testing printPath:\n";
   cout << "Path to 5: " << endl;
   tree.printPath(5);
   cout << endl;
   cout << "Path to 3: " << endl;
   tree.printPath(3);
   cout << endl;
   cout << "Path to 8: " << endl;
   tree.printPath(8);
   cout << endl;
   cout << "Path to 12: " << endl;
   tree.printPath(12);
   cout << endl;
   cout << "Path to 9: " << endl;
   tree.printPath(9);
   cout << endl;

   system("pause");
   system("cls");
   /////////////////////////// I added this code ///////////////////////////


   cout << "Testing remove:\n";
   cout << setw(25) << "Original Tree:  ";
   tree.showInOrder();
   cout << endl;
   cout << setw(25) << "After Removing 12:  ";
   tree.remove(12);
   tree.showInOrder();
   cout << endl;
   cout << setw(25) << "After Removing 5:  ";
   tree.remove(5);
   tree.showInOrder();
   cout << endl;
   cout << setw(25) << "After Removing 1:  ";
   tree.remove(1);
   tree.showInOrder();
   cout << endl;

   system("pause");
   return 0;
}