#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

#define MAX_LINE_NUM	2
#define MAX_INDEX		1000

int main(int argc, char *argv[])
{
	int i = 0, j = 0;
	double data[MAX_LINE_NUM][MAX_INDEX+1] = {0};
	set<int> index;
	int n = 0, k = 0;
	double a_n = 0;
	for(i=0;i<2;i++)
	{
		cin >> k;
		for(j=0;j<k;j++)
		{
			cin >> n >> a_n;
			data[i][n] = a_n;
			index.insert(n);
		}
	}
	for(auto it=index.rbegin();it!=index.rend();it++)
	{
		a_n = data[0][*it]+data[1][*it];
		if(a_n>-0.1&&a_n<0.1)
		{
			index.erase(*it);//删除等于零的元素及其索引
			continue;
		}
	}
	cout << index.size();
	for(auto it=index.rbegin();it!=index.rend();it++)
	{
		cout << " " << *it << " ";
		cout << setiosflags((ios::fixed));
		cout << setprecision(1) << (data[0][*it]+data[1][*it]);
	}
	return 0;
}