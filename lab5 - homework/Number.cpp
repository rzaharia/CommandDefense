#include "Number.h"
#include <string.h>
#include <iostream>
#include<cctype>


/// <summary>
/// Helper function to convert a char array into an int 
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
int char_to_int(char* s)
{

	if (s == nullptr) return 0;

	int res = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		res *= 10;
		res += s[i] - '0';

	}

	return res;
}

/// <summary>
/// Helper function to convert an int to a char 
/// </summary>
/// <param name="number"></param>
/// <returns></returns>
char* int_to_char(int number)  //1223 ---->
{
	char p[10];
	int i = 0;
	while (number)
	{
		p[i] = number % 10 + '0';
		number /= 10;
		i++;

	}
	_strrev(p);
	return p;

}
 Number::Number(const char* val_to_be_set, int base) //constructor of the number instance 
{

	 this->value = new char(strlen(val_to_be_set));
	 strcpy_s(value, strlen(val_to_be_set),val_to_be_set);
	 this->base = base;
}
 Number::Number(const Number& other)
 {
	  
	 this->base = other.base;
	 strcpy_s(this->value, strlen(other.value), other.value);
		
 }
 Number::Number(const Number&& source ) : base{source.base}
 {
	 strcpy_s(this->value, strlen(source.value), source.value);
	
 }

 /// <summary>
 /// Instance destructor 
 /// </summary>
 Number::~Number()
 {
	 delete this->value;
	 this->base = -1;  
 }
  void Number::Print()
 {

	 std::cout << this->value << std::endl;
	 std::cout << "The base is" << " " << std::endl;
 }


  //digits in decimal or any base ?? 
 int Number::GetDigitsCount()
 {
	 return strlen(this->value);
 }
 
 int Number::GetBase()
 {
	 return this->base;
 }

//TODO SwitchBase and Opearators 

 void Number::SwitchBase(int newBase)
 {
	 int current_value_decimal;
	 int digit; 
	 int val;
	 if (newBase == this->base) return;
	 //if the base is not the same  ---convert it ! 


	 //convert the base to decimal first 
	
	
	
	 
		 for (int i = strlen(this->value)-1; i >=0; i--)
		 {
			 if (isdigit(this->value[i]))
			 {
				 digit = this->value[i] - '0';
				 val += pow(this->base, digit);
			 }

			 else
			 {
				 digit = this->value[i] - 'A' + 10;
				 val += pow(this->base, digit);


			 }
		 }

		//convert decimal to newBase	 
	


		 // ----------TO BE CONTINUED 
 
		 this->base = base;
 }

 Number operator+(  Number&  left  , Number& right )
 {   
	 int final_base; 
	 if (left.base < right.base) final_base = right.base;
	 else final_base = left.base;

	 left.SwitchBase(10);
	 right.SwitchBase(10);


	 int res = char_to_int(left.value) + char_to_int(right.value);  //1234
	 
	 //convert res(int) to char * 
	 char* res_in_char = int_to_char(res);

	 //convert res into final_base 
	 return { int_to_char(res) , final_base };

 

 }
 
 Number operator-(Number& left, Number& right)
 {
	 int final_base;
	 if (left.base < right.base) final_base = right.base;
	 else final_base = left.base;

	 left.SwitchBase(10);
	 right.SwitchBase(10);


	 int res = char_to_int(left.value) - char_to_int(right.value);  //1234

	 //convert res(int) to char * 
	 char* res_in_char = int_to_char(res);

	 //convert res into final_base 
	 return { int_to_char(res) , final_base };



 }

 bool Number:: operator<( Number& right)
 {

	 //copy for our  object so we dont have to change his base 
	 Number temp{ this->value , this->base };

	 temp.SwitchBase(10);
	 right.SwitchBase(10);

	 int n1 = char_to_int(temp.value);
	 int n2 = char_to_int(right.value);
	 if (n1 < n2) return true; 
	 return false;


 }
 bool Number:: operator>(Number& right)
 {

	 //copy for our  object so we dont have to change his base 
	 Number temp{ this->value , this->base };

	 temp.SwitchBase(10);
	 right.SwitchBase(10);

	 int n1 = char_to_int(temp.value);
	 int n2 = char_to_int(right.value);
	 if (n1 > n2) return true;

	 return false;


 }
 bool Number:: operator<=(Number& right)
 {

	 //copy for our  object so we dont have to change his base 
	 Number temp{ this->value , this->base };

	 temp.SwitchBase(10);
	 right.SwitchBase(10);

	 int n1 = char_to_int(temp.value);
	 int n2 = char_to_int(right.value);
	 if (n1 <= n2) return true;
	 return false;


 }
 bool Number:: operator>=(Number& right)
 {

	 //copy for our  object so we dont have to change his base 
	 Number temp{ this->value , this->base };

	 temp.SwitchBase(10);
	 right.SwitchBase(10);

	 int n1 = char_to_int(temp.value);
	 int n2 = char_to_int(right.value);
	 if (n1 >= n2) return true;
	 return false;


 }
 bool Number:: operator==(Number& right)
 {

	 //copy for our  object so we dont have to change his base 
	 Number temp{ this->value , this->base };

	 temp.SwitchBase(10);
	 right.SwitchBase(10);

	 int n1 = char_to_int(temp.value);
	 int n2 = char_to_int(right.value);
	 if (n1 == n2) return true;
	 return false;


 }
 bool Number:: operator!=(Number& right)
 {

	 //copy for our  object so we dont have to change his base 
	 Number temp{ this->value , this->base };

	 temp.SwitchBase(10);
	 right.SwitchBase(10);

	 int n1 = char_to_int(temp.value);
	 int n2 = char_to_int(right.value);
	 if (n1 != n2) return true;
	 return false;
	
 }

 Number Number ::  operator--()
 {

	 //delete the first digit 
	 this->value++;
	 return *this;

 }

 //1234
 Number Number :: operator--(int )
 {
	 //remove the last digit   
	 this->value[strlen(value)] = NULL;
	 return *this;

 }
