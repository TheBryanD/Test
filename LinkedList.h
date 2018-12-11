/*
	Title: LinkedList.h
	Author: Bryan and Scout
	Date: 10/22/18
	Purpose: This is a header file to create a LinkedList class in order to make a dynamic list.
*/

#if !defined LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template<class T>
class LinkedList
{
	private:
		struct ListNode
		{
			T value;
			struct ListNode* next;
		};
		ListNode* head;
		ListNode* tail;
		int numNodes;
		
	public:
	//Constructor
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		numNodes = 0;
	}
	
	//Destructor
	~LinkedList()
	{
		ListNode* nodePointer;
		ListNode* nextPointer;
		
		nodePointer = head;
		while (nodePointer != NULL)
		{
			nextPointer = nodePointer->next;
			
			delete nodePointer;
			
			nodePointer = nextPointer;
		}
	}
	
	int getLength();
	T getNodeValue(int);
	void appendNode(T);
	void deleteNode(int);
};
	//Get Length
	
template<class T>
	int LinkedList<T>::getLength()
	{
		return numNodes;
	}
	
	//Get Node Value

	template<class T>
	T LinkedList<T>::getNodeValue(int index)
	{
		if (index >= 0)
		{
			ListNode* nodePointer;
			nodePointer = head;
			
			for (int i =0; i < index; i++)
			{
				nodePointer = nodePointer->next;
			}
			
			return nodePointer->value;
		}
		else
		{
			cout << "Please enter a positive value" << endl;
		}
	}
	
	//Append Node
	
template<class T>
	void LinkedList<T>::appendNode(T object)
	{
		ListNode* newNode;
		newNode = new ListNode;
		newNode->value = object;
		newNode->next = NULL;
		
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		numNodes++;
	}
	
	//Delete Node
template<class T>
	void LinkedList<T>::deleteNode(int index)
	{
	
		
		ListNode* nodePointer;
		ListNode* previousNode;
		int currentPosition;
		nodePointer = head;
		
		if (head == NULL)
		{
			return;
		}
		else
		{
	
			while (nodePointer != NULL && currentPosition < index)
			{
				previousNode = nodePointer;
				nodePointer = nodePointer->next;
				currentPosition++;
			}
			
			if (currentPosition == index)
			{
				previousNode->next = nodePointer->next;
				delete nodePointer;
				numNodes--;
			}		
		
	}
}

#endif