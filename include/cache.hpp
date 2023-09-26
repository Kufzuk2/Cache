#pragma once

#include <vector>


namespace cache
{

//template <typename key_T, typename page_T>
class lfu_simple final
{
	size_t capacity_;

	struct cell
	{
		int     key_;
		int    page_;
		int counter_ = 1; 
	};	
	
	using iterator       = typename std::vector<cell>::iterator;
	using const_iterator = typename std::vector<cell>::const_iterator;
	std::vector <cell>     cache_data;


	iterator check_hit(int key) ; 


	public:
	
	lfu_simple(size_t     capacity);
	
	int get_data(int key, int page); // (int key)
	
	void print()              const; 
};


} // namespace cache
