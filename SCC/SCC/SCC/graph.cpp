#include "graph.h"
#include <fstream>


Graph::Graph(int N)
{
	for(int i = 0; i < N; i++)
	{
		Vertex new_v;
		new_v.id = i;
		new_v.explored = false;
		v_vector.push_back(new_v);
	}
	size = N;
}

void Graph::add_edge(int i, int j)
{
	v_vector[i].connecter.push_back(&v_vector[j]);
	v_vector[j].inv_connector.push_back(&v_vector[i]);
	return;
}

void Graph::add_edge_from_txt(string filename)
{
	ifstream file(filename);
	int i;
	int j;
	bool flag = false;
	while(!file.eof())
	{
		if(flag == false)
		{
			file >> i;
			flag = true;
		}
		else
		{
			file >> j;
			flag = false;
			add_edge(i, j);
		}
	}
}

void Graph::print_adjecent_list()
{
	for(int i = 0; i < size; i++)
	{
		cout << "Vertex " << i << endl;
		list <Vertex*>::iterator iter = v_vector[i].connecter.begin();
		cout << "  adjecent vertex ";
		for(; iter != v_vector[i].connecter.end(); iter++)
		{
			cout << ' ' << (*iter)->id << ' ';
		}
		cout << endl;
	}

	cout << "inverted graph" << endl;

	for(int i = 0; i < size; i++)
	{
		cout << "Vertex " << i << " Leader " << v_vector[i].leader;
		list <Vertex*>::iterator iter = v_vector[i].inv_connector.begin();
		cout << "  adjecent vertex ";
		for(; iter != v_vector[i].inv_connector.end(); iter++)
		{
			cout << ' ' << (*iter)->id << ' ';
		}
		cout << endl;
	}
}

void Graph::DFS(Vertex &V)
{
	V.explored = true;
	list <Vertex*>::iterator iter = V.connecter.begin();
	for(; iter != V.connecter.end(); iter++)
	{
		if((*iter)->explored == false)
		{
			DFS(**iter);
		}
	}
	dfs_orderlist.push_back(V.id);
}

void Graph::DFS_loop()
{
	for(int i = 0; i < size; i++)
	{
		if(v_vector[i].explored == false)
		{
			DFS(v_vector[i]);
		}
	}
}

void Graph::reset_graph()
{
	for(int i = 0; i < size; i++)
	{
		v_vector[i].explored = false;
	}
	dfs_orderlist.reverse();
}

void Graph::SCC_DFS(Vertex &V)
{
	V.explored = true;
	V.leader = leader_mark; 
	size_count++;
	list <Vertex*>::iterator iter = V.inv_connector.begin();
	for(; iter != V.inv_connector.end(); iter++)
	{
		if((*iter)->explored == false)
		{
			SCC_DFS(**iter);
		}
	}
}

void Graph::SCC_DFS_loop()
{
	list <int>::iterator iter = dfs_orderlist.begin();

	for(; iter != dfs_orderlist.end(); iter++)
	{
		if(v_vector[*iter].explored == false)
		{
			leader_mark = *iter;
			size_count = 0;
			SCC_DFS(v_vector[*iter]);
			SCC_size.push_back(size_count);
		}
	}
	SCC_size.sort();
	SCC_size.reverse();
}
