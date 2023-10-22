#include <cache.hpp>


int main()
{
    size_t  cache_size = 0;
    std::cin >> cache_size;

    lfu::cache<int, int> tmp{cache_size};

    size_t hit_num = tmp.get_data();

    std::cout << "hit_num = " << hit_num << std::endl;


}
