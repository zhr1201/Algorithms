#include "heap.h"
#include <iostream>
#include <fstream>


using namespace std;
int main()
{
	BinaryHeap h_max(true);
	BinaryHeap h_min(false);
	ifstream data("data.txt");
	long long sum = 0;
	int count = 0;
	while(count < 10000)
	{
		count++;
		int tmp;
		data >> tmp;
		if(h_max.find_top() >= tmp)
		{
			h_max.insert(tmp);
			if(h_max.current_size - h_min.current_size >= 2)
			{
				int trans = h_max.find_top();
				h_max.delete_top();
				h_min.insert(trans);
			}
		}
		else
		{
			h_min.insert(tmp);
			if(h_min.current_size > h_max.current_size)
			{
				int trans = h_min.find_top();
				h_min.delete_top();
				h_max.insert(trans);
			}
		}
		sum += h_max.find_top();
	}
	return 0;
};
