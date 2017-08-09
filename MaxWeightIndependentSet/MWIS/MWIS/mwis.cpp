/************************************************************************/
/* Use dynamic programming to solve mwis                                                                     */
/************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


int main()
{
	ifstream file("data.txt");
	int N;
	file >> N;
	vector<bool> pre2_state(N, false);
	vector<bool> pre1_state(N, false);
	vector<bool> current_state(N, false);
	long long pre2_num = 0;
	long long pre1_num = 0;
	long long current_num = 0;
	for(int i = 0; i < N; i++)
	{
		int tmp;
		file >> tmp;
		if(pre2_num + tmp >  pre1_num)
		{
			current_num = pre2_num + tmp;
			current_state = pre2_state;
			current_state[i] = true;
		}
		else
		{
			current_num = pre1_num;
			current_state = pre1_state;
		}
		pre2_num = pre1_num;
		pre1_num = current_num;
		pre2_state = pre1_state;
		pre1_state = current_state;
	}
	cout << current_state[0] << current_state[1] << current_state[2] << current_state[3];
	cout << current_state[16] << current_state[116] << current_state[516] << current_state[996];
	return 0;
}