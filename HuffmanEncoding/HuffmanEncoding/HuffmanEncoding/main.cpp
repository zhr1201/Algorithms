#include "HuffmanTree.h"
#include <iostream>
#include <queue>
#include <fstream>


struct Element
{
	int freq;
	int id;
	Element(int init_id, int init_freq):freq(init_freq), id(init_id){};
};

bool operator < (const Element& a, const Element& b)
{
	return a.freq > b.freq;
}


int main()
{
	ifstream infile("data.txt");
	int N_element;
	infile >> N_element;
	vector<int> freq_vec;
	while(!infile.eof())
	{
		int tmp;
		infile >> tmp;
		freq_vec.push_back(tmp);
	}
	priority_queue<Element> freq_queue;
	for(int i = 0; i < N_element; i++)
	{
		Element tmp(i, freq_vec[i]);
		freq_queue.push(tmp);
	}
	HuffmanTree h_tree(N_element);
	while(!freq_queue.empty())
	{
		if(freq_queue.size() == 1)
			break;
		else
		{
		Element top_e = freq_queue.top();
		freq_queue.pop();
		Element top_e2 = freq_queue.top();
		freq_queue.pop();
		Element merge_e(top_e.id, top_e.freq + top_e2.freq);
		freq_queue.push(merge_e);
		h_tree.merge_new(top_e.id, top_e2.id);
		}
	}
	h_tree.preorder_travesal();
	return 0;
}
