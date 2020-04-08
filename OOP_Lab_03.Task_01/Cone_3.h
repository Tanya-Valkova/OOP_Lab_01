#pragma once
#include <iostream>

using namespace std;

class Cone
{
private:
	double Radius;
	double Height;
public:
	Cone();
	Cone(const Cone& cone);
	Cone(double Radius, double Height);
	~Cone();

	double GetRadius() const;
	void SetRadius(double radius);
	double GetHeight() const;
	void SetHeight(double height);

	double Volume() const;

	friend Cone operator+(const Cone& addition_1, const Cone& addition_2);
	friend bool operator<(const Cone& c1, const Cone& c2);
	friend ostream& operator<< (ostream& out, const Cone& cone);
};