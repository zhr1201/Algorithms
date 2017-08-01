#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


template <typename Comparable>
int find_median(vector <Comparable> &a, int n_left, int n_mid, int n_right)
{
	vector <int> sort_name;
	sort_name.push_back(n_left);
    sort_name.push_back(n_mid);
	sort_name.push_back(n_right);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			if(a[sort_name[i]] >= a[sort_name[j]])
				swap(sort_name[i], sort_name[j]);
		}
	}
	return sort_name[1];
}

template <typename Comparable>
long long QuickSort(vector <Comparable> &a, int n_left, int n_right)
{
	
	if (n_right - n_left == 1 || n_right - n_left == 0)
		return 0;
	else if (n_right - n_left == 2)
	{
		if(a[n_right - 1] < a[n_left])
		{
			Comparable temp = a[n_left];
			a[n_left] = a[n_right - 1];
			a[n_right - 1] = temp;	
		}
		return 1;
	}
	else
	{
		int mid = (n_right - n_left - 1) / 2 + n_left;
		int n_pivot_0 = n_right - 1;
		//int n_pivot_0 = find_median(a, n_left, mid, n_right - 1);

		Comparable temp;

		temp = a[n_pivot_0];
		a[n_pivot_0] = a[n_left];
		a[n_left] = temp;
		int n_pivot = n_left;
		int sep_flag = n_left;
		for(int i = n_left; i < n_right; i++)
		{
			if(a[i] <= a[n_pivot])
			{
				temp = a[i];
				a[i] = a[sep_flag];
				a[sep_flag] = temp;
				sep_flag ++;
			}
		}
		temp = a[n_pivot];
		a[n_pivot] = a[sep_flag - 1];
		a[sep_flag - 1] = temp;
		return QuickSort(a, n_left, sep_flag - 1) + QuickSort(a, sep_flag, n_right) + n_right - n_left - 1;
	}
}


template <typename Comparable>
long long QuickSortStart(vector <Comparable> &a)
{
	return QuickSort(a, 0, a.size());
}


int main()
{
	ifstream infile("data.txt");
	int data;
	vector<int> a;
	vector<int>::iterator iter;

	while(!infile.eof())
	{
		infile >> data;
		a.push_back(data);
	}

	long long count = QuickSortStart(a);

	cout << count << " compare";
	//for (int i = 0; i < a.size(); i++)
	//{
	//	cout << a[i] << ' ';
	//}
	return 0;
}
