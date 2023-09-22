#include "cache.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <string>

lfu_simple::lfu_simple(size_t capacity) :
capacity_{capacity}
{
	cache_data.reserve   (capacity);
}


int lfu_simple::get_data(int key, int page)
{
	size_t size          = cache_data.size();
	struct page new_elem =    {key, page, 1};

	if (size == 0)
	{
		cache_data.push_back(new_elem    );
		return 0;
	}
	

	auto hit = check_hit(key);  
	
	
	if (hit != cache_data.cend())             
	{
		cache_data[hit - cache_data.cbegin()].counter_++;
	}

	else if (size < 4)
	{
		cache_data.push_back(new_elem);
	}
	
	else
	{
		auto least_it = std::min_element(cache_data.cbegin(),
		cache_data.cend(),
		[] (auto&& p1, auto p2)
		{return p1.counter_ < p2.counter_;});


		cache_data[least_it - cache_data.cbegin()] = new_elem;
	}

	return 0;
}




lfu_simple::const_iterator lfu_simple::check_hit(int key) const
{
	return	std::find_if(cache_data.cbegin(), 
	cache_data.cend(), 
	[key] (auto&& val){return val.key_ == key;});
}



int lfu_simple::print() const
{
	std::cout << "start print \n";
	
	for (page i: cache_data)
	{
		std::cout << i.key_ << " " << i.page_ 
		   << " " << i.counter_ << "\n";
	}


	std::cout << std::endl;

	return 0;
}


