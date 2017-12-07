#include<iostream>
#include<map>
#include<set>
#include<iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N = 0, M = 0;
	unsigned int i = 0;
	map<unsigned long,unsigned long> couples;
	set<unsigned long> IDs;
	set<unsigned long> singles;
	unsigned long A = 0, B = 0;
	cin >> N;
	for (i = 0; i<N; i++)
	{
		cin >> A >> B;
		couples[A] = B;
		couples[B] = A;
	}
	cin >> M;
	for (i = 0; i<M; i++)
	{
		cin >> A;
		IDs.insert(A);
	}
	for (auto it=IDs.cbegin();it!=IDs.cend();it++)
	{
		auto temp_it = couples.find(*it);
		if (temp_it != couples.end())
		{
			if (IDs.find(temp_it->second) != IDs.end())
			{
				continue;
			}
		}
		singles.insert(*it);
	}
	cout << singles.size() << endl;
	auto it = singles.cbegin();
	cout << setw(5) << setfill('0') << *it;
	it++;
	for (; it != singles.cend(); it++)
	{
		cout << ' ' ;
		cout << setw(5) << setfill('0') << *it;
	}
	cout << endl;
	return 0;
}

/*solution 2*/
#include<iostream>
#include<cstring>
//#include<set>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N = 0, M = 0;
	unsigned int i = 0;
	long *couples = new long[100000] {};
	long A = 0, B = 0;
	memset(couples,-1,sizeof(long)*100000);
	cin >> N;
	for (i = 0; i<N; i++)
	{
		cin >> A >> B;
		couples[A] = B;
		couples[B] = A;
	}
	cin >> M;
	long *guests = new long[M] {};
	bool *visited = new bool[100000] {};
	vector<long> singles;
	for (i = 0; i<M; i++)
	{
		cin >> guests[i];
		visited[guests[i]] = true;
	}
	for (i=0;i<M;i++)
	{
		if(couples[guests[i]]==-1)//没有对象
			singles.push_back(guests[i]);
		else if(!visited[couples[guests[i]]])//有对象，但是对象没来
			singles.push_back(guests[i]);
	}
	sort(singles.begin(),singles.end());
	cout << singles.size() << endl;

	for(auto it=singles.cbegin();it!=singles.cend();it++)
	{
		if(it<singles.cend()-1)
		{
			cout << setw(5) << setfill('0') << *it;
			cout << ' ' ;
		}
		else
		{
			cout << setw(5) << setfill('0') << *it;
			cout << endl;
		}
	}
	delete [] couples;
	delete [] guests;
	delete [] visited;
	return 0;
}
