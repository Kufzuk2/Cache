#include <iostream>
#include <string>
#include <vector>
#include <list>


class check final
{
	struct page
	{
		int x;
		int y;
	};

	std::vector<struct page> line;

	std::vector<int> data;
	public:
	
	int get_two(int x, int y);
	
	int get_data(int value);

	int push_inside(int x, int y, int index);

	int print_vec();
};



int check::get_data(int value) // NE SMOTRI
{
	int size = data.size();

	data.push_back(value);

	return 0;

}

int check::print_vec()
{

	int size = line.size();	

	for (int i = 0; i < size; i++)
	{
		std::cout << line[i].x << " " << line[i].y << "\n";
	} 
	
	std::cout << "\n";

	return 0;
}

int check::get_two(int x, int y)
{
	struct page p = {x, y};	

	line.push_back(p); 

	int size = line.size();
	
	return 0;
}

int check::push_inside(int x, int y, int index)
{
	struct page p = {x, y};	

	line[index]   =      p;

	return 0;
}

int main()
{
	check tmp {};

	tmp.get_two( 1, 2 );
	tmp.print_vec(    );

	tmp.get_two( 3, 4 );

	tmp.get_two( 5, 6 );
	tmp.get_two( 7, 8 );
	tmp.get_two( 9, 10);
	tmp.print_vec(    );

	tmp.push_inside(100, 100, 3);

	tmp.print_vec(    );

	
	return 0;
}


