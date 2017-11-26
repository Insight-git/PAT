#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N = 0, base = 0;
	vector<unsigned int> result;
	unsigned int i = 0;
	cin >> N >> base;
	do
	{
		result.push_back(N % base);
		N /= base;
	}while(N);
	unsigned int size = result.size();
	bool flag = true;
	for(i=0;i<size/2;i++)
	{
		if(result[i]!=result[size-1-i])
		{
			flag = false;
			break;
		}
	}
	if(flag)	
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	auto it=result.crbegin();
	for(;it!=result.crend()-1;it++)
		cout << *it << ' ';
	cout << *it << endl;
	return 0;
}