#include "DisjSet.h"
#include <iostream>


using namespace std;


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
