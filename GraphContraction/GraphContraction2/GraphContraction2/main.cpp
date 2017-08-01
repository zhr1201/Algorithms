#include "Graph.h"
#include <string>
#include "time.h"
#include <fstream>


using namespace std;


int main()
{
	srand((unsigned)time(NULL));
	int N = 200;
	list <int> vname_list;
	for (int i = 0; i < N; i++)
		vname_list.push_back(i + 1);
	Graph <int> test_graph(vname_list);
	//test_graph.add_edge(1, 2);
	//test_graph.add_edge(1, 3);
	//test_graph.add_edge(1, 4);
	//test_graph.add_edge(1, 5);
	//test_graph.add_edge(3, 2);
	//test_graph.add_edge(4, 5);
	char line[5048 * 2];
	ifstream infile("data.txt");
	while(!infile.eof())
	{
		infile.getline(line, 5048);
		int temp = 0;
		bool flag = true;
		int n_ver = 0;
		for (int i = 0; line[i] != '\0';)
		{
			if(line[i] == ' ')
			{
				if(flag == true)
				{
					n_ver = temp;
					flag = false;
				}
				else
					test_graph.add_edge(n_ver, temp);
				temp = 0;
				i++;
			}
			else
			{
				temp = temp * 10 + (line[i++] - '0');
				//cout << line[i - 1];
			}

		}
	}
	test_graph.print_adjacent_list();
	cout << "Edges:" << test_graph.n_Edges << endl;
	int m = 500;
	while (m > 0)
	{
		Graph <int> test_graph2(test_graph);
		test_graph2.random_cut();
		cout << "edges: " << test_graph2.n_Edges << endl;
		cout << "vertices: " << test_graph2.N_vertices << endl;
		m--;
	}
	test_graph.random_cut();
	cout << "edges: " << test_graph.n_Edges << endl;
	cout << "vertices: " << test_graph.N_vertices << endl;
	test_graph.print_adjacent_list();
	return 0;

}
