//Створити клас – конус.У закритій частині описати поля – радіус основи та висоту.
//Визначити конструктор, деструктор, зміни значень полів і отримання їхніх значень, виведення полів класу, обчислення об’єму та площі поверхні конуса.
//Функції зміни значень полів класу повинні перевіряти коректність параметрів, що задаються.

#include <stdlib.h>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Cone
{
private:
	int R;
	int H;

public:
	Cone()
	{
		cout << "*Визначений конструктор*" << endl;
		R = 0;
		H = 0;
	}
	~Cone()
	{
		cout << "\n*Визначений деструктор*" << endl;
	}

	int GetR()
	{
		return R;
	}
	void SetR(int R)
	{
		if (R <= 0)
		{
			cout << "Значення помилкове, повторіть спробу: ";
			return;
		}
		this->R = R;
	}

	int GetH()
	{
		return H;
	}
	void SetH(int H)
	{
		if (H <= 0)
		{
			cout << "Значення помилкове, повторіть спробу: ";
		}
		this->H = H;
	}

	double Volume()
	{
		double V;
		V = (1.0 / 3.0) * (M_PI * R * R * H);
		return V;
	}

	double Square()
	{
		double S;
		S = M_PI * R * sqrt(R * R + H * H) + M_PI * R * R;
		return S;
	}

	void Print()
	{
		cout << "\n\n********* Результати *********" << endl;
		cout << "\nРадіус основи = " << GetR() << " см" << endl;
		cout << "\nВисота конуса = " << GetH() << " см" << endl;
		cout << "\nОб'єм конуса = " << Volume() << " см куб." << endl;
		cout << "\nПлоща поверхні конуса =  " << Square() << " см кв." << endl;
	}
};

int main()
{
	int r, h;
	system("chcp 1251");
	Cone a;

	cout << "\nВведіть радіус основи конуса: ";
	do
	{
		cin >> r;
		if (r <= 0)
		{
			cout << "Значення помилкове, повторіть спробу: ";
		}
	} while (r <= 0);
	a.SetR(r);

	cout << "\nВведіть висоту конуса: ";
	do
	{
		cin >> h;
		if (h <= 0)
		{
			cout << "Значення помилкове, повторіть спробу: ";
		}
	} while (h <= 0);
	a.SetH(h);

	a.Print();
}

