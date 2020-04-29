#include "Weather_Forecast.h"

Weather_Forecast::Weather_Forecast()
{
	cout << "\n *Constructor Weather forecast*" << endl;
	this->Place = nullptr;
	this->Date = nullptr;
}

Weather_Forecast::Weather_Forecast(const char* place, const char* date)
{
	cout << "\n *Constructor Weather forecast with parameters*" << endl;

	if (strlen(place) == 0)
	{
		throw "Incorrect place";
	}
	this->Place = Copy(place); 

	if (strlen(date) == 0)
	{
		throw "Incorrect date";
	}
	this->Date = Copy(date);
}

Weather_Forecast::~Weather_Forecast()
{
	cout << " *Destructor Weather forecast*" << endl;
	delete[] this->Place;
	delete[] this->Date;
}

bool Weather_Forecast::GetSnow() const
{
	return false;
}

bool Weather_Forecast::GetRain() const
{
	return false;
}

bool Weather_Forecast::GetHail() const
{
	return false;
}

char* Weather_Forecast::GetPlace() const
{
	return this->Place;
}

char* Weather_Forecast::GetDate() const
{
	return this->Date;
}

void Weather_Forecast::SetPlace(const char* place)
{
	if (strlen(place) == 0)
	{
		throw "Incorrect place";
	}
	this->Place = Copy(place);
}

void Weather_Forecast::SetDate(const char* date)
{
	if (strlen(date) == 0)
	{
		throw "Incorrect date";
	}
	this->Date = Copy(date);
}

int Weather_Forecast::GetTemperature() const
{
	return -100;
}

int Weather_Forecast::GetPressure() const
{
	return 750;
}

int Weather_Forecast::GetHumidity() const
{
	return 200;
}

double Weather_Forecast::GetWind() const
{
	return 0.0;
}

char* Weather_Forecast::Copy(const char* source)
{
	int n = strlen(source) + 1;
	char* destination = new char[n];
	strcpy_s(destination, n, source);
	return destination;
}

char* Weather_Forecast::Print()
{
	char* data = new char[500];
	strcpy(data, "\n\tWeather forecast:");
	strcat(data, "\n -------------------------------");
	strcat(data, "\n Place:\t\t");
	strcat(data, this->GetPlace());
	strcat(data, "\n Date:\t\t");
	strcat(data, this->GetDate());
	strcat(data, "\n -------------------------------\n\n");
	return data;
}

Weather_Forecast& Weather_Forecast::operator()(const char* place, const char* date)
{
	SetPlace(place);
	SetDate(date);
	return *this;
}