#include "Cone_3.h"
#include <iostream>

#define N 5

using namespace std;

void Sorting(Cone a[N]);
Cone AverageValue(Cone a[N]);

int main()
{
	try
	{
		double radius, height;
		Cone a [N];
		
		for (int i = 0; i < N; i++)
		{
			cout << "\nThe radius of the base of the cone #"<< i + 1 << ": ";
			cin >> radius;
			if (radius <= 0)
			{
				throw "Incorrect value of the radius";
			}
			a[i].SetRadius(radius);

			cout << "The height of the cone #" << i + 1 << ": ";
			cin >> height;

			if (height <= 0.0)
			{
				throw "Incorrect value of the height";
			}
			a[i].SetHeight(height);
		}

		cout << "\n\n---------------------------------------------------\nBefore sorting:" << endl;
		for (int i = 0; i < N; i++)
		{
			cout << a[i];
		}
		cout << "---------------------------------------------------\n" << endl;

		Sorting(a);
		Cone value = AverageValue(a);

		cout << "\n---------------------------------------------------\nAfter sorting:" << endl;
		for (int i = 0; i < N; i++)
		{
			cout << a[i];
		}
		cout << "---------------------------------------------------" << endl;

		cout << "Average radius = " << value.GetRadius() << " cm " << "\nAverage height = " << value.GetHeight() << " cm " << endl;
		cout << "---------------------------------------------------\n" << endl;
	}
	catch (const char* massage)
	{
		cout << "Error:" << massage << endl;
	}
	return 0;
}

void Sorting(Cone a[N])
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i, k = i - 1; j > 0; j--, k--)
		{
			if (a[k] < a[j])
				swap(a[k], a[j]);
		}
	}
}

Cone AverageValue(Cone a[N])
{
	Cone sum, average_value;
	for (int i = 0; i < N; i++)
	{
		sum = sum + a[i];
	}

	average_value.SetRadius(sum.GetRadius() / N);
	average_value.SetHeight(sum.GetHeight() / N);

	return average_value;
}