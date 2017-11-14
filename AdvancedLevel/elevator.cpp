#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	unsigned int N = 0;
	unsigned int i = 0;
	unsigned int last_floor = 0, cur_floor = 0;
	unsigned int total_time = 0;
	int temp = 0;
	cin >> N;
	for(i=0;i<N;i++)
	{
		cin >> cur_floor;
		temp = cur_floor - last_floor;
		if(temp>0)
			total_time += temp * 6 + 5;
		else
			total_time += abs(temp) * 4 + 5;
		last_floor = cur_floor;
	}
	cout << total_time;
	return 0;
}