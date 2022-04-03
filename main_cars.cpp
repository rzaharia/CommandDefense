#include <iostream>
#include "Car.h"
#include "Audi.h"
#include "Mercedes.h"
#include "Weather.h"
#include "Dacia.h"
#include "Ford.h"
#include "Circuit.h"


using namespace std;

int main(int argc, char* argv[])
{

	Circuit  c(10, Weather_Condition::Snowy ,2000);  //weather is set into constructo --- no more setWeather method 
	c.AddCar(new Audi( 100, 100));
	c.AddCar(new Mercedes(252, 253));
	c.AddCar(new Dacia(122, 121));
	c.AddCar(new Dacia(122, 121));
	c.AddCar(new Ford(12, 12));
	c.AddCar(new Dacia(32, 43));
	c.AddCar(new Mercedes(122, 1221));
	c.AddCar(new Audi(122, 121));
	

	c.Race();
	c.ShowFinalRanks();
	
	
}







