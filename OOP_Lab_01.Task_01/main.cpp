//�������� ���� � �����.� ������� ������ ������� ���� � ����� ������ �� ������.
//��������� �����������, ����������, ���� ������� ���� � ��������� ���� �������, ��������� ���� �����, ���������� �ᒺ�� �� ����� ������� ������.
//������� ���� ������� ���� ����� ������ ��������� ���������� ���������, �� ���������.

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
		cout << "*���������� �����������*" << endl;
		R = 0;
		H = 0;
	}
	~Cone()
	{
		cout << "\n*���������� ����������*" << endl;
	}

	int GetR()
	{
		return R;
	}
	void SetR(int R)
	{
		if (R <= 0)
		{
			cout << "�������� ���������, �������� ������: ";
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
			cout << "�������� ���������, �������� ������: ";
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
		cout << "\n\n********* ���������� *********" << endl;
		cout << "\n����� ������ = " << GetR() << " ��" << endl;
		cout << "\n������ ������ = " << GetH() << " ��" << endl;
		cout << "\n��'�� ������ = " << Volume() << " �� ���." << endl;
		cout << "\n����� ������� ������ =  " << Square() << " �� ��." << endl;
	}
};

int main()
{
	int r, h;
	system("chcp 1251");
	Cone a;

	cout << "\n������ ����� ������ ������: ";
	do
	{
		cin >> r;
		if (r <= 0)
		{
			cout << "�������� ���������, �������� ������: ";
		}
	} while (r <= 0);
	a.SetR(r);

	cout << "\n������ ������ ������: ";
	do
	{
		cin >> h;
		if (h <= 0)
		{
			cout << "�������� ���������, �������� ������: ";
		}
	} while (h <= 0);
	a.SetH(h);

	a.Print();
}

