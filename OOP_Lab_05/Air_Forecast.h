#pragma once
#include "Weather_Forecast.h"

class Air_Forecast : public Weather_Forecast
{
private:
	int Temperature;
	int Pressure;
	int Humidity;
	double Wind;

	char* AirForecast() const;

public:
	Air_Forecast();
	Air_Forecast(const char* Place, const char* Date,
				 int Temperature, int Pressure,
				 int Humidity, double Wind);
	~Air_Forecast();

	int GetTemperature() const;
	int GetPressure() const;
	int GetHumidity() const;
	double GetWind() const;

	void SetTemperature(const int temperature);
	void SetPressure(const int pressure);
	void SetHumidity(const int humidity);
	void SetWind(const double wind);

	bool GetRain() const;
	bool GetSnow() const;
	bool GetHail() const;

	char* Print();

	Air_Forecast& operator()(const char* place, const char* date,
							 const int temperature, const int pressure, 
							 const int humidity, const double wind);
};