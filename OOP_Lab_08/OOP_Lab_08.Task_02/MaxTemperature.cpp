#include "MaxTemperature.h"

double MaxTemperature::Value(int* source, int n)
{
	int max_temperature = source[0];
	int temperature = 0;
	for (int i = 1; i < n; i++)
	{
		temperature = source[i];
	
		if (temperature > max_temperature)
		{
			max_temperature = temperature;
		}
	}
	return max_temperature;
}