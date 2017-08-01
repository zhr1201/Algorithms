#include <list>
#include <vector>


using namespace std;


class HashTable
{
public:
	HashTable(int new_size);
	void insert(long long new_element);
	bool look_up(long long elelment);
	int count;
	int colision;
private:
	int size;
	int hash_function(long long element);
	vector<list<long long>> chaining_table;
};
