//Створити шаблонний клас – однозв’язний лінійний список у динамічній пам’яті.
//Тип елементів списку визначається параметром шаблона(цілі числа, дійсні числа, символи або символьні рядки).
//Передбачити функції для виконання таких операцій : створення нового елемента списку на його початку, 
//створення нового елемента списку у його кінці, переставлення елементів списку у зворотному порядку, 
//виведення списку на екран.

#include "List.hpp"
#include "List_Item.hpp"

int main()
{
	List<char> a;
	a.Push_Front('A');
	a.Push_Front('B');
	a.Push_Front('C');
	a.Push_Front('D');
	cout << a;

	List<char> b;
	b.Push_Back('A');
	b.Push_Back('B');
	b.Push_Back('C');
	b.Push_Back('D');
	cout << b;
	b.Inverse();
	cout << b;

	cout << "\n Peek back: " << a.Peek_Back() << endl;
	cout << "\n Peek front: " << a.Peek_Front() << endl;

	cout << "\n Pop front: " << a.Pop_Front() << endl;
	cout << "\n Pop back: " << a.Pop_Back() << endl;

	return 0;
}