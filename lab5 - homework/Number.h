#pragma once
class Number
{ 
	char* value = nullptr;  //pointer to the memory allocated to the value 
	int base;
public :
	Number(const char* val_to_be_set, int base);
	Number(const Number & other); // copy constructor 
	Number(const Number&& source); // move constructor 
	~Number(); //destructor 
	void SwitchBase(int newBase);
	void Print(); //print the current value 
	int GetDigitsCount(); //return the digits count of the value 
	int GetBase(); // return the current base 
	friend  Number operator+( Number& left,  Number& right); 
	friend Number operator-( Number& left , Number& right );
	bool operator<(Number& other);
	bool operator>( Number& other);
	bool operator<=( Number& other);
	bool operator>=( Number& other);
	bool operator==( Number& other);
	bool operator!=( Number& other);
	Number operator--();
	Number operator++();
};

