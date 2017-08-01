#include "HashTable.h"


using namespace std;


HashTable::HashTable(int new_size):
    size(new_size), count(0), colision(0)
{
    vector<list<long long>> tmp(size);
	chaining_table = tmp;
}


void HashTable::insert(long long new_element)
{
	if(!look_up(new_element))
	{
		int id = hash_function(new_element);
		chaining_table[id].push_back(new_element);
		if(colision < chaining_table[id].size())
			colision = chaining_table[id].size();
		count++;
	}
	return;
}


bool HashTable::look_up(long long element)
{
	int id = hash_function(element);
	list<long long>::iterator iter = chaining_table[id].begin();
	bool flag = false;
	for(; iter != chaining_table[id].end(); iter++)
	{
		if(*iter == element)
		{
			flag = true;
			break;
		}
	}
	return flag;
}


int HashTable::hash_function(long long element)
{
	int key = element % size;
	if(key < 0)
		key = key + size;
	return key;
}