#include "Dacia.h"



Dacia::Dacia( int fuel_cap, int fuel_cons)
{
	//std::cout << "constructor called";
	//std::cout << std::endl;
	SetAverageSpeed();
	SetFuelCapacity(fuel_cap);
	SetFuelConsumption(fuel_consumption);


}


int Dacia::Get_FuelConsumption()
{

  return this->fuel_consumption;

}

int Dacia::Get_FuelCapacity()
{

	return this->fuel_capacity;


}
Weather_Condition Dacia::GetWeather()
{
	return this->track_cond;
}

void Dacia::SetWeather(Weather_Condition cond)
{
	this->track_cond = cond;

}

int Dacia::Get_AverageSpeed()
{

	return this->average_speed;

}

void Dacia::SetFuelConsumption(int value)
{

	this->fuel_consumption = value;

}

void Dacia::SetFuelCapacity(int value)
{
	this->fuel_capacity = value;

}

void Dacia::SetAverageSpeed()
{
	//set the average speed that depends on the weather outside 
	// if sunny ----> value remains the same 
	// if rain ---> value - 10
	//if snow ----> value -20

	switch (this->GetWeather())
	{
	case Weather_Condition::Sunny:

		this->average_speed = 30;
		break;
	case Weather_Condition::Rainy:
		this->average_speed = 20;
		break;
	case Weather_Condition::Snowy:
		this->average_speed = 10;

	default:
		break;
	}


}
