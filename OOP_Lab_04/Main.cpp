#include "Weather_Forecast.h"
#include "Air_Forecast.h"
#define N 5

void WeatherInformation(Air_Forecast* source);
double AverageTemperature(Air_Forecast* source);
int MaxWind(Air_Forecast* source);
int MaxHumidity(Air_Forecast* source);
int MinHumidity(Air_Forecast* source);

int main()
{
	system("chcp 1251"); // using only for per cent (°)
	try
	{
		Air_Forecast a[N];
		a[0]("Lviv", "22.03.2020", -2, 731, 100, 0.0);
		a[1]("Lviv", "29.03.2020", 15, 729, 56, 5.0);
		a[2]("Lviv", "05.04.2020", 10, 730, 52, 1.0);
		a[3]("Lviv", "12.04.2020", 12, 740, 26, 3.4);
		a[4]("Lviv", "19.04.2020", 14, 737, 22, 3.2);

		for (int i = 0; i < N; i++)
		{
			cout << a[i];
		}
		WeatherInformation(a);
		
		Air_Forecast b("Kyiv", "17.04.2020", 10, 743, 28, 4.1);
		cout << b;
	}
	catch (const char* message)
	{
		cout << "\n\nError: " << message << endl;
	}
	return 0;
}

void WeatherInformation(Air_Forecast* source)
{
	double average_temperature = AverageTemperature(source);
	int max_wind = MaxWind(source);
	int max_humidity = MaxHumidity(source);
	int min_humidity = MinHumidity(source);

	cout
		<< "\n\n\t" <<"   Weather information:" << endl
		<< " -----------------------------------------" << endl
		<< " Average air temperature: " << "\t" << average_temperature << "°C" << endl
		<< " Day with maximum wind speed: " << "\t" << source[max_wind].GetDate() << endl
		<< " Day with maximum humidity: " << "\t" << source[max_humidity].GetDate() << endl
		<< " Day with minimum humidity: " << "\t" << source[min_humidity].GetDate() << endl
		<< " -----------------------------------------" << endl;
}

double AverageTemperature(Air_Forecast* source) 
{
	double sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum = sum + source[i].GetTemperature();
	}
	return(sum / N);
}

int MaxWind(Air_Forecast* source)
{ 
	int windy_day = 0;
	double wind = 0.0;
	double max_wind = source[0].GetWind();

	for (int i = 1; i < N; i++)
	{
		wind = source[i].GetWind();

		if (wind > max_wind)
		{
			windy_day = i;
			max_wind = wind;
		}
	}
	return windy_day;
}

int MaxHumidity(Air_Forecast* source)
{
	int max_humidity = source[0].GetHumidity();
	int humidity = 0, max_value = 0;

	for (int i = 1; i < N; i++)
	{
		humidity = source[i].GetHumidity();

		if (humidity > max_humidity)
		{
			max_value = i;
			max_humidity = humidity;
		}
	}
	return max_value;
}

int MinHumidity(Air_Forecast* source)
{
	int min_humidity = source[0].GetHumidity();
	int humidity = 0, min_value = 0;

	for (int i = 1; i < N; i++)
	{
		humidity = source[i].GetHumidity();

		if (humidity < min_humidity)
		{
			min_value = i;
			min_humidity = humidity;
		}
	}
	return min_value;
}