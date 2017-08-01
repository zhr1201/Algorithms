/*
A C++ emplimentation of karatsuba multiplication using divide and conquer
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


int make_same_length(vector <int> &a, vector <int> &b)
{
	int len_a = a.size();
	int len_b = b.size();
	int len_d = len_a - len_b;
	if(len_d > 0)
	{
		for(int i = 0; i < len_d; i++)
		{
			b.push_back(0);
		}
	}else if(len_d < 0)
	{
		len_d = -len_d;
		for(int i = 0; i < len_d; i++)
		{
			a.push_back(0);
		}
	}

	return max(len_a, len_b);
}


vector <int> plus_vec(vector <int> &a, vector <int> &b)
{
	int len = make_same_length(a, b);
	int carrier = 0;
	vector <int> rst;
	for(int i = 0; i < len; i++)
	{
		int temp = a[i] + b[i] + carrier;
		if (temp < 10)
		{
			carrier = 0;
			rst.push_back(temp);
		}else
		{
			carrier = 1;
			rst.push_back(temp - 10);
		}
	}
	if(carrier == 1)
		rst.push_back(carrier);
	return rst;
}


vector <int> minus_vec(vector <int> &a, vector <int> &b) 
{
	// only a <= b permitted
	int len = make_same_length(a, b);
	int carrier = 0;
	vector <int> rst;
	for(int i = 0; i < len; i++)
	{
		int temp = a[i] - b[i] + carrier;
		if (temp < 0)
		{
			carrier = -1;
			rst.push_back(temp + 10);
		}else
		{
			carrier = 0;
			rst.push_back(temp);
		}
	}
	return rst;
}


void sep_vec(vector <int> &org_v, vector <int> &low_v, vector <int> &high_v)
{
	int len = org_v.size();
	int len_l = len / 2;
	int len_h = len - len_l;
	for (int i = 0; i < len; i++)
	{
		if (i < len_l)
			low_v.push_back(org_v[i]);
		else
			high_v.push_back(org_v[i]);
	}
}


vector <int> &shift_decim(vector <int> &a, int num)
{
	for (int i = 0; i < num; i++)
		a.insert(a.begin(), 0);
	return a;
}


vector <int> karatsuba_mul(vector <int> &a, vector <int> &b)
{
	
	vector <int> a_high;
	vector <int> a_low;
	vector <int> a_plus;
	vector <int> b_high;
	vector <int> b_low;
	vector <int> b_plus;
	vector <int> rst;
	vector <int> product1;
	vector <int> product2;
	vector <int> product3;
	int len = make_same_length(a, b);

	if (len == 1)
	{
		int temp = a[0] * b[0];
		if (temp >= 10)
		{
			rst.push_back(temp % 10);
			rst.push_back(temp / 10);
		}
		else
			rst.push_back(temp);
		return rst;
	}else
	{
		sep_vec(a, a_low, a_high);
		sep_vec(b, b_low, b_high);
		int fac = a_low.size();
		a_plus = plus_vec(a_low, a_high);
		b_plus = plus_vec(b_low, b_high);
		product1 = karatsuba_mul(a_high, b_high);
		product2 = karatsuba_mul(a_low, b_low);
		product3 = minus_vec(
			minus_vec(karatsuba_mul(a_plus, b_plus), product1),
			product2);
		return plus_vec(
		    plus_vec(shift_decim(product1, fac * 2), shift_decim(product3, fac)),
			product2
			);
	}
}


vector <int> string2vec(string a)
{
	vector <int> rst;
	for (int i = 0; i < a.length(); i++)
		rst.push_back(a[i] - '0');
	return rst;
}


int main()
{
	string num1 = "3141592653589793238462643383279502884197169399375105820974944592";
	string num2 = "2718281828459045235360287471352662497757247093699959574966967627";
	ofstream outfile("rst.txt");
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	vector <int> a = string2vec(num1);
	vector <int> b = string2vec(num2);
	vector <int> rst = karatsuba_mul(a, b);
	if(outfile.is_open())
	for (int i = 0; i < rst.size(); i++)
	{
		int j = rst.size() - i - 1;
	    outfile << rst[j];
	}
	return 0;
}
