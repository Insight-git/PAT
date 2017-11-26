#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(int argc, char *argv[])
{
	string str,str_changed;
	multiset<unsigned int> original, changed;
	unsigned int m = 0, n = 0, temp = 0;
	cin >> str;
	for (auto it = str.crbegin(); it != str.crend(); it++)
	{
		temp = *it - '0';
		original.insert(temp);
		m = (temp * 2 + n) % 10;
		n = (temp * 2) / 10;
		changed.insert(m);
		str_changed.insert(0, 1, (m + '0'));
	}
	if (n)
	{
		m = n % 10;
		changed.insert(m);
		str_changed.insert(0, 1, (m + '0'));
	}
	if (original.size() != changed.size())
	{
		cout << "No" << endl;
		cout << str_changed << endl;
		return 0;
	}
	for (auto it1=original.cbegin(),it2=changed.cbegin();it1!=original.cend()&&it2!=changed.cend();it1++,it2++)
	{
		if (*it1 != *it2)
		{
			cout << "No" << endl;
			cout << str_changed << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	cout << str_changed << endl;
	return 0;
}