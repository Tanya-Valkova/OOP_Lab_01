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

char* Weather_Forecast::Copy(const char* source)
{
	int n = strlen(source) + 1;
	char* destination = new char[n];
	strcpy_s(destination, n, source);
	return destination;
}

Weather_Forecast& Weather_Forecast::operator()(const char* place, const char* date)
{
	SetPlace(place);
	SetDate(date);
	return *this;
}

ostream& operator<<(ostream& out, const Weather_Forecast& other)
{
	out
		<< "\n\n\t" << "Weather forecast:" << endl
		<< " -------------------------------" << endl
		<< " " << "Place:" << "\t\t" << other.GetPlace() << endl
		<< " " << "Date:" << "\t\t" << other.GetDate() << endl
		<< " -------------------------------\n" << endl;

	return out;
}