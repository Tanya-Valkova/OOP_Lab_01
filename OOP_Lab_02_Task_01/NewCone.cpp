#include "NewCone.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

void NewCone::InitCone(int number, double radius, double height)
{
	this->number = number;
	this->radius = new double[this->number];
	this->height = new double[this->number];
	for (int i = 0; i < this->number; i++)
	{
		this->radius[i] = radius;
		this->height[i] = height;
	}
}
NewCone::NewCone()
{
	cout << "\n*Constructor*" << endl;
	InitCone(1, 1, 1);
}
NewCone::NewCone(int n)
{
	this->number = n;
	cout << "\n*Constructor*" << endl;
	InitCone(this->number, 1, 1);
}

NewCone::NewCone(int number, double radius, double height)
{
	InitCone(number, radius, height);
	cout << "\n*Constructor with parameters*" << endl;

}

NewCone::NewCone(const NewCone& source)
{
	cout << "\n*Constructor copy*" << endl;
	this->number = source.number;
	this->radius = new double [this->number];
	this->height = new double[this->number];
	for (int i = 0; i < this->number; i++)
	{
		this->height[i] = source.height[i];
		this->radius[i] = source.radius[i];
	}
}

NewCone::~NewCone()
{
	cout << "\n*Destructor*" << endl;
	delete[] this->height;
	delete[] this->radius;
}

int NewCone::GetNumber()
{
	return this->number;
}

void NewCone::SetNumber(int Number)
{
	if (Number <= 0)
	{
		throw "Incorrect value of the number";
	}
	this->number = Number;
}

double NewCone::GetRadius(int n)
{

	return this->radius[n];
}

void NewCone::SetRadius(int n, double Radius)
{
	if (Radius <= 0)
	{
		throw "Incorrect value of the radius";
	}
	this->radius[n] = Radius;
}

double NewCone::GetHeight(int n)
{
	return this->height[n];
}

void NewCone::SetHeight(int n,double Height)
{
	if (Height <= 0)
	{
		throw "Incorrect value of the height";
	}
	this->height[n] = Height;
}

double NewCone::Volume(int n)
{
	double volume;
	volume = (1.0 / 3.0) * (M_PI * this->radius[n] * this->radius[n] * this->height[n]);
	return volume;
}

double NewCone::Square(int n)
{
	double square;
	square = M_PI * this->radius[n] * sqrt(this->radius[n] * this->radius[n] + this->height[n] * this->height[n]) + M_PI * this->radius[n] * this->radius[n];
	return square;
}