#include <vector>
#include <fstream>
#include <iostream>


using namespace std;


int main()
{
	ifstream file("data1.txt");
	int N;
	int M;
	file >> N;
	file >> M;
	vector<vector<int>> A(N, vector<int>(N, INT_MAX));
	for(int i = 0; i < M; i++)
	{
		int start_p, stop_p, weight;
		file >> start_p;
		start_p = start_p - 1;
		file >> stop_p;
		stop_p = stop_p - 1;
		file >> weight;
		if(start_p == stop_p)
			A[start_p][stop_p] = 0;
		else
			A[start_p][stop_p] = weight;
	}
	for(int k = 0; k < N; k++)
	{
		vector<vector<int>> A_pre = A;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(A_pre[i][k] == INT_MAX || A_pre[k][j] == INT_MAX)
					A[i][j] = A_pre[i][j];
				else
				    A[i][j] = min(A_pre[i][j], A_pre[i][k] + A_pre[k][j]);
			}
		}
	}
	int min = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			if(A[i][i] < 0)
			{
				cout << "Negtive loop";
				return 0;
			}
			if(A[i][j] < min)
				min = A[i][j];
		}
    cout << "Min dis " << min;
	return 0;
}