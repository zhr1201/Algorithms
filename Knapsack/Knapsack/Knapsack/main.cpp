#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>


using namespace std;


map<string, int> C;
vector<int> value;
vector<int> weight;
int size;
int N;


int compute_C(int i, int x)
{
	extern map<string, int> C;
	extern int size;
	extern int N;
	string key1 = to_string((long long)i) +  "," + to_string((long long)x);
	if(i == 0)
	{
		return 0;
	}
	else if(C.find(key1) != C.end())
		return C[key1];
	else if(x < weight[i - 1])
	{
		C[key1] = compute_C(i - 1, x);
		return C[key1];
	}
	else
	{
		C[key1] = max(compute_C(i - 1, x), compute_C(i - 1, x - weight[i - 1]) + value[i - 1]);
		return C[key1];
	}
}


int main()
{
	ifstream file("data.txt");
	extern int size;
	extern int N;
	file >> size;
	file >> N;
	extern vector<int> value;
	extern vector<int> weight;
	extern map<string, int> C;
	for(int i = 0; i < N; i++)
	{
		int tmp_value;
		int tmp_weight;
		file >> tmp_value;
		file >> tmp_weight;
		value.push_back(tmp_value);
		weight.push_back(tmp_weight);
	}
	cout << compute_C(N, size);

	return 0;
}