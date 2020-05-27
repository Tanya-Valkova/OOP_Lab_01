#pragma once

class TemperatureValue
{
public:
	virtual double Value(int* source, int n) = 0;
};