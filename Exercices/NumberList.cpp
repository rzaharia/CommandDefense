#include "NumberList.h"
#include <iostream>
using namespace std; 


 
NumberList::NumberList()
{

	count = 0; 

}

void NumberList::Init()  // or make a constructor 
{
	//initialise the count to 0 
	count = 0;
}


 void NumberList::Print()
{
	
	 for (int i = 0; i < count; i++)
	 {

		 cout << numbers[i] << " ";


	 }



}

 bool NumberList::Add(int x )
 {

	 if (count >= 10) return false;
	 else {

		 //we can add the current element to the list 
		 numbers[count] = x;
		 count++;

	 }

 }

 void NumberList::Sort()
 {
	 //sort the number list
	 for(int i = 0 ; i<count-1;i++)
		 for (int j = i + 1; j < count; j++)
		 {

			 if (numbers[i] > numbers[j])
			 {
				 swap(numbers[i], numbers[j]);
			 }

		 }





 }