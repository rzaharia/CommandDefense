#include "Wave.h"

//implementation of Wave.h methods 



/// <summary>
/// Wave class constructor 
/// </summary>
/// <param name="name">Name of the wave </param>
/// <param name="numberOfEnemies">Number of enemies </param>
/// <param name="initialHealth">initial health of the wave</param>
/// <param name="MoneyPer">Money earned for each enemy killed </param>
Wave::Wave(string name, int numberOfEnemies, int initialHealth, float MoneyPer)
{

	this->name = name;
	this->numberOfEnemies = numberOfEnemies;
	this->initialHealth = initialHealth;
	this->moneyPerEnemy = MoneyPer;



}

//GET and SET methods for class attributes	
string  Wave::nameGetter()
{

	return this->name;

}

void Wave::nameSetter(string new_name)
{

	this->name = new_name;

}

int Wave::numberOfEnemies_Getter()
{

	return this->numberOfEnemies;

}

void Wave::numberOfEnemies_Setter(int new_val)
{
	this->numberOfEnemies = new_val;
}

int Wave::initialHealth_Getter()
{
	return this->initialHealth;
}
void Wave::initialHealth_Setter(int new_val)
{
	this->initialHealth = new_val;
}

float Wave::moneyPerEnemy_Getter()
{
	return this->moneyPerEnemy;
}

void Wave::moneyPerEnemy_Setter(float new_val)
{
	this->moneyPerEnemy = new_val;
}