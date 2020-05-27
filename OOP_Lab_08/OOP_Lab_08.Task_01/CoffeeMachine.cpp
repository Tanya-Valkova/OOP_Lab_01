#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(string coffeedrink, int sugar)
{
	cout << "\n *Contructor CoffeeMachine*" << endl;

	if (coffeedrink.size() == 0)
	{
		throw "Incorrect kind of coffee drink";
	}
	this->CoffeeDrink = coffeedrink;

	if (sugar > 10 || sugar < 0)
	{
		throw "Incorrect amount of sugar";
	}
	this->Sugar = sugar;
}

CoffeeMachine::~CoffeeMachine()
{
	cout << "\n *Destructor CoffeeMachine*" << endl;
}

string CoffeeMachine::GetCoffeeDrink()
{
	return this->CoffeeDrink;
}

int CoffeeMachine::GetSugar()
{
	return this->Sugar;
}

CoffeeMachine* CoffeeMachine::Instance(string coffeedrink, int sugar)
{
	cout << "\n *Instance*" << endl;
	static CoffeeMachine instance(coffeedrink, sugar);
	return &instance;
}

ostream& operator<<(ostream& out, CoffeeMachine*& instance)
{
	if (instance->GetSugar() == 0)
	{
		out
			<< "\n Your " << instance->GetCoffeeDrink()
			<< " without sugar is ready. Bon appetit!" << endl;
		return out;
	}
	else if (instance->GetSugar() == 1)
	{
		out
			<< "\n Your " << instance->GetCoffeeDrink()
			<< " with 1 sugar sachet is ready. Bon appetit!" << endl;
		return out;
	}
	else
	{
		out
			<< "\n Your " << instance->GetCoffeeDrink()
			<< " with " << instance->GetSugar()
			<< " sugar sachets is ready. Bon appetit!" << endl;
		return out;
	}
}