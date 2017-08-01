#include "graph.h"


using namespace std;


int main()
{
	graph G(200);
	G.add_edge_from_txt("Data.txt");
	G.dijkistra(0);
	list<int> path_len;
	for(int i = 0; i < 200; i++)
		path_len.push_back(G.vertexs[i].cost);

	//graph G(6);
	//G.add_edge(0, 5, 14);
	//G.add_edge(0, 2, 9);
	//G.add_edge(0, 1, 7);

	//G.add_edge(1, 0, 7);
	//G.add_edge(1, 2, 10);
	//G.add_edge(1, 3, 15);

	//G.add_edge(2, 0, 9);
	//G.add_edge(2, 1, 10);
	//G.add_edge(2, 3, 11);
	//G.add_edge(2, 5, 2);

	//G.add_edge(3, 1, 15);
	//G.add_edge(3, 2, 11);
	//G.add_edge(3, 4, 6);

	//G.add_edge(4, 3, 6);
	//G.add_edge(4, 5, 9);

	//G.add_edge(5, 0, 14);
	//G.add_edge(5, 2, 2);
	//G.add_edge(5, 4, 9);
	G.dijkistra(0);
	//G.print_graph();
	return 0;
}
