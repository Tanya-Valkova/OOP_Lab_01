#pragma once
#include "TemperatureValue.h"

class AverageTemperature : public TemperatureValue
{
	double Value(int* source, int n) override;
};