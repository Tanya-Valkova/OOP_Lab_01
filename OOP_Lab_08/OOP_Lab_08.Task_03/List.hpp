#pragma once 
#include <iostream>
#include "ListItem.hpp"
#include "Iterator.hpp"

using namespace std;

template <typename T> class Iterator;
template <typename T> class List
{
private:
	int Size;
	ListItem<T>* Head;
	ListItem<T>* Tail;

	void Delete();
public:
	List();
	~List();

	int GetSize() const;
	void Push_Front(T item);
	void Push_Back(T item);
	bool IsEmpty() const;
	Iterator<T> Begin();
	Iterator<T> End();
};

template<typename T> void List<T>::Delete()
{
	ListItem<T>* pointer = this->Head;
	ListItem<T>* next_item;
	for (int i = 0; i < this->Size; i++)
	{
		next_item = pointer->GetNext();
		delete pointer;
		pointer = next_item;
	}
}

template <typename T> List<T>::List()
{
	cout << " *Constructor List*" << endl;
	this->Size = 0;
	this->Head = nullptr;
	this->Tail = nullptr;
}

template<typename T> List<T>::~List()
{
	cout << " *Destructor List*" << endl;
	Delete();
}

template<typename T> int List<T>::GetSize() const
{
	return this->Size;
}

template<typename T> void List<T>::Push_Front(T item)
{
	if (this->Size == 0)
	{
		this->Head = new ListItem<T>(item, nullptr);
		this->Tail = Head;
		this->Size = 1;
	}
	else
	{
		ListItem<T>* newitem = new ListItem<T>(item, nullptr);
		newitem->SetNext(this->Head);
		this->Head = newitem;
		this->Size += 1;
	}
}

template<typename T> void List<T>::Push_Back(T item)
{
	if (this->Size == 0)
	{
		this->Head = new ListItem<T>(item, nullptr);
		this->Tail = Head;
		this->Size = 1;
	}
	else
	{
		ListItem<T>* newitem = new ListItem<T>(item, nullptr);
		this->Tail->SetNext(newitem);
		this->Tail = newitem;
		this->Size += 1;
	}
}

template<typename T> bool List<T>::IsEmpty() const
{
	return (this->Size == 0);
}

template<typename T> Iterator<T> List<T>::Begin()
{
	Iterator<T> begin (this, this->Head);
	return begin;
}

template<typename T> Iterator<T> List<T>::End()
{
	Iterator<T> end(this, nullptr);
	return end;
}