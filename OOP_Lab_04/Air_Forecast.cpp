#include "Air_Forecast.h"

Air_Forecast::Air_Forecast() : Weather_Forecast()
{
	cout << " *Constructor Air forecast*" << endl;
	this->Temperature = 0;
	this->Pressure = 760;
	this->Humidity = 0;
	this->Wind = 0.0;
}

Air_Forecast::Air_Forecast(
				const char* place,
				const char* date,
				const int temperature,
				const int pressure,
				const int humidity,
				const double wind) : Weather_Forecast(place, date)
{
	cout << " *Constructor Air forecast with parameters*\n" << endl;

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

Air_Forecast& Air_Forecast::operator()(
					const char* place, 
					const char* date, 
					const int temperature, 
					const int pressure, 
					const int humidity, 
					const double wind)
{
	SetPlace(this->Copy(place));
	SetDate(this->Copy(date));
	SetTemperature(temperature);
	SetPressure(pressure);
	SetHumidity(humidity);
	SetWind(wind);

	return *this;
}

ostream& operator<<(ostream& out, const Air_Forecast& other)
{
	out
		<< "\n\n\t" << "Weather forecast:" << endl
		<< " -------------------------------" << endl
		<< " " << "Place:" << "\t\t" << other.GetPlace() << endl
		<< " " << "Date:" << "\t\t" << other.GetDate() << endl
		<< " -------------------------------" << endl
		<< " " << "Temperature:" << "\t" << other.GetTemperature() << "°C" << endl
		<< " " << "Pressure:" << "\t" << other.GetPressure() << " mm" << endl
		<< " " << "Humidity:" << "\t" << other.GetHumidity() << "%" << endl
		<< " " << "Wind:" << "\t\t" << other.GetWind() << " m/s" << endl
		<< " -------------------------------" << endl;

	return out;
}