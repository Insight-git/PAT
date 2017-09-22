#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	int i = 0;
	int sign = 0;
	vector<char> ch;
	cin >> a >> b;
	c = a + b;
	sign = c;
	if(sign<0)
		c = -c;
	do
	{
		ch.push_back(c % 10 + '0');
		c = c / 10;
		i++;
		if(i%3==0&&c)
			ch.push_back(',');
	}while(c);
	if(sign<0)
		ch.push_back('-');
	for(i=ch.size();i>=1;i--)
	{
		cout << ch.back();
		ch.pop_back();
	}
	return 0;	
}