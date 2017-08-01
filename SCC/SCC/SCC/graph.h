#include <list>
#include <vector>
#include <iostream>
#include <string>

using namespace std;


struct Vertex
{
	int id;
	int leader;
	bool explored;
	list <Vertex*> connecter;
	list <Vertex*> inv_connector; 
};


class Graph
{
public:
	int size;
	int leader_mark;
	int size_count;
	list<int> dfs_orderlist;
	list<int> SCC_size;
	vector <Vertex> v_vector;
	Graph(int N);
	void add_edge(int i, int j);
	void add_edge_from_txt(string filename);
	void print_adjecent_list();
	void DFS(Vertex &V);
	void DFS_loop();
	void reset_graph();
	void SCC_DFS(Vertex &V);
	void SCC_DFS_loop();
};