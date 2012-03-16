#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack
{
public: 
	
 /*
  * Pre: None
  * Post: A stack object has been created
  * Purpose: To construct the stack object
  */
	Stack();

 /*
  * Pre: None
  * Post: A stack object has been created with data
  * Purpose: To construct the stack object using passed in data
  */
	Stack( T data );

 /*
  * Pre: A stack object has been created
  * Post: A stack object has been deleted
  * Purpose: To delete the mpStacks pointer variable
  */
	~Stack();

 /*
  * Pre: A stack object has been created
  * Post: The contents of the stack have been displayed
  * Purpose: To display the stacks variables
  */
	void display();

 /*
  * Pre: A stack object has been created
  * Post: A bool has been returned
  * Purpose: To determine if there are any variables on the stack
  */
	bool isEmpty();

 /*
  * Pre: A stack object has been created
  * Post: A bool has been returned
  * Purpose: To determin if there is a specific variable on the stack
  */
	bool isExist( T searchKey );

 /*
  * Pre: A stack object has been created
  * Post: The last element of the stack has been deleted and returned
  * Purpose: To remove the last element of the stack and return it
  */
	T pop();

 /*
  * Pre: A stack object has been created
  * Post: Data has been added to the stack 
  * Purpose: To add data to the stack
  */
	void push( T data );

private:

	 T	        mData;
     Stack<T> *mNext;
	//vector<T>* mpStack;  //As the dummy doesnt have data, it doesnt matter what type it is initialized as

};

#endif