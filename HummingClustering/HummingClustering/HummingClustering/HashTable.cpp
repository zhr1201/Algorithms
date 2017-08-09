#include "HashTable.h"


using namespace std;


HashTable::HashTable(int new_size):
size(new_size), count(0), colision(0)
{
	vector<list<KeyValueUnion>> tmp(size);
	chaining_table = tmp;
}


void HashTable::insert(int id, list<bool>& humming_cordinate)
{

	int ids = hash_function(humming_cordinate);
	KeyValueUnion tmp(id, humming_cordinate);
	chaining_table[ids].push_back(tmp);
	if(colision < chaining_table[ids].size())
		colision = chaining_table[ids].size();
	count++;
	return;
}


list<KeyValueUnion> HashTable::look_up(list<bool>& humming_cordinate)
{
	list<KeyValueUnion> rst;
	int idx = hash_function(humming_cordinate);
	list<KeyValueUnion>::iterator iter = chaining_table[idx].begin();
	bool flag = false;
	for(; iter != chaining_table[idx].end(); iter++)
	{
		if(iter->humming_cordinate == humming_cordinate)
		{
			KeyValueUnion tmp(*iter);
			rst.push_back(tmp);
		}
	}
	return rst;
}


int HashTable::hash_function(list<bool>& humming_cordinate)
{
	int tmp = 0;
	list<bool>::iterator iter = humming_cordinate.begin();
	for(; iter != humming_cordinate.end(); iter++)
	{
		tmp = tmp * 2 + *iter;
	}

	return tmp % size;
}
