#include "cache.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <string>



int lfu_simple::get_data(int key, int page)
{
	size_t size          = cache_data.size();
	struct page new_elem =    {key, page, 1};

	if (size == 0)
	{
		cache_data.reserve(cache_capacity);
		cache_data.push_back(new_elem    );

		return 0;
	}
	

	int hit = check_hit(key); //// 
	
	
	if (hit != -1)                     // to be simplified
	{
		cache_data[hit].counter++;
		return 0; 
	}

	if (size < 4)
	{
		cache_data.push_back(new_elem);
		return 0;
	}	

	
	int least_index = search_min_freq();  // returns index of the least frequent value

	cache_data[least_index] = new_elem;
	return 0;
}


int lfu_simple::check_hit(int key) const
{
	size_t size = cache_data.size();

	
    for (size_t i = 0; i < size; i++)
	{
		if (cache_data[i].key == key)
		{
			return i;
		}
	}
	return -1;
}


int lfu_simple::search_min_freq() const
{
	int    least_freq =               inf;
	int         index =                 0;	
	int          size = cache_data.size();  //special field in the class
	

	for (int i = 0; i < size; i++)
	{

		if (cache_data[i].counter < least_freq)
		{
			index      =                 i;
			least_freq = cache_data[i].key;
		}

	}

	return index;
}



int lfu_simple::print_vec() const
{
	int size = cache_data.size();
	std::cout << "start print \n";

	for (int i = 0; i < size; i++)
	{
		std::cout << cache_data[i].key << " " << cache_data[i].page << " " << cache_data[i].counter << "\n";
	}
	
	std::cout << "\n";

	return 0;
}

