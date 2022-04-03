#include "Mercedes.h"





Mercedes::Mercedes( int fuel_cap, int fuel_cons)
{
	//std::cout << "constructor called";
	//std::cout << std::endl;
	SetAverageSpeed();
	SetFuelCapacity(fuel_cap);
	SetFuelConsumption(fuel_consumption);


}

int Mercedes::Get_FuelConsumption()
{

	return this->fuel_consumption;

}

Weather_Condition Mercedes::GetWeather()
{
	return this->track_cond;
}

void Mercedes::SetWeather(Weather_Condition cond)
{
	this->track_cond = cond;

}
int Mercedes::Get_FuelCapacity() 
{

	return this->fuel_capacity;


}

int Mercedes::Get_AverageSpeed() 
{

	return this->average_speed;

}

void Mercedes::SetFuelConsumption(int value) 
{

	this->fuel_consumption = value;

}

void Mercedes::SetFuelCapacity(int value)  
{
	this->fuel_capacity = value;

}

void Mercedes::SetAverageSpeed() 
{
	//set the average speed that depends on the weather outside 
	// if sunny ----> value remains the same 
	// if rain ---> value - 10
	//if snow ----> value -20
	switch (this->GetWeather())
	{
	case Weather_Condition::Sunny:

		this->average_speed = 60;
		break;
	case Weather_Condition::Rainy:
		this->average_speed = 50;
		break;
	case Weather_Condition::Snowy:
		this->average_speed = 40;

	default:
		break;
	}


}
