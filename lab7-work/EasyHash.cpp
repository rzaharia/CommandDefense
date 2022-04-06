#include "EasyHash.h"
#include <string.h>

void EasyHash::CalculateHash(char* ptr)
{
	char vowels[] = "aeiouAEIOU";

	for (int i = 0; i < strlen(ptr); i++)
	{

		if (strchr(vowels, ptr[i])) // if not null we found a vowel 
		{
			//if the char is a vowel 
			hash_value += (int)ptr[i] * 10;

		}
		else if (strchr(vowels, ptr[i]) == NULL)
		{
			//check if char 
			if ((ptr[i] > 'a' && ptr[i] < 'z') || (ptr[i] > 'A' && ptr[i] < 'Z'))
			{

				hash_value += (int)ptr[i] * 11;
			}
			else hash_value += (int)ptr[i] * 12;
		}

	}

}