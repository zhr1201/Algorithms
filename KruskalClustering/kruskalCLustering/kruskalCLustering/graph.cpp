#include "graph.h"
#include <fstream>


using namespace std;


bool operator < (const Edge& a, const Edge& b)
{
	return a.cost < b.cost;
}


void graph::add_edge(int v1, int v2, int cost)
{
	Edge tmp_edge(v1, v2, cost);
	all_edge_list.push_back(tmp_edge);
	return;
}


void graph::add_edge_from_txt(string filename)
{
	ifstream infile(filename);
	int tmp;
	infile >> tmp;
	while(!infile.eof())
	{
		int vertex1;
		int vertex2;
		int cost;
		infile >> vertex1;
		infile >> vertex2;
		infile >> cost;
		Edge tmp_edge(vertex1 - 1, vertex2 - 1, cost);
		all_edge_list.push_back(tmp_edge);
	}
	return;
}


int graph::kruskal_clustering(int n_clusters)
{
	all_edge_list.sort();
	DisjSets edges_set(N_vertex);
	while(edges_set.N_sets > n_clusters)
	{
		Edge tmp = *all_edge_list.begin();
		all_edge_list.pop_front();
		int root1 = edges_set.find(tmp.vertex1);
		int root2 = edges_set.find(tmp.vertex2);
		if(root1 == root2)
			continue;
		else
			edges_set.union_sets(root1, root2);

	}
	while(true)
	{
		Edge tmp = *all_edge_list.begin();
		all_edge_list.pop_front();
		int root1 = edges_set.find(tmp.vertex1);
		int root2 = edges_set.find(tmp.vertex2);
		if(root1 != root2)
		{
			cout << "maximum spacing  " <<  tmp.cost;
			break;
		}
	}
	return 0;
}


DisjSets::DisjSets(int N)
{
	vector<int> tmp(N, -1);
	N_sets = N;
	s = tmp;
	return;
}

int DisjSets::find(int x)
{
	if(s[x] < 0)
		return x;
	else
		return s[x] = find(s[x]);
}

void DisjSets::union_sets(int root1, int root2)
{
	if(s[root2] < s[root1])
		s[root1] = root2;
	else if(s[root2] > s[root1])
		s[root2] = root1;
	else
	{
	    --s[root1];
		s[root2] = root1;
	}
	N_sets--;
	return;
}

void DisjSets::print_set()
{
	vector<int>::iterator iter = s.begin();
	for(; iter != s.end(); iter++)
		cout << "  " << *iter;
	return;
}