#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

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
	virtual ~Weather_Forecast();

	char* GetPlace() const;
	char* GetDate() const;
	void SetPlace(const char* place);
	void SetDate(const char* date);

	virtual int GetTemperature() const;
	virtual int GetPressure() const;
	virtual int GetHumidity() const;
	virtual double GetWind() const;

	virtual bool GetRain() const;
	virtual bool GetSnow() const;
	virtual bool GetHail() const;

	virtual char* Print();
	Weather_Forecast& operator()(const char* place, const char* date);
};