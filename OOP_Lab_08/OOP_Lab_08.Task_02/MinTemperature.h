#pragma once
#include "TemperatureValue.h"

class MinTemperature : public TemperatureValue
{
	double Value(int* source, int n) override;
};