#pragma once
#include "Hash.h"

class CountAsciiHash : public Hash
{
public: 
	Hash(char* string) override final;

};