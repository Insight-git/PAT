#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N = 0;
	unsigned long Z = 0, A = 0, B = 0;
	unsigned int i = 0;
	string digits;
	cin >> N;
	for (i = 0; i<N; i++)
	{
		cin >> Z;
		digits = to_string(Z);
		unsigned int size = digits.size();
		if (size % 2 !=0)
		{
			cout << "No" << endl;
			continue;
		}
		A = Z / (unsigned long)pow(10, size / 2);
		B = Z % (unsigned long)pow(10, size / 2);
		if (A == 0 || B == 0)
		{
			cout << "No" << endl;
			continue;
		}
		if (Z % (A*B) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}