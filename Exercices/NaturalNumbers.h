#pragma once
#include "NumberList.h"
class NaturalNumbers :
    public NumberList
{
public : 
        unsigned numbers[100], count;

        NaturalNumbers();
        
        void AddAt(unsigned int  val , unsigned int pos);
        
        void PushBack(unsigned int val);
            
        void PushFront(unsigned int val);
        
        unsigned int PopBack();
        
        void SortAsc();
        void SortDesc();

        void Print();


         
    
};

