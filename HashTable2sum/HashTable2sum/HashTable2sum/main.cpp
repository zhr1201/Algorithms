/*
Hash table implementation for 20000(k) 2-sum for 1000000(N) long long numbers
total runnning time O(kN)
Both my hash_table implementation and STL hash_map is a bit of slow(Compared to python dict: x10 faster))
The collisions of the dataset in the my hashtable are at most 7, so not a key factor for the long running time.
Dont know what caused the slow running speed.
*/


#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <hash_map>


using namespace std;
int main()
{
	//hash_map<long long, bool> dic2;
	ifstream infile("2sum.txt");
	HashTable dic(2097152);
	HashTable sum(4001);
	list<long long> record;
	long long tmp;
	while(!infile.eof())
	{
		infile >> tmp;
		//dic2[tmp] = 1;;
		dic.insert(tmp);
		record.push_back(tmp);
	}
	for(long long i = -10000; i <= 10000; i++)
	{
		cout << i << " has been checked";
		for(list<long long>::iterator iter = record.begin(); iter != record.end(); iter++)
		{
			long long tmp = i - *iter;
			//if(dic2.find(tmp) != dic2.end())
			if(dic.look_up(tmp))
			{
				if(tmp == *iter)
					continue;
				else
				{
				    sum.insert(i);

				}
			}	    
		}
	}
	cout << sum.count;
	return 0;
}
