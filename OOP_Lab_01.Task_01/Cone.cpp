#include "Cone.h"

Cone::Cone()
{
	cout << "*Constructor*" << endl;
	R = 0;
	H = 0;
}

Cone::~Cone()
{
	cout << "\n*Destructor*" << endl;
}

int Cone::GetR()
{
	return this->R;
}

int Cone::SetR(int R)
{
	if (R <= 0)
	{
		throw "Incorrect value of the radius";
	}
	this->R = R;
}

int Cone::GetH()
{
	return this->H;
}

int Cone::SetH(int H)
{
	if (H <= 0)
	{
		throw "Incorrect value of the height";
	}
	this->H = H;
}

double Cone::Volume()
{
	double V;
	V = (1.0 / 3.0) * (M_PI * R * R * H);
	return V;
}

double Cone::Square()
{
	double S;
	S = M_PI * R * sqrt(R * R + H * H) + M_PI * R * R;
	return S;
}
