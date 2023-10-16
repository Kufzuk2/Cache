#include "cache.hpp"

int main()
{
	cache::lfu_simple <int, int> lfu {4};  


    lfu.lookup_update(0);
    lfu.print(   );

    lfu.lookup_update(1);
    lfu.print(   );

    lfu.lookup_update(1);
    lfu.print(   );

    lfu.lookup_update(0);
    lfu.print(   );

    lfu.lookup_update(2);
    lfu.print(   );

    lfu.lookup_update(3);
    lfu.print(   );

    lfu.lookup_update(2);
    lfu.print(   );

    lfu.lookup_update(1);
    lfu.print(   );

    lfu.lookup_update(2);
    lfu.print(   );

    lfu.lookup_update(4);
    lfu.print(   );

    lfu.lookup_update(4);
    lfu.print(   );

    lfu.lookup_update(4);
    lfu.print(   );

    lfu.lookup_update(5);
    lfu.print(   );

	return 0;
}
