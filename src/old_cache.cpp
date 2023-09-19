#include "cache.hpp"


int get_data(int value)
{
	size_t cur_size = cache_data.size();

	if (cur_size < 0)
		return -1;

	int hit_if_1 =  check_hit(value, cur_size, cache_data);
	if (hit_if_1 == 1)
		return 0;

	if (cur_size < cache_capacity)
	{
		cache_data.emplace_back(value, 1);
		return 0;
	}
	

	int least_index = search_min_frec(cache_data, cache_capacity);  // returns index of the least frequent value

	cache_data[least_index].first  = value;
	cache_data[least_index].second =     1;

	return 0;
}


int search_min_freq(`)
{
	int least_freq = inf;
	int      index =   0;

	for (int i = 0; i < cache_capacity; i++)
	{

		if (cache_data[i].second < least_freq)
		{
			index        =                   i;
			least_freq   = cache_data[i].second;
		}

	}
	return index;
}

int print_vec(const std::vector <std::pair <int, int>>& cache_data)
{
	std::cout << "start print \n";
	int size = cache_data.size();

	for (int i = 0; i < size; i++)
	{
		std::cout << "(" << cache_data[i].first << "," << cache_data[i].second << ") \n";
	}
	std::cout << "\n";
	return 0;
}


int check_hit(int value, int size, const std::vector <std::pair <int, int>>& cache_data)
{	
    for (int i = 0; i < size; i++)
	{
		if (cache_data[i].first == value)
		{
			cache_data[i].second++;
			return 1;
		}
	}
	return 2;
}

// read about std::rotate

