#include "cache.hpp"

int main()
{
	cache::lfu_simple <int, int> lfu {4};  


    lfu.get_key(0);
    lfu.print(   );

    lfu.get_key(1);
    lfu.print(   );

    lfu.get_key(1);
    lfu.print(   );

    lfu.get_key(0);
    lfu.print(   );

    lfu.get_key(2);
    lfu.print(   );

    lfu.get_key(3);
    lfu.print(   );

    lfu.get_key(2);
    lfu.print(   );

    lfu.get_key(1);
    lfu.print(   );

    lfu.get_key(2);
    lfu.print(   );

    lfu.get_key(4);
    lfu.print(   );

    lfu.get_key(4);
    lfu.print(   );

    lfu.get_key(4);
    lfu.print(   );

    lfu.get_key(5);
    lfu.print(   );

	return 0;
}
