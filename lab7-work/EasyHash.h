#pragma once
#include "Hash.h"

class EasyHash : public Hash
{
public:
	void CalculateHash(char* string) override final; 

};