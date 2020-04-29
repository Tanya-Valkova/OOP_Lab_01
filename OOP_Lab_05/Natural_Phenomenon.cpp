#include "Natural_Phenomenon.h"

char* Natural_Phenomenon::NaturalPhenomenon() const
{
	if (this->GetPrecipitation())
	{
		char* precipitation = new char[100];
		strcpy(precipitation, "\n Natural phenomena today:");

		if (this->GetRain()==true)
		{
			strcat(precipitation, "\n - rain");
		}
		if (this->GetSnow()==true)
		{
			strcat(precipitation, "\n - snow");
		}
		if (this->GetHail()==true)
		{
			strcat(precipitation, "\n - hail");
		}
		if (this->GetThunder()==true)
		{
			strcat(precipitation, "\n - thunder");
		}
		if (this->GetLightning()==true)
		{
			strcat(precipitation, "\n - lightning");
		}
		return precipitation;
	}
	else
	{
		char* without_precipitation = new char[40]; 
		strcpy(without_precipitation, "\n There is no precipitation today");
		return without_precipitation;
	}
}

Natural_Phenomenon::Natural_Phenomenon() : Weather_Forecast()
{
	cout << " *Constructor Natural Phenomenon*" << endl;
	this->Precipitation = 0;
	this->Rain = 0;
	this->Snow = 0;
	this->Hail = 0;
	this->Thunder = 0;
	this->Lightning = 0;
}

Natural_Phenomenon::Natural_Phenomenon(const char* place, const char* date, 
									   bool precipitation) : Weather_Forecast(place, date)
{
	cout << " *Constructor availability of Natural Phenomenon*" << endl;
	if(this->Precipitation = precipitation)
	{
		this->Rain = 1;
		this->Snow = 1;
		this->Hail = 1;
		this->Thunder = 1;
		this->Lightning = 1;
	}
	else
	{
		this->Rain = 0;
		this->Snow = 0;
		this->Hail = 0;
		this->Thunder = 0;
		this->Lightning = 0;
	}
}

Natural_Phenomenon::Natural_Phenomenon(const char* place, const char* date, 
									   bool precipitation, bool rain, bool snow, bool hail,
									   bool thunder, bool lightning) 
									   : Weather_Forecast(place, date)
{
	cout << " *Constructor Natural Phenomenon with parameters*" << endl;
	this->Precipitation = precipitation;
	this->Rain = rain;
	this->Snow = snow;
	this->Hail = hail;
	this->Thunder = thunder;
	this->Lightning = lightning;
}

Natural_Phenomenon::~Natural_Phenomenon()
{
	cout << "\n *Destructor Natural Phenomenon*" << endl;
}

bool Natural_Phenomenon::GetPrecipitation() const
{
	return this->Precipitation;
}

bool Natural_Phenomenon::GetRain() const
{
	return this->Rain;
}

bool Natural_Phenomenon::GetSnow() const
{
	return this->Snow;
}

bool Natural_Phenomenon::GetHail() const
{
	return this->Hail;
}

bool Natural_Phenomenon::GetThunder() const
{
	return this->Thunder;
}

bool Natural_Phenomenon::GetLightning() const
{
	return this->Lightning;
}

void Natural_Phenomenon::SetPrecipitation(const bool precipitation)
{
	this->Precipitation = precipitation;
}

void Natural_Phenomenon::SetRain(const bool rain)
{
	this->Rain = rain;
}

void Natural_Phenomenon::SetSnow(const bool snow)
{
	this->Snow = snow;
}

void Natural_Phenomenon::SetHail(const bool hail)
{
	this->Hail = hail;
}

void Natural_Phenomenon::SetThunder(const bool thunder)
{
	this->Thunder = thunder;
}

void Natural_Phenomenon::SetLightning(const bool lightning)
{
	this->Lightning = lightning;
}

int Natural_Phenomenon::GetTemperature() const
{
	return -100;
}

int Natural_Phenomenon::GetPressure() const
{
	return 750;
}

int Natural_Phenomenon::GetHumidity() const
{
	return 200;
}

double Natural_Phenomenon::GetWind() const
{
	return 0.0;
}

char* Natural_Phenomenon::Print()
{
	char* data = new char[250];
	strcpy(data, "\n\tWeather forecast:");
	strcat(data, "\n -------------------------------");
	strcat(data, "\n Place:\t\t");
	strcat(data, this->GetPlace());
	strcat(data, "\n Date:\t\t");
	strcat(data, this->GetDate());
	strcat(data, "\n -------------------------------");
	strcat(data, this->NaturalPhenomenon());
	strcat(data, "\n -------------------------------\n\n");
	return data;
}

Natural_Phenomenon Natural_Phenomenon::operator()(const char* place, const char* date, bool precipitation)
{
	SetPlace(this->Copy(place));
	SetDate(this->Copy(date));
	SetPrecipitation(precipitation);
	return Natural_Phenomenon();
}

Natural_Phenomenon Natural_Phenomenon::operator()(const char* place, const char* date,
												  bool precipitation, bool rain, bool snow, bool hail,
												  bool thunder, bool lightning)
{
	SetPlace(this->Copy(place));
	SetDate(this->Copy(date));
	SetPrecipitation(precipitation);
	SetRain(rain);
	SetSnow(snow);
	SetHail(hail);
	SetThunder(thunder);
	SetLightning(lightning);
	return Natural_Phenomenon();
}