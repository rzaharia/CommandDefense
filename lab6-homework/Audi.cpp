#include "Audi.h"
#include <iostream>
int Audi::Get_FuelConsumption() 
{

	return this->fuel_consumption;

}

Weather_Condition Audi::GetWeather()
{
	return this->track_cond;
}

int Audi::Get_FuelCapacity() 
{

	return this->fuel_capacity;


}

int Audi::Get_AverageSpeed() 
{

	return this->average_speed;

}

void Audi::SetFuelConsumption(int value) 
{

	this->fuel_consumption = value;

}

void Audi::SetFuelCapacity(int value) 
{
	this->fuel_capacity = value;

}

void Audi::SetAverageSpeed() 
{
	//set the average speed that depends on the weather outside 
	// if sunny ----> value remains the same 
	// if rain ---> value - 10
	//if snow ----> value -20
	switch (this->GetWeather())
	{
	case Weather_Condition::Sunny :
		
		this->average_speed = 50;
		break;
	case Weather_Condition ::Rainy:
		this->average_speed = 40;
		break;
	case Weather_Condition ::Snowy:
		this->average_speed = 30;

	default:
		break;
	}

}

void Audi::SetWeather(Weather_Condition cond)
{
	this->track_cond = cond;

}

Audi::Audi(int fuel_cap   , int fuel_cons  )
{
	//std::cout << "constructor called";
	//std::cout << std::endl;
	SetAverageSpeed();
	SetFuelCapacity(fuel_cap);
	SetFuelConsumption(fuel_consumption);


}