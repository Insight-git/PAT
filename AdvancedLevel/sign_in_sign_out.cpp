#include<iostream>
#include<string>
using namespace std;

#define INF 	0xFFFFFFFE

int main(int argc, char* argv[])
{
	unsigned int total_num_records = 0;
	unsigned int i = 0, j = 0;
	string id, start_time, end_time;
	string earliest_id, latest_id;
	unsigned long min_time = INF, max_time = 0;
	cin >> total_num_records;
	for (i = 0; i<total_num_records; i++)
	{
		cin >> id >> start_time >> end_time;
		start_time.erase(2,1);
		start_time.erase(4,1);
		end_time.erase(2,1);
		end_time.erase(4,1);
		unsigned long temp = stoul(start_time, NULL);
		if (temp < min_time)
		{
			min_time = temp;
			earliest_id = id;
		}
		temp = stoul(end_time, NULL);
		if (temp>max_time)
		{
			max_time = temp;
			latest_id = id;
		}
	}
	cout << earliest_id << ' ' << latest_id << endl;
	return 0;
}