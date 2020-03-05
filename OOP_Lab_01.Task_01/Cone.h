#pragma once

class Cone
{
private:
	int radius;
	int height;
public:
	Cone();
	~Cone();

	int GetRadius();
	int SetRadius(int Radius);
	int GetHeight();
	int SetHeight(int Height);

	double Volume();
	double Square();
};

