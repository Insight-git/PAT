#include<iostream>
#include<cmath>
#include<string>
using namespace std;

long long StringToInt(string N, long long radix)
{
	long long n = 0;
	for (auto it : N)
	{
		n *= radix;
		n += (it >= 'a' ? it - 'a' + 10 : it - '0');
	}
	return n;
}

int main(int argc, char* argv[])
{
	string N1, N2;
	unsigned int tag = 0, radix = 0;
	unsigned int max_digit = 0;
	long long num = 0;
	string target;
	cin >> N1 >> N2 >> tag >> radix;
	if (N1 == N2)
	{
		cout << radix << endl;
		return 0;
	}
	if (tag == 1)
	{
		num = StringToInt(N1, radix);
		unsigned int temp;
		for (auto it : N2)
		{
			temp = (it >= 'a' ? it - 'a' + 10 : it - '0');
			if (temp>max_digit)
				max_digit = temp;
		}
		target = N2;
	}
	else
	{
		num = StringToInt(N2, radix);
		unsigned int temp;
		for (auto it : N1)
		{
			temp = (it >= 'a' ? it - 'a' + 10 : it - '0');
			if (temp>max_digit)
				max_digit = temp;
		}
		target = N1;
	}
	long long left = max_digit + 1;
	long long right = num > left ? num : left;
	while (left <= right)
	{
		long long mid = ((right - left) >> 1) + left;
		long long num_target = StringToInt(target, mid);
		if (num_target == num)
		{
			cout << mid << endl;
			return 0;
		}
		else if (num_target<num)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << "Impossible" << endl;
	return 0;
}