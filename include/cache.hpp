#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <string>

enum temporal 
{
	cache_capacity =     4,
	inf            = 10000

};




//template <key_t, page_t>
class lfu_simple final
{

	private: // may be deleted

	struct page
	{
		int     key;
		int    page;
		int counter;
	};	
	
	std::vector <struct page> cache_data;


	int search_min_freq() const;


	int check_hit(int key) const; // returns 1, if hit found


	public:
	
	int get_data(int key, int page);
	
	int print_vec() const;
};



