#pragma once

class NewCone
{
private:
	double* radius;
	double* height;
	int number;
	void InitCone(int n, double radius, double height);

public:
	NewCone();
	NewCone(int n);
	NewCone(int number, double radius, double height);
	NewCone(const NewCone& newcone);
	~NewCone();

	int GetNumber();
	void SetNumber(int Number);
	double GetRadius(int n);
	void SetRadius(int n,double Radius);
	double GetHeight(int n);
	void SetHeight(int n,double Height);
	double Volume(int n);
	double Square(int n);
};

