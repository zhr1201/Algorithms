/*
Using SCC to solve 2Sat
O(N + M) blazingly fast
*/


#include "graph.h"
#include <iostream>


using namespace std;


int main()
{
	Graph test_graph(800000);  // graph size = 2 * input variable
	test_graph.add_edge_from_txt("data3.txt");
	test_graph.DFS_loop();
	test_graph.reset_graph();
	test_graph.SCC_DFS_loop();
	cout << test_graph.check_2sat();
	return 0;
}
