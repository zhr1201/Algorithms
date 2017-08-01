#include "graph.h"
#include <fstream>


using namespace std;


bool operator < (const Vertex& a, const Vertex& b)
{
	return a.cost > b.cost;
}


graph::graph(int N)
{
	for(int i = 0; i < N; i++)
	{
		vertexs.push_back(Vertex(i, 1000000));
	}
}

void graph::add_edge(int i, int j, int weight)
{
	Edge temp_vertex(j, weight);
	Edge temp_vertex2(i, weight);
	vertexs[i].edges.push_back(temp_vertex);
	vertexs[j].edges.push_back(temp_vertex2);
	return;
}

void graph::add_edge_from_txt(string filename)
{
	char line[5048 * 2];
	ifstream infile(filename);
	int tmp;
	infile >> tmp;
	infile >> tmp;
	while(!infile.eof())
	{
		int s1, s2, weight;
		infile >> s1;
		infile >> s2;
		infile >> weight;
		add_edge(s1 - 1, s2 - 1, weight);
	}
	return;
}

void graph::print_graph()
{
	vector<Vertex>::iterator iter = vertexs.begin();
	for(; iter != vertexs.end(); iter++)
	{
		cout << " Vertex: " << iter->id << " Cost: " << iter->cost << " Visited:" << iter->visited << endl;
		cout << "    Adjecent vertices: ";
		for(list<Edge>::iterator iter2 = iter->edges.begin();
			iter2 != iter->edges.end(); iter2++)
		{
			cout << " Vertex: " << iter2->next << " Cost " << iter2->cost; 
		}
		cout << endl;
	}
	return;
}

long long graph::prim_mst(int init_id)
{
	long long cost = 0;
	vertexs[init_id].cost = 0;
	vertex_cost.push(vertexs[init_id]);
	while(!vertex_cost.empty())
	{
		Vertex& current_vertex = vertexs[vertex_cost.top().id];
		int tmp_cost = vertex_cost.top().cost;
		vertex_cost.pop();
		if(current_vertex.visited == true)
			continue;
		cost += tmp_cost;
		// Dont forget to update the smallest cost
		current_vertex.cost = tmp_cost;
		current_vertex.visited = true;
		list<Edge>::iterator iter = current_vertex.edges.begin();
		for(; iter != current_vertex.edges.end(); iter++)
		{
			if(vertexs[iter->next].visited == false)
			{
				vertexs[iter->next].cost = iter->cost;
				Vertex tempV(vertexs[iter->next]);
				vertex_cost.push(tempV);
			}
		}
	}
	return cost;
}

