#pragma once
class Hash
{
	// An abstract class Hash that has a method that calculates a hash from a string and returns the appropriate number type;
protected  : 
	char* ptr;
	long double hash_value;
	//use a struct to make a pair 
	virtual void CalculateHash(char* string) = 0; //pure abstract method 
		

};

