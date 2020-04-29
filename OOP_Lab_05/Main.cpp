#include "Weather_Forecast.h"
#include "Air_Forecast.h"
#include "Natural_Phenomenon.h"
#define N 7

void PrintWeatherForecast(Weather_Forecast** source);

void WeatherInformation(Weather_Forecast** source);
double AverageTemperature(Weather_Forecast** source);
int MaxWind(Weather_Forecast** source);
int MaxHumidity(Weather_Forecast** source);
int MinHumidity(Weather_Forecast** source);

void KindOfPrecipitation(Weather_Forecast** source, const char* precipitation);
int DaysWithRain(Weather_Forecast** source);
int DaysWithSnow(Weather_Forecast** source);
int DaysWithHail(Weather_Forecast** source);

int main()
{
	system("chcp 1251"); // using only for per cent (°)
	try
	{
		Weather_Forecast* a[N];
		a[0] = new Air_Forecast("Lviv", "20.04.2020", -2, 731, 100, 0.0);
		a[1] = new Natural_Phenomenon("Lviv", "20.04.2020", 1, 0, 1, 0, 0, 0);
		a[2] = new Air_Forecast("Kyiv", "25.04.2020", 14, 737, 22, 3.2);
		a[3] = new Natural_Phenomenon("Kyiv", "25.04.2020", 0);
		a[4] = new Air_Forecast("Lutsk", "30.04.2020", 10, 730, 52, 1.0);
		a[5] = new Natural_Phenomenon("Lutsk", "30.04.2020", 1);
		a[6] = new Weather_Forecast("Lutsk", "01.05.2020");

		PrintWeatherForecast(a);
		WeatherInformation(a);
		KindOfPrecipitation(a, "snow");
		KindOfPrecipitation(a, "rain");

		for (int i = 0; i < N; i++)
		{
			delete a[i];
		}
	}
	catch (const char* message)
	{
		cout << "\n\nError: " << message << endl;
	}
	return 0;
}

void PrintWeatherForecast(Weather_Forecast** source)
{
	for (int i = 0; i < N; i++)
	{
		char* tmp = source[i]->Print();
		cout << tmp;
		delete[] tmp;
	}
}

void KindOfPrecipitation(Weather_Forecast** source, const char* precipitation)
{
	cout << " ----------------------------" << endl;
	if (strstr(precipitation, "rain"))
	{
		cout << " " << "Number of days with rain: " << DaysWithRain(source) << endl;
	}
	if (strstr(precipitation, "snow"))
	{
		cout << " " << "Number of days with snow: " << DaysWithSnow(source) << endl;
	}
	if (strstr(precipitation, "hail"))
	{
		cout << " " << "Number of days with hail: " << DaysWithHail(source) << endl;
	}
	cout << " ----------------------------" << endl;
}

int DaysWithRain(Weather_Forecast** source)
{
	int num_of_days_with_rain = 0;
	for (int i = 0; i < N; i++)
	{
		if (source[i]->GetRain()==true)
		{
			num_of_days_with_rain++;
		}
	}
	return num_of_days_with_rain;
}

int DaysWithSnow(Weather_Forecast** source)
{
	int num_of_days_with_snow = 0;
	for (int i = 0; i < N; i++)
	{
		if (source[i]->GetSnow()==true)
		{
			num_of_days_with_snow++;
		}
	}
	return num_of_days_with_snow;
}

int DaysWithHail(Weather_Forecast** source)
{
	int num_of_days_with_hail = 0;
	for (int i = 0; i < N; i++)
	{
		if (source[i]->GetHail()==true)
		{
			num_of_days_with_hail++;
		}
	}
	return num_of_days_with_hail;
}

void WeatherInformation(Weather_Forecast** source)
{
	double average_temperature = AverageTemperature(source);
	int max_wind = MaxWind(source);
	int max_humidity = MaxHumidity(source);
	int min_humidity = MinHumidity(source);

	cout.precision(2);
	cout
		<< "\n\n\t" << "   Weather information:" << endl
		<< " -----------------------------------------" << endl
		<< " Average air temperature: " << "\t" << average_temperature << "°C" << endl
		<< " Day with maximum wind speed: " << "\t" << source[max_wind]->GetDate() << endl
		<< " Day with maximum humidity: " << "\t" << source[max_humidity]->GetDate() << endl
		<< " Day with minimum humidity: " << "\t" << source[min_humidity]->GetDate() << endl
		<< " -----------------------------------------" << endl;
}

double AverageTemperature(Weather_Forecast** source)
{
	double sum = 0;
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (source[i]->GetTemperature() > -90 &&
			source[i]->GetTemperature() < 60)
		{
			sum = sum + source[i]->GetTemperature();
			n++;
		}
	}
	return(sum / n);
}

int MaxWind(Weather_Forecast** source)
{ 
	int windy_day = 0;
	double wind = 0.0;
	double max_wind = source[0]->GetWind();

	for (int i = 1; i < N; i++)
	{
		wind = source[i]->GetWind();

		if (wind > max_wind)
		{
			windy_day = i;
			max_wind = wind;
		}
	}
	return windy_day;
}

int MaxHumidity(Weather_Forecast** source)
{
	int max_humidity = source[0]->GetHumidity();
	int humidity = 0, max_value = 0;

	for (int i = 1; i < N; i++)
	{	
		if (source[i]->GetHumidity() >= 0 &&
			source[i]->GetHumidity() <= 100)
		{
			humidity = source[i]->GetHumidity();

			if (humidity > max_humidity)
			{
				max_value = i;
				max_humidity = humidity;
			}
		}
	}
	return max_value;
}

int MinHumidity(Weather_Forecast** source)
{
	int min_humidity = source[0]->GetHumidity();
	int humidity = 0, min_value = 0;

	for (int i = 1; i < N; i++)
	{
		if (source[i]->GetHumidity() >= 0 &&
			source[i]->GetHumidity() <= 100)
		{
			humidity = source[i]->GetHumidity();

			if (humidity < min_humidity)
			{
				min_value = i;
				min_humidity = humidity;
			}
		}
	}
	return min_value;
}