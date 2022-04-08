// OOP - facultate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include  "Vector.h"
using namespace std;

class dog
{

};

long double  operator"" _kg(long double  val)
{

	return val * 1000;


}

long double operator"" _g(long double val)
{

	return val;
}


long double operator"" _mg(long double val)
{
	return val / 100;
}


long double operator"" _cels(long double val)
{

	return val;

}

long double operator"" _fahr(long double val)
{
	return (val * 1.8) + 32;
}

long double operator"" _kel(long double val)
{
	return val + 273.15;
}


int compare(const void* first_arg, const void* second_arg)
{
	int first = *(int*)first_arg;
	int second = *(int*)second_arg;
	if (first < second)
	{
		return -1;
	}
	else if (first == second)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}
int compare2(int a, int b)
{
	return a + b;

}

int a(int b, int c)
{
	return 2;
}


bool equal(char a, char b)
{

	return a == b; 

}
int main(int argc, char* argv[])
{
	long double kg = 20.0_kg;
	long double g = 13.0_g;

	Vector<int> my_int(41); //vector of 21 ints
	Vector<char> my_char(41); //vector of 21 intsd
	Vector<dog> my_dog(41); //vector of 21 intsd
	my_int.push(1);
	my_int.insert(1, 1);
	my_int.insert(2, 1);
	my_int.insert(3, 1);
	
	my_int.print();
	cout << my_int.count();
	my_int.push(10);
	my_int.push(12);
	my_int.print();
	cout << my_int.pop();
	my_int.print();


	my_char.push('c');
	my_char.push('c');
	my_char.push('c');
	my_char.push('c');
	my_char.push('d');
	my_char.push('a');
	my_char.push('a');
	my_char.push('a');
	my_int.sort(a);
	my_char.print();
	my_char.Set('z', 2);
	my_char.print();
	cout<<my_char.FirstIndexOf('z', equal);
}



