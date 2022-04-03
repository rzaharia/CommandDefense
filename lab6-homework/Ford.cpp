#include "Ford.h"
#include "Ford.h"




Ford::Ford(int fuel_cap, int fuel_cons)
{
	//std::cout << "constructor called";
	//std::cout << std::endl;
	 SetAverageSpeed();
	SetFuelCapacity(fuel_cap);
	SetFuelConsumption(fuel_consumption);


}

int Ford::Get_FuelConsumption()
{

	return this->fuel_consumption;

}

int Ford::Get_FuelCapacity()
{

	return this->fuel_capacity;


}
Weather_Condition Ford::GetWeather()
{
	return this->track_cond;
}

void Ford::SetWeather(Weather_Condition cond)
{
	this->track_cond = cond;

}
int Ford::Get_AverageSpeed()
{

	return this->average_speed;

}

void Ford::SetFuelConsumption(int value)
{

	this->fuel_consumption = value;

}

void Ford::SetFuelCapacity(int value)
{
	this->fuel_capacity = value;

}

void Ford::SetAverageSpeed()
{
	//set the average speed that depends on the weather outside 
	// if sunny ----> value remains the same 
	// if rain ---> value - 10
	//if snow ----> value -20
	switch (this->GetWeather())
	{
	case Weather_Condition::Sunny:

		this->average_speed = 45;
		break;
	case Weather_Condition::Rainy:
		this->average_speed = 35;
		break;
	case Weather_Condition::Snowy:
		this->average_speed = 25;

	default:
		break;
	}


}