#pragma once
class Canvas
{
	char** matrix; 
	int columns;
	int lines;

public : 
	Canvas(int lines, int columns);
	void set_pixel(int x, int y, char val);
	void set_pixels(int count, ...);
	void clear();
	void print() const;


};

