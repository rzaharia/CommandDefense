#include "canvas.h"
#include <iostream>
#include <cstdarg>
#include <iostream>

Canvas::Canvas(int lines, int columns)
{
    int a[10][10];
    m = new char*[lines];
    for (int i = 0; i < lines; i++)
    {
        m[i] = new char[columns];
    }
    this->lines = lines;
    this->columns = columns;
    clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < lines; i++)
        delete[] m[i];
    delete[] m;
}

void Canvas::set_pixel(int x, int y, char value)
{
    m[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
    std::va_list args;
    va_start(args, count);

    int x, y, value;
    for (int i = 0; i < count; i++)
    {
        x     = va_arg(args, int);
        y     = va_arg(args, int);
        value = va_arg(args, int);
        set_pixel(x, y, value);
    }

    va_end(args);
    // vaargs variadic args c++
}

void Canvas::clear()
{
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            m[i][j] = ' ';
}

void Canvas::print() const
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << m[i][j];
        std::cout << std::endl;
    }
}
