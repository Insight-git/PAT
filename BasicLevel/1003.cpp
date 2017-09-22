#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(unsigned int n)
{
	unsigned int i = 0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	unsigned short int M, N;
	unsigned int i = 0, j = 0;
	unsigned short int prime_count = 0;
	cin >> M >> N;
	for(i=2;;i++)
	{
		if(IsPrime(i))
		{
			prime_count++;
			if(prime_count>=M&&prime_count<=N)
			{
				j++;
				cout << i;
				if(j==10)
				{
					j = 0;
					cout << endl;
				}
				else if(prime_count == N)
				{
					cout << endl;
					break;
				}
				else
					cout << " ";
			}	
		}
	}
}