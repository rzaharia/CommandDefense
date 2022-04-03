#include "Weather.h"
#ifndef CAR_H
#define CAR_H	

// Contents of your Package.h file
class Car
{
	/// <summary>
	/// pure abstract class ---> interface 
	/// </summary>

protected:
	int fuel_capacity;
	int fuel_consumption;
	int average_speed;
	Weather_Condition track_cond = Weather_Condition::Sunny ; //default weather 

public:

	// GETTER functions for 

	float finish_time = -1 ; //the time in which the car finishes the race 
	virtual Weather_Condition GetWeather() = 0;
	virtual int  Get_FuelConsumption() = 0;
	virtual int  Get_FuelCapacity() = 0;
	virtual int  Get_AverageSpeed() = 0;

	//SETTER functions for Car fields 
	virtual void SetWeather(Weather_Condition cond) = 0;
	virtual void SetFuelConsumption(int value) = 0;
	virtual void SetFuelCapacity(int value) = 0;
	virtual void SetAverageSpeed() = 0;

};

#endif
