#include "NewCone.h"
#include <iostream>

using namespace std;

void Print(NewCone* buff);

int main()
{
	try
	{
		int n = 0;
		double  radius = 0, height = 0;
		cout << "\nNumber of cones: ";
		do
		{
			cin >> n;
			if (n <= 0)
				cout << "\nThe number value is incorrect, try again: ";
		} while (n <= 0);

		NewCone* a = new NewCone(n);

		a->SetNumber(n);
				
		for (int i = 0; i < a->GetNumber(); i++)
		{	
			cout << "\nEnter the radius value of the cone #" << i+1 << ": ";
			do
			{ 
				cin >> radius;
				if (radius <= 0)
					cout << "\nThe value of radius is incorrect, try again: ";
			} while (radius <= 0);
			a->SetRadius(i, radius);
			cout << "\nEnter the height value of the cone #" << i + 1 << ": ";
			do
			{
				cin >> height;
				if (height <= 0)
					cout << "\nThe value of height is incorrect, try again: ";
			} while (height <= 0);
			a->SetHeight(i, height);
			
		}

		NewCone *b = new NewCone(*a);
		NewCone* c = new NewCone(2, 1.4, 2.5);

		Print(a);
		Print(b);
		Print(c);
		delete a;
		delete b;
		delete c;
	}
	catch (const char* massage)
	{
		cout << "Error:" << massage << endl;
	}
	return 0;
}

void Print(NewCone* buff)
{
	cout << "\n\n********* Results *********" << endl;
	for (int i = 0; i < buff->GetNumber(); i++)
	{
		cout << "\nCone #" << i+1 << endl;
		cout << "\nThe radius of the base = " << buff->GetRadius(i) << " cm" << endl;
		cout << "\nThe height of the cone = " << buff->GetHeight(i) << " cm" << endl;
		cout << "\nThe volume of the cone = " << buff->Volume(i) << " cm^3" << endl;
		cout << "\nSurface area of the cone =  " << buff->Square(i) << " cm^2" << endl;
		cout << "\n---------------------------------------\n" << endl;
	}
}

