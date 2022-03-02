#include "NaturalNumbers.h"
#include<iostream>
using namespace std;

NaturalNumbers::NaturalNumbers()
{
	this->count = 0;

}


/// <summary>
/// Function to Add a value at a given position in the array 
/// </summary>
/// <param name="val">Value to be inserted  </param>
/// <param name="pos">Position to be inserted</param>
void NaturalNumbers::AddAt(unsigned int  val , unsigned int pos )
{
	if (pos > count) return; 

	//if not , add the number in the array and shift all the elements 

	unsigned temp = this->numbers[pos]; 
	count++; 
	for (unsigned i = count - 1; i > pos; i--)
	{
		this->numbers[i] = this->numbers[i - 1];

	}
	this->numbers[pos] = val;

}
/// <summary>
/// Function to push back the 'val' element
/// </summary>
/// <param name="val">Element to be added </param>
void NaturalNumbers::PushBack(unsigned int  val)
{


	this->numbers[count] = val;
	this->count++;

}

void NaturalNumbers::Print()
{
	for (int i = 0; i < count; i++)
	{

		cout << numbers[i] << " ";


	}
	cout << endl;
}
/// <summary>
/// Function to push in the front  an element
/// </summary>
/// <param name="val"></param>
void NaturalNumbers::PushFront(unsigned int val)
{
	this->count++;
	for (unsigned i = this->count - 1; i > 0; i--)
	{

		this->numbers[i] = this->numbers[i - 1];

	}

	this->numbers[0] = val;


}
/// <summary>
/// Function to pop the last element 
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
unsigned int NaturalNumbers::PopBack()
{	
	unsigned int ret = this->numbers[this->count-1];
	this->numbers[this->count - 1] = 0;
	this->count--;
	return ret;


}
/// <summary>
/// Function to sort ascending the list of numbers 
/// </summary>
void NaturalNumbers::SortAsc()
{
	//sort the number list
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
		{

			if (numbers[i] > numbers[j])
			{
				swap(numbers[i], numbers[j]);
			}

		}
}
/// <summary>
/// Function to sort descending the list of numbers
/// </summary>
void NaturalNumbers::SortDesc()
{
	//sort the number list
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
		{

			if (numbers[i] < numbers[j])
			{
				swap(numbers[i], numbers[j]);
			}

		}
}

