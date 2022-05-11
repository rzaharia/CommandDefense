#pragma once
///struct key -- value

template<class K, class V>
struct Pair
{

	
	K key;
	V value;
	int index; 
	
};



template <class K , class V>
class MapIterator
{

	Pair <K, V> *ptr ; //pointer to the first pair
	int index;

public :
	MapIterator() {} 
	MapIterator(Pair<K,V>* map , int index_parm) : ptr(map),index(index_parm) {}


	bool operator !=(const MapIterator& other) const
     {
		return this->index != other.index; 
     }

	void operator++()
   {
		this->index++;

   }

	Pair<K,V> operator*() const
    {
		return map[index];
	
   }

};

//Map template
//
#include <map>
template<class K, class V >
class Map
{  
private :
	const int max_pairs;

	int curr_indx = 0; //current index of the elements

	Pair<K,V>* pair_ptr = new Pair<K,V>[max_pairs];

	

public : 
	Map() : max_pairs(100){}; //default constructor for 100 pairs in the vector
	Map(int no_of_pairs) : max_pairs(no_of_pairs) {};

	~Map()
	{   
		delete this->pair_ptr;
	}
	//operator to add a new pair to the vector 
	  V& operator[](K key)
	 {
		//we loop through vector and see if exists
		for(int i = 0 ; i<curr_indx;i++)
		{
			if (this->pair_ptr->key == key) return this->pair_ptr[i].value; 
			
		}

		
			//we haven't found it so we add it

			return this->pair_ptr[curr_indx++].value;
		
	}

	
	 
	void Insert(K key , V value )
	{
		this->pair_ptr[curr_indx].key = key;
		this->pair_ptr[curr_indx].value=value;
		curr_indx++;

	}
	void print(int indx )
	{
		printf("the value at %d is %d", indx, this->pair_ptr[indx].value); 


	}

	MapIterator<K,V> begin()
	{

		return { pair_ptr , 0 };

	}
	MapIterator<K,V> end()
	{

		return{ pair_ptr, curr_indx };

	}


};

