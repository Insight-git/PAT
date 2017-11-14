/*solution 1*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	unsigned int seq_length = 0;
	int i = 0, j = 0;
	vector<int> sequence;
	int temp = 0;
	int sum = 0, max_sum = 0;
	int start = 0, end = 0;
	cin >> seq_length;
	for (i = 0; i<seq_length; i++)
	{
		cin >> temp;
		sequence.push_back(temp);
	}
	for (i = 0; i<seq_length; i++)
	{
		if (sequence[i]<0)
		{
			continue;
		}
		sum = 0;
		for (j = i; j<seq_length; j++)
		{
			sum += sequence[j];
			if(sum<0)
				break;
			if (sum>max_sum)
			{
				max_sum = sum;
				start = i;
				end = j;
			}
		}
		i = j;
	}
	if (max_sum == 0)
	{
		start = 0;
		end = seq_length - 1;
	}
	cout << max_sum << ' ' << sequence[start] << ' ' << sequence[end];
	return 0;
}

/*solution 2*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	unsigned int seq_length = 0;
	int i = 0, j = 0;
	vector<int> sequence;
	int temp = 0;
	int sum = -1, max_sum = 0;
	int start = 0, end = 0;
	cin >> seq_length;
	for (i = 0; i<seq_length; i++)
	{
		cin >> temp;
		sequence.push_back(temp);
	}
	for (i = 0; i<seq_length; i++)
	{
		if(sum<0)
		{
			sum = 0;
			temp = i;
		}
		sum += sequence[i];
		if(sum>max_sum)
		{
			max_sum = sum;
			start = temp;
			end = i;
		}
	}
	if (max_sum == 0)
	{
		start = 0;
		end = seq_length - 1;
	}
	cout << max_sum << ' ' << sequence[start] << ' ' << sequence[end];
	return 0;
}