#pragma once

#include <vector>
#include <algorithm>

class lfu_simple final
{
	size_t capacity_;

	struct page
	{
		int     key_;
		int    page_;
		int counter_;
	};	
	
	using iterator       = std::vector<page>::iterator;
	using const_iterator = std::vector<page>::const_iterator;
	std::vector <page>     cache_data;


	const_iterator check_hit(int key)   const; 


	public:
	
	lfu_simple(size_t     capacity);
	
	int get_data(int key, int page);
	
	int print()               const;
};



