#pragma once
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
	Cone();
	~Cone();

	int GetR();
	int SetR(int R);
	int GetH();
	int SetH(int H);

	double Volume();
	double Square();
};

