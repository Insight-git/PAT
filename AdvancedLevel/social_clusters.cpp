#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N = 0, K = 0;
	unsigned int i = 0, j = 0;
	unsigned int temp = 0;
	set<unsigned int> cluster;
	map<unsigned int,unsigned int> hobby;
	cin >> N;
	for(i=0;i<N;i++)
	{
		scanf("%d:",&K);
		for(j=0;i<K;j++)
		{
			cin >> temp;
			hobby[temp]++;
		}
	}
	for(auto it:hobby)
	{
		if(it.second>1)
			cluster.insert(it.second);
	}
	cout << cluster.size() << endl;
	auto it = cluster.crbegin();
	cout << *it;
	for(;it!=cluster.crend();it++)
		cout << ' ' << *it;
	cout << endl;
	return 0;
}