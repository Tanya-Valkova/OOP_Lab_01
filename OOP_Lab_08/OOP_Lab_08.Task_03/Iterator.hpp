#pragma once
#include "List.hpp"

template <typename T> class List;
template <typename T> class Iterator
{
private:
	List<T>* IteratorList;
	ListItem<T>* IteratorItem;

public:
	Iterator();
	Iterator(List<T>* iteratorlist, ListItem<T>* iteratoritem);
	~Iterator();

	const T GetIterItem();
	void SetIterItem(const T item);
	Iterator<T>& operator=(const Iterator<T> source);
	Iterator<T>& operator++(int);
	template <typename T> friend T& operator*(const Iterator<T> source);

	bool operator!=(const Iterator source);
};

template<typename T> Iterator<T>::Iterator()
{
	//*Constructor Iterator*
	this->IteratorList = nullptr;
	this->IteratorItem = nullptr;
}

template<typename T> Iterator<T>::Iterator(List<T>* iteratorlist, ListItem<T>* iteratoritem)
{
	//*Constructor Iterator with parameters*
	this->IteratorList = iteratorlist;
	this->IteratorItem = iteratoritem;
}

template<typename T> Iterator<T>::~Iterator()
{
	//*Destructor Iterator*
}

template<typename T> const T Iterator<T>::GetIterItem()
{
	return this->IteratorItem->GetItem();
}

template<typename T> void Iterator<T>::SetIterItem(const T item)
{
	this->IteratorItem->SetItem(item);
}

template<typename T> Iterator<T>& Iterator<T>::operator=(const Iterator<T> source)
{
	this->IteratorList = source.IteratorList;
	this->IteratorItem = source.IteratorItem;
}

template<typename T> Iterator<T>& Iterator<T>::operator++(int)
{
	this->IteratorItem = this->IteratorItem->GetNext();
	return *this;
}

template<typename T> bool Iterator<T>::operator!=(const Iterator source)
{
	return this->IteratorItem != source.IteratorItem;
}

template<typename T> T& operator*(const Iterator<T> source)
{
	return source.IteratorItem->GetItem();
}