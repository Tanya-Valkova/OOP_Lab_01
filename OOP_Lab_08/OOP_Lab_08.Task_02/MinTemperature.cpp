#include "MinTemperature.h"

double MinTemperature::Value(int* source, int n)
{
	int min_temperature = source[0];
	int temperature = 0;
	for (int i = 1; i < n; i++)
	{
		temperature = source[i];

		if (min_temperature > temperature)
		{
			min_temperature = temperature;
		}
	}
	return min_temperature;
}