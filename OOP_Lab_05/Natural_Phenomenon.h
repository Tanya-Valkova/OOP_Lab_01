#pragma once
#include "Weather_Forecast.h"

class Natural_Phenomenon : public Weather_Forecast
{
private:
	bool Precipitation;
	bool Rain;
	bool Snow;
	bool Hail;
	bool Thunder;
	bool Lightning;

	char* NaturalPhenomenon() const;

public:
	Natural_Phenomenon();
	Natural_Phenomenon(const char* place, const char* date,
					   bool precipitation);
	Natural_Phenomenon(const char* place, const char* date, 
				   	   bool precipitation, bool rain, bool snow, bool hail,
					   bool thunder, bool lightning);
	~Natural_Phenomenon();

	bool GetPrecipitation() const;
	bool GetRain() const;
	bool GetSnow() const;
	bool GetHail() const;
	bool GetThunder() const;
	bool GetLightning() const;

	void SetPrecipitation(const bool precipitation);
	void SetRain(const bool rain);
	void SetSnow(const bool snow);
	void SetHail(const bool hail);
	void SetThunder(const bool thunder);
	void SetLightning(const bool lightning);

	int GetTemperature() const;
	int GetPressure() const;
	int GetHumidity() const;
	double GetWind() const;

	char* Print();

	Natural_Phenomenon operator()(const char* place, const char* date,
								  bool precipitation);
	Natural_Phenomenon operator()(const char* place, const char* date, 
								  bool precipitation, bool rain, bool snow, bool hail,
								  bool thunder, bool lightning);
};