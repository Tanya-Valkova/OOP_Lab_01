#pragma once

#include <iostream>

using namespace std;

template <typename T> class List_Item
{
private:
	T Item;
	List_Item<T>* Next;
public:
	List_Item(T item, List_Item<T>* next);
	~List_Item();

	const T GetItem() const;
	List_Item<T>* GetNext() const;
	void SetItem(const T item);
	void SetNext(List_Item<T>* next);
};

template<typename T> List_Item<T>::List_Item(T item, List_Item<T>* next)
{
	cout << " *List_Item Constructor*" << endl;
	this->Item = item;
	this->Next = next;
}

template<typename T> List_Item<T>::~List_Item()
{
	cout << " *List_Item Destructor" << endl;
}

template<typename T> const T List_Item<T>::GetItem() const
{
	return this->Item;
}

template<typename T> List_Item<T>* List_Item<T>::GetNext() const
{
	return this->Next;
}

template <typename T> void List_Item <T>::SetItem(const T item)
{
	this->Item = item;
}

template <typename T> void List_Item <T>::SetNext(List_Item<T>* next)
{
	this->Next = next;
}