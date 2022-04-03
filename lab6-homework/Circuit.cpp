#include "Circuit.h"
#include <iostream>	
#include "Weather.h"
using namespace std;


/// <summary>
/// Circuit constructor
/// </summary>
/// <param name="cars_on_track"></param>
/// <param name="circuit_cond"></param>
Circuit :: Circuit( int cars_on_track , Weather_Condition circuit_cond  , int circuit_length)
{

 
	this->max_cars = cars_on_track; // maximum cars allowed on the track
	this->ptr_car = new Car * [max_cars]; // allocate memory for maximum cars
	this->weather = circuit_cond; // weather condition on track
	this->circuit_length = circuit_length;
}
/// <summary>
/// destructor that deallocates memory 
/// </summary>
Circuit::~Circuit()
{
	delete[] ptr_car;
}

/// <summary>
/// Adds the car to the array with the given parameters 
/// </summary>
/// <param name="car"></param>
/// <param name="fuel_cons"></param>
/// <param name="fuel_capac"></param>
/// <param name="aver_speed"></param>
/// <returns></returns>
bool Circuit::AddCar( Car * car )
{
	if (this->no_of_cars < this->max_cars)
	{
		
		//cout << "viteza masinii" << no_of_cars << car->Get_FuelCapacity();
		//set the Weather field of every car the same with circuit weather
		ptr_car[no_of_cars++] = car;
		car->SetWeather(this->weather);
		return true;
	}

	return false;

}


/// <summary>
/// helper function to print the cars 
/// </summary>
void Circuit::Print_Cars()
{
	int max = this->no_of_cars;
	for (int i = 0; i < max; i++)
	{
		cout << this->ptr_car[i]->Get_AverageSpeed()<< "car1" << endl;
    }
}

/// <summary>
/// Change the Weather field of the circuit 
/// </summary>
/// <param name="value"></param>
void Circuit::ChangeWeather(Weather_Condition value)
{
	this->weather = value;
}

void Circuit::Race()
{

	//implement simple logic to race 
	int count = this->no_of_cars;
	for (int i = 0; i < count; i++)
	{
		//for every car remember the time it takes to finish the race 
	this->ptr_car[i]->finish_time = this->circuit_length / this->ptr_car[i]->Get_AverageSpeed();
	
	}


	/// ................................RACE ENDED ! ---->STATS 
}

void Circuit::ShowFinalRanks()
{

	//print for each car the time it takes to finish 
	for (int i = 0; i < this->no_of_cars; i++)
	{
		cout << "The car number" << " " << i+1 << " " << "finished in" << " " << this->ptr_car[i]->finish_time << " minutes" << endl;

	}


}

