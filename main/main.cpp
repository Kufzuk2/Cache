#include "cache.hpp" 

#include <iostream>
#include <vector>
#include <utility>
#include <string>


int main()
{
	lfu_simple lfu   {4};  

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
