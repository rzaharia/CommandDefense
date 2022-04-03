#pragma once
#include "Car.h"	
class Audi : public Car
{

	
public :

	int Get_FuelConsumption() override  final  ;

	int Get_FuelCapacity()override final ;

	int Get_AverageSpeed() override final;

	Weather_Condition GetWeather() override final;

	void SetFuelConsumption(int value)override final;

	void SetFuelCapacity(int value) override final;

	void SetAverageSpeed()override final;
	
	void SetWeather(Weather_Condition cond) override final; 

	Audi(int fuel_cap, int fuel_cons);
	Audi(); //default constructor 
};

