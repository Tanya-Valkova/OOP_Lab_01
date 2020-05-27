#include "WeatherForecast.h"

WeatherForecast::WeatherForecast(string city, int numberofdays)
{
	cout << "\n *Constructor*" << endl;
	this->City = city;
	this->NumberOfDays = numberofdays;
	this->Temperature = new int(this->NumberOfDays);
}

WeatherForecast::~WeatherForecast()
{
	cout << "\n *Destructor*" << endl;
}

string WeatherForecast::GetCity()
{
	return this->City;
}

int WeatherForecast::GetNumberOfDays()
{
	return this->NumberOfDays;
}

int WeatherForecast::GetTemperature(int n)
{
	return this->Temperature[n];
}

void WeatherForecast::SetTemperature(int n, int temperature)
{
	if (n < 0)
	{
		throw "Incorrect n value!";
	}
	if (temperature < -70 || temperature > 65)
	{
		throw "Incorrect value of temperature!";
	}
	this->Temperature[n] = temperature;
}

void WeatherForecast::SetChoose(TemperatureValue* choice)
{
	if (choice == nullptr)
	{
		throw "Incorrect choice of value!";
	}
	this->Choice = choice;
}

double WeatherForecast::FindValue()
{
	double value = this->Choice->Value(this->Temperature, this->NumberOfDays);
	return value;
}

int& WeatherForecast::operator[](int n)
{
	return this->Temperature[n];
}

ostream& operator<<(ostream& out, WeatherForecast& weather)
{
	out.precision(3);
	out 
		<< "\n ---------------------------" << endl
		<< " Weather Forecast for " << weather.GetNumberOfDays() << " days" << endl
		<< " City: " << weather.GetCity() << endl
		<< " Temperature:" << endl;
	for (int i = 0; i < weather.GetNumberOfDays(); i++)
	{
		out
			<< "\tDay " << i + 1 << ": "
			<< weather.GetTemperature(i) << "°C" << endl;
	}
	out
		<< " ---------------------------" << endl;
	return out;
}