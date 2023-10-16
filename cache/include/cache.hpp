#pragma once

#include <iostream>
#include <list>


namespace lfu
{

template <typename key_T, typename page_T>
class cache 
{

    struct node_
    {
        key_T    key_;
        page_T  page_;
        freq_it root_;  
    };


    using cfreq_it = typename std::list<std::pair<int, std::list<node>>>::const_iterator;
    using  freq_it = typename std::list<std::pair<int, std::list<node>>>::iterator;

    using  ckey_it = typename std::list<node_>::iterato::const_iterator;
    using   key_it = typename std::list<node_>::iterator;

    size_t capacity_;
    std::list<std::pair<int, std::list<node_>>> freq_list_;

    std::unordered_map<key_T, key_it>                 map_;


    explicit cache(int capacity) : capacity_{capacity}
    {
        map_.restrict(capacity);
    }

    

    std::pair<bool, key_it> check_if_added(const key_T& key); // not realised 

    key_it raise_freq(key_it iter);  // not realised, must change iterator in hash_table
                          
    key_it add_to_cache(const key_T& key);  // not realised 

    void add_to_map(const key_T& key, key_it iter); // not realised

    key_it get_lfu(); // not realised

    void delete_from_cache(key_it iter);   // not realised just replace data if freq = 1
                                           


	page_T lookup_update(const key_T& key)
    {
        auto key_in_cache = check_if_added(key);  // returns pair

        int size = map_.size();

        if(key_in_cache.first)
        {
            key_it new_it = raise_freq(key_in_cache.second);
            page_T   page = new_it->page_;
        }

        else if (size < capacity)
        {
            key_it iter = add_to_cache(key);
            add_to_map(key, iter); //void

            page_T page = iter->page_t;
        }
        else
        {
            key_it iter_to_change =  get_lfu();

            map_.erase (iter_to_chanche->key_);
            
            delete_from_cache(iter_to_change);   // just replace data if freq = 1   make in one func
            key_it iter = add_to_cache(key);

            map_.insert(key, iter);
        }   
    
        return page;
    }


    page_T get_page()








} // class cache

} // namespace lfu
