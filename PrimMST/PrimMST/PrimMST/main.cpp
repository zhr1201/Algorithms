#include "graph.h"


using namespace std;


int main()
{
	graph G(500);
	G.add_edge_from_txt("edges.txt");
	//G.print_graph();
	long long result = G.prim_mst(10);
	cout << "total cost: " << result;
	return 0;
}
