#include "HashTable.h"
#include "DisjSet.h"
#include <fstream>
#include <string>
#include <cmath>
#include <iostream>


using namespace std;


int main()
{
	string filename("data2.txt");
	ifstream file(filename);
	int N_size;
	int N_bits;
	file >> N_size;
	file >> N_bits;
	int hash_size = N_size * 1.8 + 1;
	list<list<bool>> all_data;
	HashTable hash_table(hash_size);
	DisjSets disjoint_set(N_size);
	int count = 0;
	list<bool> humming_id;
	while(count < N_size)
	{
		humming_id.clear();
		for(int i = 0; i < N_bits; i++)
		{
			int tmp;
			file >> tmp;
			bool tmp2 = (bool)tmp;
			humming_id.push_back(tmp2);
		}
		all_data.push_back(humming_id);
		hash_table.insert(count++, humming_id);
	}
	

	list<list<bool>>::iterator iter = all_data.begin();
	list<KeyValueUnion> search_result;
	list<bool> search_result_mut;
	count = 0;

	// O(N)
	for(iter = all_data.begin(); iter != all_data.end(); iter++)
	{
		search_result = hash_table.look_up(*iter);
		list<KeyValueUnion>::iterator iter2 = search_result.begin();
		for(; iter2 != search_result.end(); iter2++)
		{
			int root1 = disjoint_set.find(count);
			int root2 = disjoint_set.find(iter2->id);
			if(root1 != root2)
				disjoint_set.union_sets(root1, root2);
		}
		count++;
	}

	count = 0;
	//O(24N)
	for(iter = all_data.begin(); iter != all_data.end(); iter++)
	{
		for(int i = 0; i < N_bits; i++)
		{
			search_result_mut = *iter;
			list<bool>::iterator iter_c = search_result_mut.begin();
			for(int j = 0; j < i; j++)
				iter_c++;
			*iter_c = (*iter_c == false);
			search_result = hash_table.look_up(search_result_mut);
			list<KeyValueUnion>::iterator iter2 = search_result.begin();
			for(; iter2 != search_result.end(); iter2++)
			{
				int root1 = disjoint_set.find(count);
				int root2 = disjoint_set.find(iter2->id);
				if(root1 != root2)
					disjoint_set.union_sets(root1, root2);
			}
		}
		count++;
	}

	//O(24^2 / 2 * N)
	count = 0;
	for(iter = all_data.begin(); iter != all_data.end(); iter++)
	{
		for(int i = 1; i < N_bits; i++)
		{
			for(int i2 = 0; i2 < i ; i2++)
			{
				search_result_mut = *iter;
				list<bool>::iterator iter_c = search_result_mut.begin();
				list<bool>::iterator iter_c2 = search_result_mut.begin();
				for(int j = 0; j < i; j++)
					iter_c++;
				*iter_c = (*iter_c == false);
				for(int j = 0; j < i2; j++)
					iter_c2++;
				*iter_c2 = (*iter_c2 == false);
				search_result = hash_table.look_up(search_result_mut);
				list<KeyValueUnion>::iterator iter2 = search_result.begin();
				for(; iter2 != search_result.end(); iter2++)
				{
					int root1 = disjoint_set.find(count);
					int root2 = disjoint_set.find(iter2->id);
					if(root1 != root2)
						disjoint_set.union_sets(root1, root2);
				}
			}
		}
		count++;
	}
	cout << "number of clusters " << disjoint_set.N_sets; 
	cout << " press e to exit";
	char x;
	while(1)
	{
		cin >> x;
		if(x == 'e')
			break;
	}
	return 0;
}
