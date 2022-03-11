#include "Canvas.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	Canvas c(50, 50);
	c.Clear();
	//c.DrawRect(1,1, 5,5, '*');
	//c.FillRect(10, 10, 20, 20, '*');
	//c.DrawCircle(10,10, 4, '-');
	//c.FillCircle(10, 10, 4, '-');
	c.DrawLine(10, 10, 20, 20, '*');
	c.Print();

}