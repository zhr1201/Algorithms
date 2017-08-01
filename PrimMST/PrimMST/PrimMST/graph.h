#include <queue>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <list>
using namespace std;


struct Edge
{
	int next;
	int cost;
	Edge(int init_next, int init_cost):next(init_next), cost(init_cost){};
};


struct Vertex
{
	int id;
	bool visited;
	int cost;
	list<Edge> edges;
	Vertex(int input_id, int weight):visited(false), id(input_id), cost(weight){};

};


bool operator < (const Vertex& a, const Vertex& b);


class graph
{
public:
	vector<Vertex> vertexs;
	priority_queue<Vertex> vertex_cost;
	graph(int N);
	void add_edge(int i, int j, int weight);
	void add_edge_from_txt(string filename);
	void print_graph();
	long long prim_mst(int init_id);
};
