#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{

private :

	int circuit_length;
	int no_of_cars = 0;
	int max_cars;
	Car** ptr_car;
	Weather_Condition weather;
	
public :
	
	Circuit( int cars_on_track , Weather_Condition circuit_cond , int circuit_lengthci );

	~Circuit();
	
	bool AddCar(Car* value);
	void SetCarStats(Car& car); // set params for a given car 
	void Race();
	void ChangeWeather(Weather_Condition cond);
        void Print_Cars(); //prints the 
	void ShowFinalRanks(); //show the final leaderboard 
	void ShowWhoDidNotFinish();
	};


