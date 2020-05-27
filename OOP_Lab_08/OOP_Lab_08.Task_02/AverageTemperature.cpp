#include "AverageTemperature.h"

double AverageTemperature::Value(int* source, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + source[i];
	}
	return(sum / (double)n);
}