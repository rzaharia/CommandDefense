#include<iostream>
#include "NumberList.h"

using namespace std; 
int main()
{
    NumberList list1;
    // list1.Init();//initialise the count attribute with 0
    list1.Add(12);
    list1.Add(23);
    list1.Add(34);
    list1.Add(41);
    list1.Sort();
    list1.Print();
}


