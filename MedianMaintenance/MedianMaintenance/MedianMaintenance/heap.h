#include <vector>


using namespace std;


class BinaryHeap
{
public:
	explicit BinaryHeap(bool is_max_heap):max_heap(is_max_heap), current_size(0){num_array.push_back(0);};
	void insert(int new_element);
	int current_size;
	void delete_top();
	int find_top();
private:
	bool max_heap;
	vector<int> num_array;
};
