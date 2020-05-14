#include "List.hpp"
#include "List_Item.hpp"

int main()
{
	List<char>* a = new List<char>;
	a->Push_Front('A');
	a->Push_Front('B');
	a->Push_Front('C');
	a->Push_Front('D');
	cout << *a;

	List<int>* b = new List<int>;
	b->Push_Back(1);
	b->Push_Back(3);
	b->Push_Back(5);
	b->Push_Back(7);
	b->Push_Back(9);
	cout << *b;
	b->Reverse();
	cout << *b;

	List<const char*>* c = new List<const char*>;
	c->Push_Front("See that girl");
	c->Push_Back("Watch that scene");
	c->Push_Front("Having the time of your life");
	c->Push_Back("Dig in the dancing queen");
	c->Push_Front("You can jive");
	c->Push_Front("You can dance");
	cout << *c;

	List<double>* d = new List<double>;
	d->Push_Back(1.2);
	d->Push_Back(3.4);
	d->Push_Back(5.6);
	d->Push_Back(7.8);
	d->Push_Back(9.1);

	cout << "\n Peek back: " << d->Peek_Back() << "\n" << endl;
	cout << "\n Peek front: " << d->Peek_Front() << "\n" << endl;

	while (!d->IsEmpty())
	{
		cout << "\n Pop: " << d->Pop() << "\n" << endl;
	}

	delete a;
	delete b;
	delete c;
	delete d;

	return 0;
}