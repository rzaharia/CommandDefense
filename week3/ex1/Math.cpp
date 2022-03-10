#include "Math.h"
#include <stdarg.h>
#include <string.h>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{


	return a + b + c;
}

int Math::Add(double a, double b)
{



	return int(a + b);
}

int Math::Add(double a, double b, double c)
{
	return int(a + b + c);
}

int Math::Mul(int a, int b)
{

	return a * b;



}

int Math::Mul(int a, int b, int c)
{

	return a * b * c;


}

int Math::Mul(double a, double b)
{

	return int(a * b);

}


int Math::Mul(double a, double b, double c)
{

	return int(a * b * c);
	

}


int Math::Add(int n, ...)
{

	int sum = 0; 

	va_list ptr; 
	va_start(ptr, n);
	for (int i = 0; i < n; i++)
	{


		sum += va_arg(ptr, int);
	}
	va_end(ptr);
	return sum;

}

char* Add(const char* a, const char* b )
{

	if (a == nullptr) return nullptr;
	if (b == nullptr) return nullptr; 

	char *buffer = new char [strlen(a) + strlen(b) +1 ];

	strcpy(buffer, a);
	strcpy(buffer, b);

	buffer[strlen(a) + strlen(b) + 1] = NULL;

	return buffer; 

}
