#include "heap.h"

int BinaryHeap::find_top()
{
	if(current_size == 0)
		return -1;
	else
	    return num_array[1];
}


void BinaryHeap::insert(int new_element)
{
	int hole = ++current_size;
	num_array[0] = new_element;
	if(max_heap)
	{
		num_array.push_back(new_element);
		for(; new_element > num_array[hole / 2]; hole /= 2)
			num_array[hole] = num_array[hole / 2];
		num_array[hole] = new_element;
	}
	else
	{
		num_array.push_back(new_element);
		for(; new_element < num_array[hole / 2]; hole /= 2)
			num_array[hole] = num_array[hole / 2];
		num_array[hole] = new_element;
	}
	return;
}

void BinaryHeap::delete_top()
{
	int hole = 1;
	int last_element = num_array[current_size];
	int child;
	if(max_heap)
	{
		for(; hole * 2 <= current_size; hole = child)
		{
			child = hole * 2;
			if(child != current_size && num_array[child] < num_array[child + 1])
			{
				child++;
			}
			if(num_array[child] > last_element)
				num_array[hole] = num_array[child];
			else
				break;
		}
		num_array[hole] = last_element;
	}
	else
	{
		for(; hole * 2 <= current_size; hole = child)
		{
			child = hole * 2;
			if(child != current_size && num_array[child] > num_array[child + 1])
			{
				child++;
			}
			if(num_array[child] < last_element)
				num_array[hole] = num_array[child];
			else
				break;
		}
		num_array[hole] = last_element;
	}
	num_array.erase(num_array.end() - 1);
	current_size--;
	return;
	
}
