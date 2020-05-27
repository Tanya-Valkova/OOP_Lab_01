#include "List.hpp" 
#include "ListItem.hpp"

int main()
{
	List<char>* c = new List<char>; 
	c->Push_Front('/');
	c->Push_Back('D');
	c->Push_Front('C');
	c->Push_Back('C');
	c->Push_Front('A');

	cout << "\n List:" << endl;
	for (auto iterator = c->Begin(); iterator != c->End(); iterator++)
	{
		cout << "\t" << iterator.GetIterItem() << endl;
		iterator.SetIterItem('*');
	}

	cout << "\n List:" << endl;
	for (auto iterator = c->Begin(); iterator != c->End(); iterator++)
	{
		cout << "\t" << iterator.GetIterItem() << endl;
		
	}
	delete c;
	return 0;
}