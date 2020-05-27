#pragma once
#include <iostream>
#include <string>

using namespace std;

class CoffeeMachine
{
private:
	string CoffeeDrink;
	int Sugar = 0;

	CoffeeMachine(string coffeedrink, int sugar);
	~CoffeeMachine();

public:
	string GetCoffeeDrink();
	int GetSugar();
	
	static CoffeeMachine* Instance (string coffeedrink, int sugar);
	friend ostream& operator<< (ostream& out, CoffeeMachine*& instance);
};