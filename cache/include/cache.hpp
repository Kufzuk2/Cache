#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>

namespace lfu
{

template <typename key_T, typename page_T>
class cache 
{

    struct node_
    {
        key_T   key_;
        page_T page_;
        typename std::list<std::pair<int, std::list<node_>>>::iterator root_;  
    };


    size_t hit_num_ = 0;
    size_t    capacity_;
    std::list<std::pair<int, std::list<node_>>> freq_list_;



    using cfreq_it = typename std::list<std::pair<int, std::list<node_>>>::const_iterator;
    using  freq_it = typename std::list<std::pair<int, std::list<node_>>>::iterator;


    using  ckey_it = typename std::list<node_>::const_iterator;
    using   key_it = typename std::list<node_>::iterator;


    using  cmap_it = typename std::unordered_map<key_T, key_it>::const_iterator;
    using   map_it = typename std::unordered_map<key_T, key_it>::iterator;

   
    std::unordered_map<key_T, key_it> map_;


    public:
    explicit cache(size_t capacity) : capacity_{capacity}
    {
        map_.reserve(capacity);
    }



///---------------------------------------------------------------------------------------------------

	page_T lookup_update(const key_T& key)
    {
        auto key_in_cache = check_if_added(key); 

        size_t    size = map_.size();
        map_it hash_it = map_.find(key);
        page_T page;
        

        if(key_in_cache.first)
        {
            key_it   new_it = raise_freq(key_in_cache.second); 
                       page = new_it->page_;
            hash_it->second = new_it;
        }

        else if (size < capacity_)
        {
            key_it iter = add_to_cache(key);
            map_.insert({key, iter});

            page = iter->page_;
        }
        else
        {
            key_it iter_to_change = get_lfu();

            map_.erase           (iter_to_change->key_);
            key_it iter = replace(iter_to_change, key ); 

            map_.emplace(key, iter);
            page = iter->page_;   
        }   
    
        return page;
    }


///---------------------------------------------------------------------------------------------------


    void print()
    {
        std::cout << "start print \n";
        for (auto [freq, list] : freq_list_)
        {
            std::cout << "freq = " << freq << ": ";

            for (auto node : list)
            {
                std::cout << node.key_ << " ";
            }

            std::cout << std::endl;
        }

        std::cout << "end print \n";
        std::cout << std::endl;
    }


///---------------------------------------------------------------------------------------------------


    std::size_t get_hit_num()
    {
        return hit_num_;
    }


///---------------------------------------------------------------------------------------------------


    std::size_t get_data()
    {
        std::istream_iterator<int> is_iter {std::cin};
        ++is_iter;

        std::vector<int> data { is_iter, std::istream_iterator<int> {} };

        for (int elem : data)
        {
            lookup_update(elem);
        }

        return hit_num_;

    }

///---------------------------------------------------------------------------------------------------
    private:
///---------------------------------------------------------------------------------------------------

    std::pair<bool, key_it> check_if_added(const key_T& key)
    {
        for (auto [inner_key, iter] : map_)
        {
            if (inner_key == key)
            {
                hit_num_++;
                return {true, iter};           
            }
        }

        return {false, key_it{}};
    }
///---------------------------------------------------------------------------------------------------

    key_it raise_freq(key_it iter)   
    {
        if (iter->root_ == std::prev(freq_list_.end()))
        {
            std::list<node_> list;
            freq_list_.push_back({iter->root_->first + 1, list}); 
        }

        freq_it new_root = ++(iter->root_); 
        new_root->second.push_front({iter->key_, iter->page_, new_root});  
        iter->root_->second.erase(iter);                     
        
        return new_root->second.begin();
    }

///---------------------------------------------------------------------------------------------------


    key_it add_to_cache(const key_T& key)
    {
        if (freq_list_.empty())   // or better use size of map as an argument of this function
        {
            std::list<node_> list;
            freq_list_.push_front({1, list});  // not clear how to do it better  
                                              // magic number
        }

        freq_list_.begin()->second.push_front( {key, get_page(key), freq_list_.begin()} );

        return freq_list_.begin()->second.begin();
    }

///---------------------------------------------------------------------------------------------------


    key_it get_lfu()
    {
        for (auto [freq, list] : freq_list_) 
        {
            if (!list.empty())
                return std::prev(list.end());
        }

        return key_it{};   //for the further repairations
    }

///---------------------------------------------------------------------------------------------------

    page_T get_page(const key_T& key)
    {
        return key;
    }

///---------------------------------------------------------------------------------------------------

    key_it replace(key_it iter, key_T new_key) // in case of freq = 1 its possible just to replace data but not to erase the whole element
    {
        iter->root_->second.pop_back();

        key_it new_it = add_to_cache(new_key);

        return new_it;                                             
    }

///---------------------------------------------------------------------------------------------------



}; // class cache

} // namespace lfu
