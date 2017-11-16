#include<iostream>
using namespace std;

bool IsPrime(int n)
{
	unsigned int i = 0;
	if(n<=1)
		return false;
	for (i = 2; i <= n / i; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	int N = 0, D = 0;
	while (1)
	{
		cin >> N;
		if (N<0)
			break;
		cin >> D;
		if (IsPrime(N))
		{
			int temp = 0;
			do
			{
				temp = temp * D + N % D;
				N /= D;
			} while (N);
			if (IsPrime(temp))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}