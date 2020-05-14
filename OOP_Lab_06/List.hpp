#pragma once

#include <iostream>
#include "List_Item.hpp"

using namespace std;

template <typename T> class List
{
private:
	int Size;
	List_Item<T>* Head;
	List_Item<T>* Tail;

	void Delete();
public:
	List();
	~List();

	int GetSize() const;
	void Push_Front(T item);
	void Push_Back(T item);
	T Peek_Front() const; 
	T Peek_Back() const;
	T Pop_Front();
	T Pop_Back();
	bool IsEmpty() const;
	void Inverse();
	List_Item<T>* GetBegin();
	List_Item<T>* GetEnd();


	template<typename T> friend ostream& operator<< (ostream& out, const List<T>& list);
};

template<typename T> void List<T>::Delete()
{
	List_Item<T>* pointer = this->Head;
	List_Item<T>* next_item;
	for (int i = 0; i < this->Size; i++)
	{
		next_item = pointer->GetNext();
		delete pointer;
		pointer = next_item;
	}
}

template <typename T> List<T>::List()
{
	cout << " *List Constructor*" << endl;
	this->Size = 0;
	this->Head = nullptr;
	this->Tail = nullptr;
}

template<typename T> List<T>::~List()
{
	cout << " *List Destructor*" << endl;
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
		this->Head = new List_Item<T>(item, nullptr);
		this->Tail = Head;
		this->Size = 1;
	}
	else
	{
		List_Item<T>* new_item = new List_Item<T>(item, nullptr);
		new_item->SetNext(this->Head);
		this->Head = new_item;
		this->Size += 1;
	}
}

template<typename T> void List<T>::Push_Back(T item)
{
	if (this->Size == 0)
	{
		this->Head = new List_Item<T>(item, nullptr);
		this->Tail = Head;
		this->Size = 1;
	}
	else
	{
		List_Item<T>* new_item = new List_Item<T>(item, nullptr);
		this->Tail->SetNext(new_item);
		this->Tail = new_item;
		this->Size += 1;
	}
}

template<typename T> T List<T>::Peek_Front() const
{
	if (this->Size == 0)
	{
		throw "This list does not contain items";
	}
	List_Item<T>* item = this->Head;
	T get_item = item->GetItem();
	return get_item;
}

template<typename T> T List<T>::Peek_Back() const
{ 
	if (this->Size == 0)
	{
		throw "This list does not contain items";
	}
	List_Item<T>* item = this->Tail;
	T get_item = item->GetItem();
	return get_item;
}

template<typename T> T List<T>::Pop_Front()
{
	if(this->Size == 0)
	{
		throw "This list does not contain items";
	}

	if (this->Size == 1)
	{
		List_Item <T>* item = this->Head;
		this->Head = nullptr;
		this->Tail = nullptr;
		T deleted_item = item->GetItem();
		delete item;
		this->Size -= 1;
		return deleted_item;
	}
	else
	{
		List_Item <T>* item = this->Head;
		this->Head = item->GetNext();
		T deleted_item = item->GetItem();
		delete item;
		this->Size -= 1;
		return deleted_item;
	}
}

template<typename T> T List<T>::Pop_Back()
{
	if (this->Size == 0)
	{
		throw "This list does not contain items";
	}

	if (this->Size == 1)
	{
		List_Item <T>* item = this->Tail;
		this->Head = nullptr;
		this->Tail = nullptr;
		T deleted_item = item->GetItem();
		delete item;
		this->Size -= 1;
		return deleted_item;
	}
	else
	{
		List_Item <T>* item = this->Tail;
		this->Tail = item->GetNext();
		T deleted_item = item->GetItem();
		delete item;
		this->Size -= 1;
		return deleted_item;
	}
}

template<typename T> bool List<T>::IsEmpty() const
{
	return (this->Size() == 0);
}

template<typename T> void List<T>::Inverse()
{
	List_Item<T>* newNextItem = nullptr;
	List_Item<T>* oldHead = this->Head;
	this->Head = nullptr;
	while (oldHead != nullptr)
	{
		newNextItem = this->Head;
		this->Head = oldHead;
		oldHead = oldHead->GetNext();
		this->Head->SetNext(newNextItem);		
	}

	/*for (int i = 1; i < this->Size; i++)
	{		
		this->Head = oldHead->GetNext();
		newHead = this->Head->GetNext();
	}*/

	//List_Item<T>* newHead = this->Head;
	////List_Item<T>* oldHead = this->Head;
	//for (int i = 1; i < this->Size; i++)
	//{		
	//	this->Head = this->Head->GetNext();
	//	newHead = this->Head->GetNext();
	//}

//	//List<T> NewList;
//	List_Item<T>* NewPointer = this->Head;
//	List_Item<T>* pointer;
//	for(int i = 0; i < this->Size; i++)
//	{
//
//		//NewList.Push_Front(NewPointer->GetItem());
//		//NewPointer = NewPointer->GetNext();
//		pointer = NewPointer->GetNext();
//		NewPointer = 
//	}
//
//	NewPointer = this->Head;
//	pointer = NewList.GetBegin();
//	for (int i = 0; i < this->Size; i++)
//	{
//		NewPointer->SetItem(pointer->GetItem());
//		NewPointer = NewPointer->GetNext();
//		pointer = pointer->GetNext();
//	}
}

template<typename T> List_Item<T>* List<T>::GetBegin()
{
	return this->Head;
}

template<typename T> List_Item<T>* List<T>::GetEnd()
{
	return this->Tail;
}

template<typename T> ostream& operator<< (ostream& out, const List<T>& list)
{
	List_Item<T>* pointer = list.Head;
	out << "\n List:" << endl;
	for (int i = 0; i < list.Size; i++)
	{
	out << "\t" << pointer->GetItem() << endl;
		pointer = pointer->GetNext();
	}
	out << "\n" << endl;
	return out;
}