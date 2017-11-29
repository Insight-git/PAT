#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N = 0, M = 0, K = 0, Nv = 0;
	unsigned int i = 0, j = 0, a = 0, b = 0;
	vector<unsigned int> edge;
	set<unsigned int> vex;
	cin >> N >> M;
	for(i=0;i<M;i++)
	{
		cin >> a >> b;
		edge.push_back(a);
		edge.push_back(b);
	}
	cin >> K;
	for(i=0;i<K;i++)
	{
		cin >> Nv;
		vex.clear();
		for(j=0;j<Nv;j++)
		{
			cin >> a;
			vex.insert(a);
		}
		bool flag = true;
		for(auto it=edge.cbegin();it!=edge.cend();it=it+2)
		{
			if(vex.find(*it)==vex.end()&&vex.find(*(it+1))==vex.end())
			{
				cout << "No" << endl;
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "Yes" << endl;
	}
	return 0;
}