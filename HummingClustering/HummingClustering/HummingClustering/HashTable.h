#include <list>
#include <vector>


using namespace std;


struct KeyValueUnion
{
	int id;
	list<bool> humming_cordinate;
	KeyValueUnion(int in_id, list<bool>& in_cordinate):id(in_id), humming_cordinate(in_cordinate){};
};


class HashTable
{
public:
	HashTable(int new_size);
	void insert(int id, list<bool>& humming_cordinate);
	list<KeyValueUnion> look_up(list<bool>& humming_cordinate);
	int count;
	int colision;
private:
	int size;
	int hash_function(list<bool>& humming_cordinate);
	vector<list<KeyValueUnion>> chaining_table;
};
