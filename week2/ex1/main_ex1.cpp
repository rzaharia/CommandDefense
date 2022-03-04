// OOP - facultate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EnemyController.h"

using namespace std;

int main()
{
	EnemyController controller; 
	Point initialPos;
	initialPos.x = 10;
	initialPos.y = 10;

	controller.Init(15, 2, initialPos);

	for (int i = 0; i < 15; i++)
	{
		controller.SpawnEnemy();
		cout << endl;
	}
	controller.PrintHealth();

	controller.DamageAll();
	cout << endl;
	controller.PrintHealth();

	int enemies_killed = controller.CountKilledEnemies();
	cout << "There are " << " " << enemies_killed << "killed \n";

}





