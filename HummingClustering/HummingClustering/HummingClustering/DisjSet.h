#include <vector>


using namespace std;


class DisjSets
{
public:
	DisjSets(int N);
	int N_sets;
	int find(int x);
	void union_sets(int x, int y);
	void print_set();
private:
	vector<int> s;
};