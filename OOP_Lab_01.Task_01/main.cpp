#include "Cone.h"

void Print(Cone& buff);

int main()
{
	try 
	{
		int r, h;
		Cone a;

		cout << "\nThe radius of the base of the cone: ";
		cin >> r;
		if (r <= 0)
		{
			throw "Incorrect value of the radius";
		}
		a.SetR(r);

		cout << "\nThe height of the cone: ";
		cin >> h;
		if (h <= 0)
		{
			throw "Incorrect value of the height";
		}
		a.SetH(h);

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
		cout << "\nThe radius of the base = " << buff.GetR() << " cm" << endl;
		cout << "\nThe height of the cone = " << buff.GetH() << " cm" << endl;
		cout << "\nThe volume of the cone = " << buff.Volume() << " cm^3" << endl;
		cout << "\nSurface area of the cone =  " << buff.Square() << " cm^2" << endl;
	}

