#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

typedef struct
{
	unsigned long arriving_time;
	unsigned long start_time;
	unsigned long end_time;
	unsigned long process_time;
	unsigned long wait_time;
}Curstomer;

bool cmp(Curstomer a, Curstomer b)
{
	if (a.arriving_time<b.arriving_time)
		return true;
	return false;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0, K = 0;
	unsigned int i = 0, t = 0, id = 0;
	unsigned long total_wait_time = 0, num_wait_people = 0;
	cin >> N >> K;
	Curstomer *cur = new Curstomer[N]{};
	queue<unsigned int> *q = new queue<unsigned int>[K] {};
	unsigned int HH, MM, SS;
	for (i = 0; i<N; i++)
	{
		scanf("%d:%d:%d %d", &HH, &MM, &SS, &cur[i].process_time);
		cur[i].process_time = cur[i].process_time > 60 ? 60 * 60 : cur[i].process_time * 60;
		cur[i].arriving_time = HH * 3600 + MM * 60 + SS;
	}
	sort(cur, cur + N, cmp);
	unsigned long *last_time = new unsigned long[K] {};
	for (i = 0; i<K; i++)
		last_time[i] = 8 * 3600;
	for (t = 8 * 3600, id = 0;;)
	{
		for (i = 0; i<K; i++)
		{
			if (q[i].empty())
			{
				if(cur[id].arriving_time>last_time[i])
					last_time[i] = cur[id].arriving_time;
				cur[id].start_time = last_time[i];
				cur[id].end_time = cur[id].start_time + cur[id].process_time;
				cur[id].wait_time = cur[id].start_time - cur[id].arriving_time;
				q[i].push(id);
				id++;
			}
		}
		if (id >= N) break;
		t = cur[q[0].front()].end_time;
		for (i = 0; i<K; i++)
		{
			if (cur[q[i].front()].end_time<t)
				t = cur[q[i].front()].end_time;
		}
		for (i = 0; i<K; i++)
		{
			if (cur[q[i].front()].end_time == t)
			{
				q[i].pop();
				last_time[i] = t;
			}
		}
	}
	for (id = 0; id<N; id++)
	{
		if (cur[id].arriving_time>17 * 3600)
			continue;
		total_wait_time += cur[id].wait_time;
		num_wait_people++;
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << total_wait_time / (60.0 * num_wait_people) << endl;
	delete [] cur;
	delete [] q;
	delete [] last_time;
	return 0;
}