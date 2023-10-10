#pragma once


#include <iostream>
#include <vector>
#include <utility>
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
	std::vector <cell>     cache_data_;

///---------------------------------------------------------------------------------

	iterator check_hit(const key_T& key)
    {   
	    return std::find_if(cache_data_.begin(), cache_data_.end(),
                           [key]( const cell& val ){ return val.key_ == key; });
    }


///---------------------------------------------------------------------------------

    
    page_T get_page(const key_T& key)
    {
        return key;
    }

///---------------------------------------------------------------------------------

    public:

    explicit lfu_simple (std::size_t capacity) :
    capacity_{capacity}
    {
	    cache_data_.reserve (capacity);
    }


///---------------------------------------------------------------------------------


	
	void print() const
    {
	    std::cout << "start print \n";
	
    	for (const cell& i: cache_data_)  
	    {
		    std::cout << i.key_ << ' '        << i.page_ 
		              << ' '    << i.counter_ <<   '\n';
	    }
        std::cout << std::endl;
    }

///--------------------------------------------------------------------------------

	
	page_T get_key(const key_T& key)
    {
        page_T page =   get_page(key);
        auto   hit  =  check_hit(key);  
       
        if (hit != cache_data_.end())             
	    {
		    hit->counter_++; 
            return page;
    	}

	    size_t size   = cache_data_.size();
        cell new_elem =         {key,page};


        if (size < capacity_) 
    	{   
	    	cache_data_.push_back(std::move(new_elem));
    	}

	    
        else
    	{
    		auto least_it = std::min_element(cache_data_.begin(), cache_data_.end(),
	    	                                 [](const cell& p1, const cell& p2)
                                             { return p1.counter_ < p2.counter_; });
            *least_it = std::move(new_elem);
    	}   

	    return page;
    }

}; // class


} // namespace cache
