#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

typedef struct
{
	unsigned int start_time;
	unsigned int waste_time;
	unsigned int end_time;
}Customer;

int main(int argc, char* argv[])
{
	unsigned int N = 0, M = 0, K = 0, Q = 0;
	unsigned int i = 0, j = 0, t = 0, id = 0;
	cin >> N >> M >> K >> Q;
	queue<unsigned int> *q = new queue<unsigned int>[N] {};
	Customer *cus = new Customer[K]{};
	for (i = 0; i<K; i++)
	{
		cin >> cus[i].waste_time;
	}
	for (t = 8 * 60, id = 0;;)
	{
		for (; id<K; id++)
		{
			unsigned int min_index = 0;
			for (j = 0; j<N; j++)	//找最短队列
			{
				if (q[j].size()<q[min_index].size())
					min_index = j;
			}
			if (q[min_index].size() >= M)//窗口满
				break;
			cus[id].start_time = q[min_index].empty() ? t : cus[q[min_index].back()].end_time;
			cus[id].end_time = cus[id].start_time + cus[id].waste_time;
			q[min_index].push(id);
		}
		if (id >= K)	break; 	//所有人均已入队
		t = cus[q[0].front()].end_time;
		for (j = 0; j<N; j++)
		{
			if (cus[q[j].front()].end_time<t)
				t = cus[q[j].front()].end_time;
		}
		for (j = 0; j<N; j++)
		{
			if (cus[q[j].front()].end_time == t)
				q[j].pop();
		}
	}
	for (i = 0; i<Q; i++)
	{
		cin >> id;
		id--;
		if (cus[id].start_time>=17 * 60)
			cout << "Sorry" << endl;
		else
		{
			cout << setfill('0')<< setw(2) << (int)(cus[id].end_time / 60);
			cout << ':';
			cout << setfill('0') << setw(2) << cus[id].end_time % 60 << endl;
		}
	}
	delete[] q;
	delete[] cus;
	return 0;
}