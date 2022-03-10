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


void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[x][y] = ch;

}

void Canvas::DrawRect(int left, int top , int right, int bottom, char ch)
{

	//draw the border of the rectange 

	for (int i = left; i < right; i++)
	{
		matrix[top][i] = ch;
		matrix[bottom][i] = ch;
	}
	

	for (int i = top; i <= bottom; i++)
	{
		matrix[i][left] = ch;
		matrix[i][right] = ch;
	}
}

/// <summary>
/// Fill the rectangle with given 'char ch'
/// </summary>
/// <param name="left"></param>
/// <param name="top"></param>
/// <param name="right"></param>
/// <param name="bottom"></param>
/// <param name="ch"></param>
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i < right; i++)
	{
		for (int j = top; j < bottom; j++)
		{
			matrix[i][j] = ch;
		}
	}




}
 

