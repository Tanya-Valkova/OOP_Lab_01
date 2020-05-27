#pragma once 
#include <iostream>

using namespace std;

template <typename T> class ListItem
{
private:
	T Item;
	ListItem<T>* Next;

public:
	ListItem(T item, ListItem<T>* next);
	~ListItem();

	T& GetItem();
	ListItem<T>* GetNext() const;

	void SetItem(const T item);
	void SetNext(ListItem<T>* next);
};

template<typename T> ListItem<T>::ListItem(T item, ListItem<T>* next)
{
	cout << " *Constructor ListItem*" << endl;
	this->Item = item;
	this->Next = next;
}

template<typename T> ListItem<T>::~ListItem()
{
	cout << " *Destructor ListItem*" << endl;
}

template<typename T>  T& ListItem<T>::GetItem() 
{
	return this->Item;
}

template<typename T> ListItem<T>* ListItem<T>::GetNext() const
{
	return this->Next;
}

template <typename T> void ListItem <T>::SetItem(const T item)
{
	this->Item = item;
}

template <typename T> void ListItem <T>::SetNext(ListItem<T>* next)
{
	this->Next = next;
}