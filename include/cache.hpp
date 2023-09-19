#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <string>

#if(1)
enum temporal 
{
	//cache_capacity =     4,
	inf            = 10000

};
#endif



//template <key_t, page_t>
class lfu_simple final
{

	private: // may be deleted

	size_t capacity;

	struct page
	{
		int     key;
		int    page;
		int counter;
	};	
	
	std::vector <struct page> cache_data;



	int search_min_freq()  const;

	int check_hit(int key) const; // returns 1, if hit found



	public:
	
	lfu_simple(size_t     capacity);
	
	int get_data(int key, int page);
	
	int print_vec()           const;
};



