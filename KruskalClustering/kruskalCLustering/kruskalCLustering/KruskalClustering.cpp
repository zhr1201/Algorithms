#include "graph.h"


int main()
{
	graph test(500);
	test.add_edge_from_txt("data.txt");
	test.kruskal_clustering(4);
	return 0;
}