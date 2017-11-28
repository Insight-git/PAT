#include<iostream>
#include<string>
using namespace std;

string ReverseInt(string N)
{
	string reverse_N;
	for (auto it = N.crbegin();it!=N.crend(); it++)
		reverse_N.push_back(*it);
	return reverse_N;
}

string BigIntSum(string N1, string N2)
{
	string sum;
	unsigned int m = 0, n = 0;
	unsigned int length = N1.size();
	for (int i=length-1;i>=0;i--)
	{
		m = (N1[i] - '0') + (N2[i] - '0') + n;
		n = m / 10;
		sum.insert(0, 1, (m % 10 + '0'));
	}
	if (n)
	{
		sum.insert(0, 1, (n % 10 + '0'));
	}
	return sum;
}

int main(int argc, char *argv[])
{
	string N, r_N;
	unsigned int max_steps = 0;
	unsigned int i = 0;
	bool flag = false;
	cin >> N >> max_steps;
	for (i = 1; i <= max_steps; i++)
	{
		r_N = ReverseInt(N);
		N = BigIntSum(N, r_N);
		if (N == ReverseInt(N))
		{
			flag = true;
			break;
		}
	}
	cout << N << endl;
	cout << (flag ? i : max_steps) << endl;
	return 0;
}