#pragma once
#include<iostream>
#include<algorithm>
#include <utility>

template<class T>
class Vector
{	
private : 
	T* ptr;
	int indx ;
	int max_size;

	 /// <summary>
	 /// Helper function to double the size of the memory in case it's needed 
	 /// </summary>
	 /// <typeparam name="T"></typeparam>
	 void add_memory()
	{
	  //double the size of the memory allocated 
	//double the memory 
		T* new_ptr = new T[this->max_size * 2];
		//copy the elements in the new buffer 		
		memcpy(new_ptr, this->ptr, sizeof(this->ptr));
		this->ptr = new_ptr;
		this->max_size *= 2;	
	}
	 
public :



	Vector() //default constructor 
	{

	}

	Vector(int size ) // constuctor 
	{
		ptr = new T[size];
		this->max_size = size;
		this->indx = 0;
	}
	void print()
	{
		for (int i = 0; i < indx; i++)
		{
			std::cout << this->ptr[i] << " ";
		}
		std::cout << std::endl;
	}
	 void push(T elem)
	{
		if (this->indx > this->max_size)
		{
			this->add_memory();
			//now ptr points to another memory location that is bigger   :) 
		}
		this->ptr[this->indx++] = elem;
		
	}
	T pop() // pop the last element 
	{
		int pos = this->indx-1;
		--indx;
		return this->ptr[pos];
		
	}
	void remove(int indx)
	{

		if (indx > this->max_size) return;

		
		//shift all elements 

		for (int i = indx; i < this->max_size-1; i++)
		{
			//3 4 5 2 
			this->ptr[i] = this->ptr[i + 1];
		}
		this->indx--;

	
	}

	void insert(int indx , T elem)
	{
		if (this->indx + indx > max_size)
		{
		
		//double the memory 
			this->add_memory();
			
		}

		//else insert the element 
		//shift the elements

		for (int i = this->max_size; i >= indx; i--)
		{
			this->ptr[i] = this->ptr[i-1];
		}
		this->ptr[indx] = elem;  //insert the element at indx position
		this->indx++;
	}

	/// <summary>
	/// Generic sort function
	/// </summary>
	/// <param name="funct">Funct that tells us how we should sort the vector </param>
	void sort( int(*sort__callback)(T elem1 , T elem2)) 
	{ 

		if (sort__callback== nullptr)
		{

			//use the operator '<'
			for (int i = 0; i < this->indx - 1; i++)
				for (int j = i + 1; j < this->indx; j++)
				{
					if (this->ptr[i] > this->ptr[j]) std::swap(this->ptr[i], this->ptr[j]);
				}

		}

		else {

			//use the callback function in order to determine how to sort the vector 
			
				
			for (int i = 0; i < this->indx - 1; i++)
				for (int j = i + 1; j < this->indx; j++)
				{  

					//3  2  1 
					// 1  2  3  
					if (sort__callback(this->ptr[i], this->ptr[j])  > 0) std::swap(this->ptr[i], this->ptr[j]); 

					if (sort__callback(this->ptr[i], this->ptr[j])  < 0) std::swap(this->ptr[i], this->ptr[j]); 
					
				}



		}

	}

	int count()
	{
		return this->indx ; // number of elements in the vector 
	
	}

	T& Get(int indx)
	{
		return this->ptr[indx];

	}
	void Set(  const T& elem , int indx  )
	{
		if (indx > this->indx - 1) return;

		//set the
		this->ptr[indx] = elem;

	}

	int FirstIndexOf(T elem, bool (*equal)(T elem1, T elem2)) 
	{
		//if the pointer to the callback funct is null we use  operator '++'
		if (equal == nullptr)
		{

			for (int i = 0; i < this->indx; i++)
			{
				if (this->ptr[i] == elem) return i; 
			}

			return -1;

		}


		//use of equal callback function to implement the functionality 

		for (int i = 0; i < this->indx; i++)
		{
			if (equal(this->ptr[i], elem)) return i; 
		}
		return -1;

	}

};
