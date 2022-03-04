#pragma once
#include <string>
using namespace std;
class Wave
{
private:
	string name; 
	int numberOfEnemies; 
	int initialHealth;
	float moneyPerEnemy;

public:
	Wave(string name, int numberOfEnemies, int initialH, float moneyPer); //class constructor 

	void nameSetter(string new_name); // name setter  
	string nameGetter();  //name getter 

	void numberOfEnemies_Setter(int new_val); // setter
	int  numberOfEnemies_Getter(); //getter

	void initialHealth_Setter(int new_val);  //setter
	int initialHealth_Getter(); //getter 

	void moneyPerEnemy_Setter(float new_val); //setter  
	float moneyPerEnemy_Getter(); //getter

};

