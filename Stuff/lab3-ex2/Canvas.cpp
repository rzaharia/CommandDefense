#include "Canvas.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
/// <summary>
/// Initialize the canvas 
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->matrix = (char**)(malloc(height * sizeof(char*)));
	for (int i = 0; i < height; i++)
		this->matrix[i] = (char*)(malloc(width * sizeof(char)));
	
}

/// <summary>
/// Drawing the circle
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="ray"></param>
/// <param name="ch"></param>
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	//(x,y)-centrul cercului
	//ray-raza
	
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				this->matrix[i][j] = ch;
			else
				this->matrix[i][j] = ' ';

	

}

/// <summary>
/// Filling in the circle
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="ray"></param>
/// <param name="ch"></param>
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray + 1))
				this->matrix[i][j] = ch;

}

/// <summary>
/// Drawing the rectangle
/// </summary>
/// <param name="left"></param>
/// <param name="top"></param>
/// <param name="right"></param>
/// <param name="bottom"></param>
/// <param name="ch"></param>
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		this->matrix[i][top] = ch;
		this->matrix[top][i] = ch;
		this->matrix[i][bottom] = ch;
		this->matrix[bottom][i] = ch;
	}

	for (int j = bottom; j <= left; j++)
	{
		this->matrix[j][right] = ch;
		this->matrix[right][j] = ch;
		this->matrix[j][left] = ch;
		this->matrix[left][j] = ch;
	}
}


/// <summary>
/// Filling in the rectangle
/// </summary>
/// <param name="left"></param>
/// <param name="top"></param>
/// <param name="right"></param>
/// <param name="bottom"></param>
/// <param name="ch"></param>
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			this->matrix[i][j] = ch;
}

/// <summary>
/// Setting a pixel
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="ch"></param>
void Canvas::SetPoint(int x, int y, char ch)
{
	this->matrix[x][y] = ch;
}


/// <summary>
/// Drawing a line
/// </summary>
/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
/// <param name="ch"></param>
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int m_new = 2 * (y2 - y1);
	int error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++)
	{
		SetPoint(x, y, '*');
		error_new += m_new;
		if (error_new >= 0)
		{
			y++;
			error_new -= 2 * (x2 - x1);
		}
	}
}


/// <summary>
/// Print the Canvas
/// </summary>
void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			cout << this->matrix[i][j];
		cout << endl;
	}
}

/// <summary>
/// Clear the Canvas
/// </summary>
void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->matrix[i][j] = ' ';

}