#include "Air_Forecast.h"

char* Air_Forecast::AirForecast() const
{
	char tmp[10];
	char* sentence = new char[100];
	strcpy(sentence, "");
	strcat(sentence, "\n Temperature:\t");
	sprintf(tmp, "%d", this->GetTemperature());
	strcat(sentence, tmp);
	strcat(sentence, "°C");
	strcat(sentence, "\n Pressure:\t");
	sprintf(tmp, "%d", this->GetPressure());
	strcat(sentence, tmp);
	strcat(sentence, " mm");
	strcat(sentence, "\n Humidity:\t");
	sprintf(tmp, "%d", this->GetHumidity());
	strcat(sentence, tmp);
	strcat(sentence, "%");
	strcat(sentence, "\n Wind:\t\t");
	sprintf(tmp, "%.1lf", this->GetWind());
	strcat(sentence, tmp);
	strcat(sentence, " m/s");
	return sentence;
}

Air_Forecast::Air_Forecast() : Weather_Forecast()
{
	cout << " *Constructor Air forecast*" << endl;
	this->Temperature = 0;
	this->Pressure = 760;
	this->Humidity = 0;
	this->Wind = 0.0;
}

Air_Forecast::Air_Forecast(const char* place, const char* date,
						   const int temperature, const int pressure,
						   const int humidity, const double wind) 
						   : Weather_Forecast(place, date)
{
	cout << " *Constructor Air forecast with parameters*" << endl;

	if (temperature > 60 || temperature < -90)
	{
		throw "Incorrect value of temperature";
	}
	this->Temperature = temperature;

	if (pressure > 850 || pressure < 660)
	{
		throw "Incorrect value of pressure";
	}
	this->Pressure = pressure;

	if (humidity > 100 || humidity < 0)
	{
		throw "Incorrect value of humidity";
	}
	this->Humidity = humidity;

	if (wind > 100 || wind < 0)
	{
		throw "Incorrect value of wind speed";
	}
	this->Wind = wind;
}

Air_Forecast::~Air_Forecast()
{
	cout << "\n *Destructor Air forecast*" << endl;
}

int Air_Forecast::GetTemperature() const
{
	return this->Temperature;
}

int Air_Forecast::GetPressure() const
{
	return this->Pressure;
}

int Air_Forecast::GetHumidity() const
{
	return this->Humidity;
}

double Air_Forecast::GetWind() const
{
	return this->Wind;
}

bool Air_Forecast::GetRain() const
{
	return false;
}

bool Air_Forecast::GetSnow() const
{
	return false;
}

bool Air_Forecast::GetHail() const
{
	return false;
}

void Air_Forecast::SetTemperature(const int temperature)
{
	if (temperature>60 || temperature<-90)
	{
		throw "Incorrect value of temperature";
	}
	this->Temperature = temperature;
}

void Air_Forecast::SetPressure(const int pressure)
{
	if (pressure > 850 || pressure < 660)
	{
		throw "Incorrect value of pressure";
	}
	this->Pressure = pressure;
}

void Air_Forecast::SetHumidity(const int humidity)
{
	if (humidity>100 || humidity<0)
	{
		throw "Incorrect value of humidity";
	}
	this->Humidity = humidity;
}

void Air_Forecast::SetWind(const double wind)
{
	if (wind>100 || wind < 0)
	{
		throw "Incorrect value of wind speed";
	}
	this->Wind = wind;
}

char* Air_Forecast::Print()
{
	char* data = new char[250];
	strcpy(data, "\n\tWeather forecast:");
	strcat(data, "\n -------------------------------");
	strcat(data, "\n Place:\t\t");
	strcat(data, this->GetPlace());
	strcat(data, "\n Date:\t\t");
	strcat(data, this->GetDate());
	strcat(data, "\n -------------------------------");
	strcat(data, this->AirForecast());
	strcat(data, "\n -------------------------------\n\n");
	return data;
}

Air_Forecast& Air_Forecast::operator()(const char* place, const char* date, 
									   const int temperature, const int pressure, 
									   const int humidity, const double wind)
{
	SetPlace(this->Copy(place));
	SetDate(this->Copy(date));
	SetTemperature(temperature);
	SetPressure(pressure);
	SetHumidity(humidity);
	SetWind(wind);
	return *this;
}