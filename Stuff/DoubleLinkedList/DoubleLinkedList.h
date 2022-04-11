#pragma once
#include "Node.h"
#include <iostream>
template<class T>
class DoubleLinkedList
{

private : 
	  
	 Node<T> head; //pointer to head of the list 
	 
  
public:

	DoubleLinkedList(){} //default constructor 

	void PushFront(T value)
	{
		Node<T>* new_node = new Node<T>;
		
		new_node->value = value;
		new_node->next = this->head.next;
		this->head.next = new_node;

	}


	void PushBack(T value)
	{

		Node<T>* ptr = this->head.next; 
		Node<T>* new_node = new Node<T>;
		new_node->value = value;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;

		}
		//add on the last position 
		ptr->next = new_node;
		new_node->next = nullptr;

	}

	T  PopFromBack()
	{

		//pop an element from the back 
		Node<T>* ptr = this->head.next; 
		while (ptr->next->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = nullptr; //delete the last conection 
		return ptr->value;

	}
	void PrintAll(void (*printElem)(T elem))
	{
		if (printElem == nullptr)
		{
			//use the default print function 
			Node<T>* ptr = this->head.next;
			while (ptr != nullptr)
			{

				std::cout << ptr->value << std::endl;
				ptr = ptr->next;


			}


		}

		else
		{
			//use the function to print each element 
			Node<T>* ptr = this->head.next;
			while (ptr != nullptr)
			{

				printElem(ptr->value);
				ptr = ptr->next;


			}

		}

	}
	
  }; 

