/*
Author:      Jesse Ferland
Class: CS1 281 <Section 2>
Assignment:  pa 3
Date Assigned: 2/3/12
Due Date: 2/10/12 2:00pm
Description: Using LinkedLists in a calculator program
Certification of Authenticity:
I certify that this assignment is entirely my own work.
*/

#include "LinkList.h"

template <class T>
LinkList<T>::LinkList()
{
   mNext = NULL;
}


template <class T>
LinkList<T>::LinkList(T data)
{
   mData = data;
   mNext = NULL;
}


template <class T>
LinkList<T>::~LinkList()
{
   LinkList<T> *tmp;

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
T LinkList<T>::getData()
{
   return mData;
}


template <class T>
LinkList<T> *LinkList<T>::getNext()
{
   return mNext;
}


template <class T>
void LinkList<T>::setData(T data)
{
   mData = data;
}

   
template <class T>
void LinkList<T>::display()
{
   LinkList<T> *tmp;

   tmp = mNext;
   while (tmp != NULL)
   {
      cout << tmp->mData << endl;
      tmp = tmp->mNext;
   }
}


template <class T>
void LinkList<T>::insert(T data)
{
   LinkList<T> *newNode, *tmp, *oneBefore;

   newNode = new LinkList(data);

   if (mNext == NULL)
      mNext = newNode;
   else
   {
      oneBefore = mNext;
      tmp = mNext;

      while (tmp != NULL && tmp->mData < data)
      {
         oneBefore = tmp;
         tmp = tmp->mNext;
      }
   
      if (tmp == mNext)
      {
         newNode->mNext = mNext;
         mNext = newNode;
      }
      else
      {
         oneBefore->mNext = newNode;
         newNode->mNext = tmp;
      }
   }
}


template <class T>
bool LinkList<T>::isExist(T data)
{
   bool        found = false;
   LinkList<T> *tmp;

   tmp = mNext;
   while (tmp != NULL)
   {
      if (tmp->mData == data)
      {
         found = true;
         break;
      }

      tmp = tmp->mNext;
   }

   return found;
}


template <class T>
void LinkList<T>::remove(T data)
{
   LinkList<T> *tmp, *oneBefore;

   if (!isExist(data))
      return;

   tmp = mNext;
   oneBefore = mNext;
   while (tmp->mData != data)
   {
      oneBefore = tmp;
      tmp = tmp->mNext;
   }

   if (tmp == mNext)
   {
      mNext = tmp->mNext;
      tmp->mNext = NULL;
   }
   else
   {
      if (tmp->mNext == NULL)
         oneBefore->mNext = NULL;
      else
      {
         oneBefore->mNext = tmp->mNext;
         tmp->mNext = NULL;
      }
   }

   delete tmp;
}

template <class T>
bool LinkList<T>::operator<(T rhs)
{
   return mData < rhs;
}


template <class T>
bool operator<(T lhs, LinkList<T> rhs)
{
   return lhs < rhs.mData;
}


template <class T>
bool LinkList<T>::operator>(T rhs)
{
   return mData > rhs;
}


template <class T>
bool operator>(T lhs, LinkList<T> rhs)
{
   return lhs > rhs.mData;
}


template <class T>
bool LinkList<T>::operator==(T rhs)
{
   return mData == rhs;
}


template <class T>
bool operator==(T lhs, LinkList<T> rhs)
{
   return lhs == rhs.mData;
}


template <class T>
bool LinkList<T>::operator!=(T rhs)
{
   return mData != rhs;
}


template <class T>
bool operator!=(T lhs, LinkList<T> rhs)
{
   return lhs != rhs.mData;
}


template <class T>
ostream& operator<<(ostream &outputStream, LinkList<T> obj)
{
   outputStream << obj.mData;

   return outputStream;
}