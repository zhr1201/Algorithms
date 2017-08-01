#include "graph.h"


int main()
{
	Graph test_graph(900000);
	test_graph.add_edge_from_txt("SCC.txt");
	test_graph.DFS_loop();
	test_graph.reset_graph();
	test_graph.SCC_DFS_loop();
	return 0;
}
