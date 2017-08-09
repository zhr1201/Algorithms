#include <queue>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <list>
using namespace std;


struct Edge
{
	int vertex1;
	int vertex2;
	int cost;
	Edge(int v1, int v2, int c):vertex1(v1), vertex2(v2), cost (c){};
};


bool operator < (const Edge& a, const Edge& b);


class graph
{
public:
	graph(int N_init):N_vertex(N_init){};
	int N_vertex;
	list<Edge> all_edge_list;
	void add_edge(int v1, int v2, int cost);
	void add_edge_from_txt(string filename);
	int kruskal_clustering(int n_clusters);
};


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