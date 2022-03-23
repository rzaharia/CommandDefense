#include "Complex.h"


void Complex::set_ImagData(double setval)
{
    this->imag_data = setval;
}
 
void Complex::set_RealData(double setval)
{
    this->real_data = setval;
}


bool double_equals(double l, double r)
{
    return abs(l - r) < 0.001;
}

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag)
{
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const
{
    return imag() == 0;
}

double Complex::real() const
{
    return real_data;
}

double Complex::imag() const
{
    return imag_data;
}

double Complex::abs() const
{
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const
{
    return { real(), -imag() };
}

Complex operator+(const Complex& left, const Complex& right)
{       
    return { left.real() + right.real() ,left.imag() + right.imag() };
}

Complex operator+(const Complex& left, double r)
{
    return { left.real() + r ,  left.imag() };
}

Complex operator+(double left, const Complex& r)
{

    return { r.real() + left , r.imag() };


}

Complex operator-(const Complex& obj) //inversul numarului complex 
{

    return { obj.real() * -1 , obj.imag() * -1 };

}

bool operator==(const Complex& left, const Complex& right)
{

    if (left.real() == right.real() && left.imag() == right.imag()) return true;

    return false;
}


bool operator!=(const Complex& left, const Complex& right)
{

    if (left.real() != right.real() || left.imag() != right.imag()) return true;


    return false;
}


Complex operator*(const Complex& left, const Complex& right)
{
    //a+bi * c+di  = a*c + -1*b*d + (  b*c + a*d )i
    
   return { (left.real() * right.real()) + (left.imag() + right.imag()) * -1, (left.real() * right.imag()) + (left.imag() * right.real()) };
} 

Complex operator*(const Complex& left, double right)
{



}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{



}