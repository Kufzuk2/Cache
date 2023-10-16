#pragma once

#include <iostream>
#include <list>
#include <unordered_map>


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

#if 0
    struct map_data
    {   
        bool     added_;
        key_T      key_;
        key_it list_it_;
        map_it  map_it_;
    };
#endif  // will be necessery if it is posssible not to serach through hash_table in func check_if_added


    size_t capacity_;
    std::list<std::pair<int, std::list<node_>>> freq_list_;

    std::unordered_map<key_T, key_it>                 map_;


    using cfreq_it = typename std::list<std::pair<int, std::list<node>>>::const_iterator;
    using  freq_it = typename std::list<std::pair<int, std::list<node>>>::iterator;

    using  cmap_it = typename std::unordered_map<key_T, key_it>::const_iterator;
    using   map_it = typename std::unordered_map<key_T, key_it>::iterator;

    using  ckey_it = typename std::list<node_>::iterato::const_iterator;
    using   key_it = typename std::list<node_>::iterator;


    explicit cache(int capacity) : capacity_{capacity}
    {
        map_.restrict(capacity);
    }

    
                          
    key_it add_to_cache(const key_T& key);  // not realised 

    key_it get_lfu(); // not realised

    void delete_from_cache(key_it iter);   // not realised just replace data if freq = 1
                                           


///---------------------------------------------------------------------------------------------------

	page_T lookup_update(const key_T& key)
    {
        auto key_in_cache = check_if_added(key);  // done

        int size = map_.size();
        map_it hash_it = map_.find(key);

        if(key_in_cache.first)
        {
            key_it   new_it = raise_freq(key_in_cache.second); // 
            page_T     page = new_it->page_;
            hash_it->second = new_it;
        }

        else if (size < capacity)
        {
            key_it iter = add_to_cache(key); //
            map_.insert(key, iter);

            page_T page = iter->page_t;
        }
        else
        {
            key_it iter_to_change =  get_lfu(); //

            map_.erase (iter_to_chanche->key_);
            
            delete_from_cache(iter_to_change);   // just replace data if freq = 1   make in one func
            key_it iter = add_to_cache(key);  // 

            map_.insert(key, iter);
        }   
    
        return page;
    }


///---------------------------------------------------------------------------------------------------

    std::pair<bool, key_it> check_if_added(const key_T& key)
    {
        for (auto [inner_key, iter] : map_)
        {
            if (inner_key == key)
                return {true, iter};           
        }

        return {false, map_.end()}
    }


///---------------------------------------------------------------------------------------------------


    key_it raise_freq(key_it iter) 
    {
        // add move
        key_T   key = iter-> key_;
        page_T page = iter->page_;


        key_it new_root = ++(iter->root_.second);
        
        new_root.second.push_front({key, page, new_root});  //
                                                                // mat be better
                                                                // replace with
                                                                // each other
        iter->root_.second.erase(iter);                     //
        
        return new_root.second.begin();
    }



    page_T get_page(const key_T& key)
    {
        return key;
    }








} // class cache

} // namespace lfu
