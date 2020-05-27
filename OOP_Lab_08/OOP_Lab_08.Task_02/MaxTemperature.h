#pragma once
#include "TemperatureValue.h"

class MaxTemperature : public TemperatureValue
{
	double Value(int* source, int n) override;
};