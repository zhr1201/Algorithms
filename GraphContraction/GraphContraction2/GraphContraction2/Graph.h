#include <list>
#include <iostream> 


using namespace std;


template <typename idtype>
class Vertex
{
public:
	idtype id;
	list <idtype> connectors;
	Vertex()
	{
		id = NULL;
	}
	Vertex(idtype in_id)
	{
        id = in_id;
	}
};


template <typename idtype>
class Graph
{
public:
	list <Vertex <idtype>> vertices_list;
	int N_vertices;
	int n_Edges;

	Graph(list <idtype> init_vertices)
	{
		list <idtype>::iterator iter = init_vertices.begin();
		N_vertices = 0;
		for (; iter != init_vertices.end(); iter++)
		{
			N_vertices++;
			Vertex<idtype> temp(*iter);
			vertices_list.push_back(temp);
		}
		n_Edges = 0;
	}

	bool add_vertex(idtype id)
	{
		list <Vertex<idtype>>::iterator iter = vertices_list.begin();
		for(; iter != vertices_list.end(); iter++)
		{
			if(iter->id == id)
				return false;
		}
		N_vertices++;
		Vertex<idtype> temp(id);
		vertices_list.push_back(temp);
		return true;
	}

	bool del_vertex(idtype id)
	{
		list <Vertex<idtype>>::iterator iter = vertices_list.begin();
		bool flag = false;
		for(; iter != vertices_list.end();)
		{
			list <idtype>::iterator iter2 = iter->connectors.begin();
			for(; iter2 != iter->connectors.end();)
			{
				if(*iter2 == id)
				{
					iter2 = iter->connectors.erase(iter2);
					n_Edges--;
				}
				else
					iter2++;
			}
			if(iter->id == id)
			{
				iter = vertices_list.erase(iter);
				flag = true;
				N_vertices--;
			}
			else
				iter++;
		}

		return flag;
	}

	bool add_edge(idtype id1, idtype id2)
	{
		list <Vertex<idtype>>::iterator iter = vertices_list.begin();
		list <Vertex<idtype>>::iterator iter_id1 = vertices_list.begin();
		list <Vertex<idtype>>::iterator iter_id2 = vertices_list.begin();
		int flag_count = 0;
		for(; iter != vertices_list.end(); iter++)
		{
			if(iter->id == id1)
			{
				iter_id1 = iter;
				flag_count++;
			}
			if(iter->id == id2)
			{
				iter_id2 = iter;
				flag_count++;
			}
		}
		if (flag_count != 2)
			return false;
		
		list <idtype>::iterator iter_1_c = (*iter_id1).connectors.begin();
		for(; iter_1_c != (*iter_id1).connectors.end(); iter_1_c++)
		{
			if(*iter_1_c == id2)
				return false;
		}
		iter_id1->connectors.push_back(id2);
		iter_id2->connectors.push_back(id1);
		n_Edges++;
		return true;
	}

	void print_adjacent_list()
	{
		list <Vertex<idtype>>::iterator iter = vertices_list.begin();
		for(; iter != vertices_list.end(); iter++)
		{
			std::cout << "Vertex name: " << iter->id << " adjacent vertex: ";
			list <idtype>::iterator iter2 = iter->connectors.begin();
			for(; iter2 != iter->connectors.end(); iter2++)
			{
				std::cout << *iter2 << ' ';
			}
			std::cout << endl;
		}
		std::cout << endl;
		return;
	}

	bool del_edge(idtype id1, idtype id2)
	{
		list <Vertex<idtype>>::iterator iter = vertices_list.begin();

		bool flag = false;
		for(; iter != vertices_list.end(); iter++)
		{
			if(iter->id == id1)
			{
				list <idtype>::iterator iter_2 = iter->connectors.begin();
				for(; iter_2 != iter->connectors.end();)
				{
					if(*iter_2 == id2)
					{
						iter_2 = iter->connectors.erase(iter_2);
						flag = true;
					}
					else
						iter_2++;
				}
			}
			if(iter->id == id2)
			{
				list <idtype>::iterator iter_3 = iter->connectors.begin();
				for(; iter_3 != iter->connectors.end();)
				{
					if(*iter_3 == id1)
					{
						iter_3 = iter->connectors.erase(iter_3);
						flag = true;
						n_Edges--;
					}
					else
						iter_3++;
				}
			}
		}	
		return flag;
	}

	bool contract_edge(idtype id1, idtype id2)
	{
		list <Vertex<idtype>>::iterator iter = vertices_list.begin();
		list <Vertex<idtype>>::iterator iter1 = vertices_list.begin();
		list <Vertex<idtype>>::iterator iter2 = vertices_list.begin();
		int count = 0;
		int tot_edge_del_2 = 0;
		for(; iter != vertices_list.end();iter++)
		{
			if(iter->id == id1)
			{
                count++;
				iter1 = iter;
			}
			if(iter->id == id2)
			{
				count++;
				iter2 = iter;
			}
			list <idtype>::iterator iter_temp = iter->connectors.begin();
			for(;iter_temp != iter->connectors.end(); iter_temp++)
			{
				if(*iter_temp == id2) *iter_temp = id1;
			}
		}
		
		list <idtype>::iterator iter_id1 = iter1->connectors.begin();
		list <idtype>::iterator iter_id2 = iter2->connectors.begin();
		for(;iter_id2 != iter2->connectors.end(); iter_id2++)
		{
		    iter1->connectors.push_back(*iter_id2);
		}

		for(iter_id1=iter1->connectors.begin(); iter_id1 != iter1->connectors.end();)
		{
			if(*iter_id1 == iter1->id) 
			{
				tot_edge_del_2++;
				iter_id1 = iter1->connectors.erase(iter_id1);
			}
			else
				iter_id1++;
		}
		vertices_list.erase(iter2);
		if(count == 2)
		{
			n_Edges -= tot_edge_del_2 / 2;
			N_vertices--;
			return true;
		}
		else
			return false;
	}
	
	void random_cut()
	{
		while(N_vertices > 2)
		{
			int b = n_Edges * 2;
			int sel_v = rand() % b;
			int sum_v = 0;
			int ind = 0;
			list <Vertex<idtype>>::iterator iter = vertices_list.begin();
			idtype v1;
			idtype v2;
			for (; sum_v <= sel_v; iter++)
				sum_v += iter->connectors.size();
			iter--;

			sum_v -= iter->connectors.size();
			v1 = iter->id;
			ind = sel_v - sum_v;
			list <idtype>::iterator iter2 = iter->connectors.begin();
			for(int i = 0; i < ind; i++)
				iter2++;
			v2 = *iter2;
			contract_edge(v1, v2);
			//std::cout << "contract " << v1 << " and " << v2 << endl;
			//print_adjacent_list();
		}
		return;
	}
};
