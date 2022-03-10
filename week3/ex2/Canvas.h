#pragma once
class Canvas
{
	char** matrix; 
	int columns;
	int lines;

public : 
	Canvas(int lines, int columns); //class constructor

	
	void set_pixel(int x, int y, char val);

	void set_pixels(int count, ...);

	void clear();

	void print() const;

	void DrawCircle(int x, int y, int ray, char ch);

	void FillCircle(int x, int y, int ray, char ch);

	void DrawRect(int left, int top, int right, int bottom, char ch);

	void FillRect(int left, int top, int right, int bottom, char ch);

	void SetPoint(int x, int y, char ch);

	void DrawLine(int x1, int y1, int x2, int y2, char ch);

	



};

