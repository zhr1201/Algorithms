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
		vertexs.push_back(Vertex(i, 100000));
	}
}

void graph::add_edge(int i, int j, int weight)
{
	Edge temp_vertex(j, weight);
	vertexs[i].edges.push_back(temp_vertex);
	return;
}

void graph::add_edge_from_txt(string filename)
{
	char line[5048 * 2];
	ifstream infile(filename);
	while(!infile.eof())
	{
		infile.getline(line, 2 * 5048);
		bool out_vertex = true;
		int out_id;
		bool weight = false;
		int in_id;
		int tmp = 0;
		for (int i = 0; line[i] != '\0'; i++)
		{
			if((line[i] >= '0') & (line[i] <= '9'))
				tmp = (line[i] - '0') + tmp * 10;
			else
			{
				if(out_vertex)
				{
					out_vertex = false;
					out_id = tmp;
				}
				else if(weight)
				{
					weight = false;
					add_edge(out_id - 1, in_id - 1, tmp);
					
				}
				else
				{
					in_id = tmp;
					weight = true;
				}
				tmp = 0;
			}
		}
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

void graph::dijkistra(int init_id)
{
	vertexs[init_id].cost = 0;
	vertex_cost.push(vertexs[init_id]);
	while(!vertex_cost.empty())
	{
		Vertex& current_vertex = vertexs[vertex_cost.top().id];
		int tmp_cost = vertex_cost.top().cost;
		vertex_cost.pop();
		if(current_vertex.visited == true)
			continue;
		// Dont forget to update the smallest cost
		current_vertex.cost = tmp_cost;
		current_vertex.visited = true;
		list<Edge>::iterator iter = current_vertex.edges.begin();
		for(; iter != current_vertex.edges.end(); iter++)
		{
			if(vertexs[iter->next].visited == false)
			{
				vertexs[iter->next].cost = current_vertex.cost + iter->cost;
				Vertex tempV(vertexs[iter->next]);
				vertex_cost.push(tempV);
			}
		}
	}
	return;
}

