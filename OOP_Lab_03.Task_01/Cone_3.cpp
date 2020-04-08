#include "Cone_3.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

Cone::Cone()
{
	cout << "*Constructor*" << endl;
	Radius = 0.0;
	Height = 0.0;
}

Cone::Cone(const Cone& cone)
{
	cout << "*Constructor copy*" << endl;
	this->Radius = cone.Radius;
	this->Height = cone.Height;
}

Cone::Cone(double Radius, double Height)
{
	cout << "*Constructor with parameters*" << endl;
	this->Radius = Radius;
	this->Height = Height;
}

Cone::~Cone()
{
	cout << "*Destructor*" << endl;
}

double Cone::GetRadius() const
{
	return this->Radius;
}


void Cone::SetRadius(double Radius)
{
	if (Radius <= 0)
	{
		throw "Incorrect value of the radius";
	}
	this->Radius = Radius;
}

double Cone::GetHeight() const
{
	return this->Height;
}

void Cone::SetHeight(double Height)
{
	if (Height <= 0)
	{
		throw "Incorrect value of the height";
	}
	this->Height = Height;
}

double Cone::Volume() const
{
	double volume;
	volume = (1.0 / 3.0) * (M_PI * this->Radius * this->Radius * this->Height);
	return volume;
}

bool operator<(const Cone& c1, const Cone& c2)
{
	return c1.Volume() < c2.Volume();
}

ostream& operator << (ostream& out, const Cone& cone)
{
	cout << "\nRadius = " << cone.GetRadius() << " cm, " << "Height = " << cone.GetHeight() << " cm, " 
		 << "Volume = " << cone.Volume() << " cm^3"<< endl;
	return out;
}

Cone operator+(const Cone& addition_1, const Cone& addition_2)
{
	Cone c(addition_1.GetRadius() + addition_2.GetRadius(), addition_1.GetHeight() + addition_2.GetHeight());
	return c;
}