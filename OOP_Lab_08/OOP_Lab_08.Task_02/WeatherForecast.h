#pragma once
#include <iostream>
#include <string>
#include "TemperatureValue.h"

using namespace std;

class TemperatureValue;
class WeatherForecast
{
private:
	string City;
	int NumberOfDays;
	int* Temperature;
	TemperatureValue* Choice;

public:
	WeatherForecast(string city, int numberofdays);
	~WeatherForecast();
	
	string GetCity();
	int GetNumberOfDays();
	int GetTemperature(int n);
	void SetTemperature(int n, int temp);

	void SetChoose(TemperatureValue* choice);
	double FindValue();

	int& operator[](int n);
	friend ostream& operator<< (ostream& out, WeatherForecast& weather);
};