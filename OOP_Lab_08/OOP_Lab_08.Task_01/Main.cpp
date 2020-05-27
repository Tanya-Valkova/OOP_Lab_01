#include "CoffeeMachine.h"

int main()
{
	try
	{
		CoffeeMachine* drink = CoffeeMachine::Instance("Cappuccino", 1);
		CoffeeMachine* newdrink = CoffeeMachine::Instance("Latte", 3);

		cout << "\n -------------Cappuccino with 1 sugar sachet---------------" << endl;
		cout << drink;
		cout << "\n\n ----------Changed data: Latte with 3 sugar sachets--------" << endl;
		cout << newdrink;
	}
	catch (const char* message)
	{
		cout << "\n Error: " << message << endl;
	}
}