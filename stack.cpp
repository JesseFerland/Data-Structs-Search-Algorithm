/*
Author:      Jesse Ferland
Class: CS1 281 <Section 2>
Assignment:  pa 3
Date Assigned: 2/3/12
Due Date: 2/10/12 2:00pm
Description: Using stack in a calculator program
Certification of Authenticity:
I certify that this assignment is entirely my own work.
*/

#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"

template <class T>
Stack<T>::Stack()
{
	mData = T();
	mNext = NULL;
}

template <class T>
Stack<T>::Stack(T data)
{
   mData = data;
   mNext = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	Stack<T> *tmp;

   tmp = mNext;
   while (tmp != NULL)
   {
      mNext = tmp->mNext;
      tmp->mNext = NULL;
      delete tmp;
      tmp = mNext;
   }
}

template <class T>
void Stack<T>::display()
{
	Stack<T> *tmp;

   tmp = mNext;
   while (tmp != NULL)
   {
      cout << tmp->mData << endl;
      tmp = tmp->mNext;
   }
}

template <class T>
bool Stack<T>::isEmpty()
{
	Stack<T>* temp;
	temp = mNext; //First element
	if( temp == NULL ) //If the stack has not been created or if the first element is null
	{
		return true;
	}

	return false;
}

template <class T>
bool Stack<T>::isExist( T searchKey )
{
   bool        found = false;
   Stack<T> *tmp;

   tmp = mNext;
   while (tmp != NULL)
   {
      if (tmp->mData == searchKey)
      {
         found = true;
         break;
      }

      tmp = tmp->mNext;
   }

   return found;
}

template <class T>
T Stack<T>::pop()
{
	Stack<T> *temp, *oneBefore;
	temp = mNext; //First element
	
	T lastElement;

	if( temp->mNext == NULL ) //If only one element
	{
		lastElement = temp->mData;
		mNext = temp->mNext;
		temp->mNext = NULL;

		delete temp;
		temp = NULL;

		return lastElement;
	}

	else  //If more than one element
 	{

		while( temp->mNext != NULL )
		{		
			oneBefore = temp;
			temp = temp->mNext;
			lastElement = temp->mData;
		}

	   oneBefore->mNext = NULL;
	   delete temp;
	   temp = NULL;

		//Return it
		return lastElement;
	}
}

template <class T>
void Stack<T>::push( T data )
{
	Stack<T> *newNode, *tmp;

   newNode = new Stack(data);

   if (mNext == NULL)
      mNext = newNode;
   else
   {
      tmp = mNext;

	  while (tmp->mNext != NULL)
      {
         tmp = tmp->mNext;
      }

	  tmp->mNext = newNode;   
    
   }
}



#endif



