#include "WeatherForecast.h"
#include "MaxTemperature.h"
#include "AverageTemperature.h"
#include "MinTemperature.h"

void FindMaxTemperature(WeatherForecast& weather);
void FindAverageTemperature(WeatherForecast& weather);
void FindMinTemperature(WeatherForecast& weather);

using namespace std;

int main()
{
	system("chcp 1251"); 
	try
	{
		WeatherForecast a("Lviv", 7);
		a[0] = 13;
		a[1] = 10;
		a[2] = 15;
		a[3] = 20;
		a[4] = 17;
		a[5] = 21;
		a[6] = 14;
		cout << a;

		FindMaxTemperature(a);
		FindAverageTemperature(a);
		FindMinTemperature(a);
	}
	catch (const char* message)
	{
		cout << "\n\n Error: " << message << endl;
	}
	return 0;
}

void FindMaxTemperature(WeatherForecast& weather)
{
	MaxTemperature* max = new MaxTemperature;
	weather.SetChoose(max);
	cout << "\n Max value of temperature: " << weather.FindValue() << "°C" << endl;
}

void FindAverageTemperature(WeatherForecast& weather)
{
	AverageTemperature* average = new AverageTemperature;
	weather.SetChoose(average);
	cout << "\n Average value of temperature: " << weather.FindValue() << "°C" << endl;
}

void FindMinTemperature(WeatherForecast& weather)
{
	MinTemperature* min = new MinTemperature;
	weather.SetChoose(min);
	cout << "\n Min value of temperature: " << weather.FindValue() << "°C" << endl;
}