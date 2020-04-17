#pragma once
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Weather_Forecast
{
private:
	char* Place;
	char* Date;

protected:
	char* Copy(const char* source);

public:
	Weather_Forecast();
	Weather_Forecast(const char* place, const char* date);
	~Weather_Forecast();

	char* GetPlace() const;
	char* GetDate() const;
	void SetPlace(const char* place);
	void SetDate(const char* date);

	Weather_Forecast& operator()(const char* place, const char* date);
	friend ostream& operator<<(ostream& out, const Weather_Forecast& other);
};