#include "graph.h"


int main()
{
	Graph test_graph(200000);
	test_graph.add_edge_from_txt("data1.txt");
	test_graph.DFS_loop();
	test_graph.reset_graph();
	test_graph.SCC_DFS_loop();
	return 0;
}
