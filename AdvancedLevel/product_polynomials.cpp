#include<iostream>
#include<map>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	unsigned int K1 = 0, K2 = 0;
	map<unsigned int, double> poly;
	map<unsigned int, double> result;
	set<unsigned int> exponent;
	set<unsigned int> final_exp;
	unsigned int i = 0, j = 0;
	unsigned int temp1 = 0;
	double temp2 = 0;
	cin >> K1;
	for (i = 0; i<K1; i++)
	{
		cin >> temp1 >> temp2;
		poly[temp1] = temp2;
		exponent.insert(temp1);
	}
	cin >> K2;
	for (i = 0; i<K2; i++)
	{
		cin >> temp1 >> temp2;
		for (auto it : exponent)
		{
			result[temp1 + it] += temp2 * poly[it];
			final_exp.insert(temp1 + it);
		}
	}
	unsigned int count = 0;
	for (auto it : final_exp)
	{
		if (result[it]>-0.1&&result[it]<0.1)
			final_exp.erase(it);
	}
	cout << final_exp.size();
	for (auto it = final_exp.crbegin(); it != final_exp.crend(); it++)
	{
		cout << ' ' << *it << ' ';
		cout << setiosflags((ios::fixed));
		cout << setprecision(1) << result[*it];
	}
	return 0;
}