#include "cache.hpp"

/*
 * 1) Put all your classes in a namespace;
 * 2) Use templates: template<typename Key_T, typename Page_T> class LFU;:
 */
int main()
{
	cache::lfu_simple <int, int> lfu {4};  

	lfu.get_data(100, 0);
	lfu.print(         );

	lfu.get_data(101, 1);
	lfu.print(         );

	lfu.get_data(102, 2);
	lfu.print(     	   );

	lfu.get_data(102, 2);
	lfu.print(         );

	lfu.get_data(103, 3);
	lfu.print(         );

	lfu.get_data(104, 4);
	lfu.print(         );

	lfu.get_data(100, 0);
	lfu.print(         );

	lfu.get_data(101, 1);
	lfu.print(         );

	return 0;
}
