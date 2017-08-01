/************************************
* 计算一个数组中的inversion的个数
*************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;


long long count_and_merge(int *a, int nl1, int nr1, int nl2, int nr2)
{
	int size1 = nr1 - nl1 +1;
	int size2 = nr2 - nl2 + 1;
	int size = size1 + size2;
	int *temp = new int[size];
	int i = nl1;
	int j = nl2;
	int k = 0;
	long long inv_count = 0;
	while(i <= nr1 || j <= nr2)
	{
		if(i > nr1)
			temp[k++] = a[j++];	
		else if(j > nr2)
		    temp[k++] = a[i++];
		else if(a[i] < a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			inv_count += nr1 - i + 1;
		}
	}
	int a_index = nl1;
	for (k = 0; k < size; k++)
	{
		a[a_index++] = temp[k]; 
	}
	delete [] temp;
	return inv_count;
}


long long count_and_sort(int *a, int nl, int nr)
{
	int size = nr - nl + 1;
	if(size == 1)
	{
		return 0;
	}
	else
	{
		int size1 = size / 2;
		int size2 = size - size1;
		int nl1 = nl;
		int nr1 = nl1 + size1 - 1;
		int nl2 = nl1 + size1;
		int nr2 = nr;
		long long inv_n1 = count_and_sort(a, nl1, nr1);
		long long inv_n2 = count_and_sort(a, nl2, nr2);
		long long inv_n3 = count_and_merge(a, nl1, nr1, nl2, nr2);
		return inv_n1 + inv_n2 + inv_n3;
	}
	
}


int main()
{
	ifstream infile("data.txt");
	int data;
	list<int> a;
	list<int>::iterator iter;

	while(!infile.eof())
	{
		infile >> data;
		a.push_back(data);
	}
	int size = a.size();
	int *data_array = new int[size];
	iter = a.begin();
	cout << *iter << endl;
	for(int i = 0; i < size; i++)
		data_array[i] = *iter++;
	cout << count_and_sort(data_array, 0, size - 1);
	return 0;
}
