#include "Cone.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

Cone::Cone()
{
	cout << "*Constructor*" << endl;
	radius = 0;
	height = 0;
}

Cone::~Cone()
{
	cout << "\n*Destructor*" << endl;
}

int Cone::GetRadius()
{
	return this->radius;
}

int Cone::SetRadius(int R)
{
	if (R <= 0)
	{
		throw "Incorrect value of the radius";
	}
	this->radius = R;
}

int Cone::GetHeight()
{
	return this->height;
}

int Cone::SetHeight(int Height)
{
	if (Height <= 0)
	{
		throw "Incorrect value of the height";
	}
	this->height = Height;
}

double Cone::Volume()
{
	double volume;
	volume = (1.0 / 3.0) * (M_PI * radius * radius * height);
	return volume;
}

double Cone::Square()
{
	double square;
	square = M_PI * radius * sqrt(radius * radius + height * height) + M_PI * radius * radius;
	return square;
}
