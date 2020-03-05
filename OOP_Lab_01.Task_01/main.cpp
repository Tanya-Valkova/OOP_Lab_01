#include "Cone.h"
#include <iostream>

using namespace std;

void Print(Cone& buff);

int main()
{
	try 
	{
		int radius, height;
		Cone a;

		cout << "\nThe radius of the base of the cone: ";
		cin >> radius;
		if (radius <= 0)
		{
			throw "Incorrect value of the radius";
		}
		a.SetRadius(radius);

		cout << "\nThe height of the cone: ";
		cin >> height;
		if (height <= 0)
		{
			throw "Incorrect value of the height";
		}
		a.SetHeight(height);

	Print(a);
	}
	catch (const char* massage)
	{
		cout << "Error:" << massage << endl;
	}
	return 0;
}

	void Print(Cone& buff)
	{
		cout << "\n\n********* Results *********" << endl;
		cout << "\nThe radius of the base = " << buff.GetRadius() << " cm" << endl;
		cout << "\nThe height of the cone = " << buff.GetHeight() << " cm" << endl;
		cout << "\nThe volume of the cone = " << buff.Volume() << " cm^3" << endl;
		cout << "\nSurface area of the cone =  " << buff.Square() << " cm^2" << endl;
	}

