#pragma once


#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cstddef>

namespace cache
{

template <typename key_T, typename page_T>
class lfu_simple final
{
    std::size_t capacity_;

	struct cell
	{
		key_T       key_;
		page_T     page_;
		int counter_ = 1; 
	};	
	
	using iterator       = typename std::vector<cell>::iterator;
	using const_iterator = typename std::vector<cell>::const_iterator;
	std::vector <cell>     cache_data;

///---------------------------------------------------------------------------------

	iterator check_hit(key_T key)
    {   
	    return std::find_if(cache_data.begin(), cache_data.end(),
                           [key]( const cell& val ){ return val.key_ == key; });
    }


///---------------------------------------------------------------------------------

    
    page_T get_page(key_T key)
    {
        return key;
    }

///---------------------------------------------------------------------------------

    public:

    lfu_simple (std::size_t capacity) :
    capacity_{capacity}
    {
	    cache_data.reserve (capacity);
    }


///---------------------------------------------------------------------------------


	
	void print() const
    {
	    std::cout << "start print \n";
	
    	for (const cell& i: cache_data) //  error if cell& 
	    {
		    std::cout << i.key_ << " "        << i.page_ 
		              << " "    << i.counter_ <<   "\n";
	}
        std::cout << std::endl;
    }

///--------------------------------------------------------------------------------

	
	int get_data( key_T key, page_T page ) // (int key)
	
    {
	    size_t size          = cache_data.size();
    	struct cell new_elem =    {key, page, 1};

	    if (size == 0)
    	{
	    	cache_data.push_back(new_elem);
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
    	}

	    
        else
    	{
    		auto least_it = std::min_element(cache_data.begin(), cache_data.end(),
	    	                                 [](cell& p1, cell& p2){ return p1.counter_ < p2.counter_; });
            *least_it = std::move(new_elem);
    	}   

	    return 0;
    }

}; // class


// get_data should return a page

} // namespace cache
