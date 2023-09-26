#include "cache.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

cache::lfu_simple::lfu_simple(size_t capacity) :
capacity_{capacity}
{
	cache_data.reserve (capacity);
}


int cache::lfu_simple::get_data(int key, int page) // get_data should return a page
{
	size_t size          = cache_data.size();
	struct cell new_elem =    {key, page, 1};

	if (size == 0)
	{
		cache_data.push_back(new_elem    );
		return 0;
	}
	

	auto hit = check_hit(key);  
	
	
	if (hit != cache_data.end())             
	{
		hit->counter_++; 
	}

	else if (size < capacity_) 
	{
		cache_data.push_back(std::move(new_elem));
        // Better implementations:
		// 1) cache_data.push_back(std::move(new_elem));
        // 2) cache_data.emplace_back(key, page, 1);
	}

	else
	{
		auto least_it = std::min_element(cache_data.begin(), cache_data.end(),
		                                 [](cell& p1, cell& p2){ return p1.counter_ < p2.counter_; });

		cache_data[least_it - cache_data.cbegin()] = new_elem; // *least_it = std::move(new_elem);
	}

	return 0;
}




cache::lfu_simple::iterator cache::lfu_simple::check_hit(int key)
{
	return std::find_if(cache_data.begin(), cache_data.end(),
                        [key](const cell& val){ return val.key_ == key; });
}



void cache::lfu_simple::print() const
{
	std::cout << "start print \n";
	
	for (const cell& i: cache_data) //  error if cell& 
	{
		std::cout << i.key_ << " " << i.page_ 
		   << " " << i.counter_ << "\n";
	}


	std::cout << std::endl;

}


