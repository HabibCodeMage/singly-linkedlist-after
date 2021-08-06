#pragma once
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include<stddef.h>
#include<iostream>
using namespace std;
template<typename T>
class singlylinkedlist
{
private:
	struct listnode
	{
		T value;
		listnode* next;
	};
	listnode* head;
public:
	singlylinkedlist() :head(nullptr)
	{}
	void appendnode(const T&);
	void printvalues();
	void deletenode(const T&);
	void insertnode(const T&);
	void update(const T&, const T&);
	~singlylinkedlist();
};
#endif // !singlylinkedlist_H
template<typename T>
void singlylinkedlist<T>::appendnode(const T& value)
{
	listnode* createnode;
	createnode = new listnode;
	createnode->value = value;
	createnode->next = nullptr;
	listnode* traverse;
	if (!this->head)
	{
		this->head = createnode;
	}
	else
	{
		traverse = this->head;
		while (traverse->next)
		{

			traverse = traverse->next;
		}
		traverse->next = createnode;
	}
}
template<typename T>
void singlylinkedlist<T>::deletenode(const T& val)
{
	if (!head)
	{
		return;
	}
	listnode* nextnode = head,
		* previousnode = NULL;
	while (nextnode != NULL && nextnode->value != val)
	{
		previousnode = nextnode;
		nextnode = nextnode->next;
	}
	if (!previousnode)
	{

		head = nextnode->next;
		delete nextnode;
	}
	else if (nextnode)
	{
		previousnode->next = nextnode->next;
		delete nextnode;
	}
	else
	{
		cout << "no value found\n";
	}
}
template<typename T>
void singlylinkedlist<T>::insertnode(const T& val)
{
	listnode* createnode = new listnode{ val };
	createnode->next = NULL;
	if (!head)
	{
		head = createnode;
	}
	else
	{
		listnode* nextnode = head,
			* previousnode = NULL;
		while (nextnode != NULL && nextnode->value < val)
		{
			previousnode = nextnode;
			nextnode = nextnode->next;
		}
		if (!(previousnode))
		{
			previousnode = head;
			head = createnode;
			createnode->next = previousnode;
		}
		else
		{
			previousnode->next = createnode;
			createnode->next = nextnode;
		}

	}
}

template<typename T>
void singlylinkedlist<T>::printvalues()
{
	listnode* traverse = this->head;
	while (traverse)
	{
		cout << "value is:" << traverse->value << "\n";
		traverse = traverse->next;
	}
	return;

}
template<typename T>
singlylinkedlist<T>::~singlylinkedlist()
{
	listnode* traverse = head,
		* previous;

	while (traverse)
	{
		previous = traverse;
		traverse = traverse->next;
		delete previous;
	}

}
template<typename T>
void singlylinkedlist<T>::update(const T& value, const T& newvalue)
{
	if (this->head == NULL)
		cout << "empty linked list";
	
	listnode* temp = this->head;
	while (temp!=NULL && temp->value!=value)
	{
		temp = temp->next;
	}
	if (!temp)
		cout << "GIVEN VALUE DOES NOT EXIST IN LIST\n";
	temp->value = newvalue;
}
