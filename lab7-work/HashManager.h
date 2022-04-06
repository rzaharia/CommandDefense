#pragma once
#include "Hash.h"
class HashManager
{
	HashManager(); //default constructor 

	HashManager(int size);  
	
	void print_hashes(); // print the hashes 
	
	Hash* & operator[](const char * hash_name);


};

