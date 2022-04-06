#include "CountAsciiHash.h"
#include <string.h>
void CountAsciiHash::CalculateHash(char* ptr)
{

	//add  to the hash the ASCII value of each char 
	for (int i = 0; i < strlen(ptr); i++)
	{
		//convert to ascii and add 
		hash_value += (int)ptr[i];

	}

		
}