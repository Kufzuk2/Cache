#include "cache.hpp" 

#include <iostream>
#include <vector>
#include <utility>
#include <string>


int main()
{
	lfu_simple lfu {};  

	lfu.get_data(100, 0);
	lfu.print_vec(     );

	lfu.get_data(101, 1);
	lfu.print_vec(     );

	lfu.get_data(102, 2);
	lfu.print_vec(     );

	lfu.get_data(102, 2);
	lfu.print_vec(     );

	lfu.get_data(103, 3);
	lfu.print_vec(     );

	lfu.get_data(104, 4);
	lfu.print_vec(     );

	lfu.get_data(100, 0);
	lfu.print_vec(     );

	lfu.get_data(101, 1);
	lfu.print_vec(     );

//	std::cout << x << "\n";
}
