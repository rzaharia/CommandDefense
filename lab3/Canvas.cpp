#include "Canvas.h"
#include<stdarg.h>
#include<iostream>

Canvas::Canvas(int lines, int columns)
{

	this->lines = lines;
	this->columns = columns;
	 
	matrix = new char* [lines];
	for (int i = 0; i < lines; i++)
		matrix[i] = new char [columns];


	clear();
}

void Canvas::set_pixel(int x, int  y, char v)
{
	this->matrix[x][y] = v;
}


void Canvas::set_pixels(int count, ...)
{
	va_list list;
	va_start(list, count); 
	int x ,y ,z ; 
	for (int i = 0; i < count; i++)
	{

		x = va_arg(list, int);
		y = va_arg(list, int);
		z  = va_arg(list, int);
		set_pixel(x, y, z); //set the pixel 

	}

	va_end(list);

}

void Canvas::clear()
{

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			this->matrix[i][j] = ' ';
	}


}


void Canvas::print() const
{

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << this->matrix[i][j]<<" ";

		std::cout <<std::endl;
	}


}