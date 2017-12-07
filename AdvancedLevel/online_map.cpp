#include<iostream>
#include<vector>
//#include<cstring>
#include<climits>
using namespace std;

#define MAX_NUM_VEX 501
#define INF (UINT_MAX>>1)
typedef struct
{
	unsigned int length[MAX_NUM_VEX][MAX_NUM_VEX];
	unsigned int time[MAX_NUM_VEX][MAX_NUM_VEX];
	unsigned int num_vexes, num_edges;
}MGraph;


vector<unsigned int> min_dis_path;
vector<unsigned int> min_time_path;
vector<unsigned int> path;
unsigned int min_dis = INF;
unsigned int min_time = INF;
unsigned int min_count = INF;

void Dijsktra(MGraph *graph, unsigned int start, vector<unsigned int> *length_path, vector<unsigned int> *time_path)
{
	bool *visited = new bool[graph->num_vexes]{};
	unsigned int i = 0, j = 0;
	unsigned int *distance = new unsigned int[graph->num_vexes]{};
	unsigned int *time = new unsigned int[graph->num_vexes]{};
	
	/*求距离最短路径*/
	//memset(distance, INF, sizeof(unsigned int)*(graph->num_vexes));
	for (i = 0; i < graph->num_vexes; i++)
		distance[i] = INF;
	distance[start] = 0;
	for (i = 0; i<graph->num_vexes; i++)
	{
		unsigned int k = 0;
		unsigned int min = INF;
		for (j = 0; j<graph->num_vexes; j++)
		{
			if (!visited[j] && distance[j] < min)
			{
				min = distance[j];
				k = j;
			}
		}
		visited[k] = true;
		for (j = 0; j<graph->num_vexes; j++)
		{
			unsigned int temp = graph->length[k][j] + min;
			if (!visited[j] && temp < distance[j])
			{
				distance[j] = temp;
				length_path[j].clear();
				length_path[j].push_back(k);
			}
			else if (!visited[j] && temp == distance[j])
				length_path[j].push_back(k);
		}
	}
	/*求时间最短路径*/
	//memset(time, INF, sizeof(unsigned int)*(graph->num_vexes));
	//memset(visited, false, sizeof(bool)*graph->num_vexes);
	for (i = 0; i < graph->num_vexes; i++)
	{
		time[i] = INF;
		visited[i] = false;
	}
	time[start] = 0;
	for (i = 0; i<graph->num_vexes; i++)
	{
		unsigned int k = 0;
		unsigned int min = INF;
		for (j = 0; j<graph->num_vexes; j++)
		{
			if (!visited[j] && time[j] < min)
			{
				k = j;
				min = time[j];
			}
		}
		visited[k] = true;
		for (j = 0; j<graph->num_vexes; j++)
		{
			unsigned int temp = graph->time[k][j] + time[k];
			if (!visited[j] && temp < time[j])
			{
				time[j] = temp;
				time_path[j].clear();
				time_path[j].push_back(k);
			}
			else if (!visited[j] && temp == time[j])
				time_path[j].push_back(k);
		}
	}
	delete[] visited;
	delete[] distance;
	delete[] time;
}

void Dis_DFS(MGraph *graph, unsigned int start, unsigned int end, unsigned int dis, unsigned int time, vector<unsigned int> *length_path)
{
	path.push_back(start);
	if (start == end)
	{
		if (dis<min_dis)
		{
			min_dis = dis;
			min_time = time;
			min_dis_path = path;
		}
		else if (dis == min_dis&&time < min_time)
		{
			min_dis = dis;
			min_time = time;
			min_dis_path = path;
		}
		return;
	}
	for (auto it : length_path[start])
	{
		Dis_DFS(graph, it, end, dis + graph->length[it][start], time + graph->time[it][start], length_path);
		path.pop_back();
	}
}

void Time_DFS(MGraph *graph, unsigned int start, unsigned int end, unsigned int time, unsigned int count, vector<unsigned int> *time_path)
{
	path.push_back(start);
	if (start == end)
	{
		if (time<min_time)
		{
			min_count = count;
			min_time = time;
			min_time_path = path;
		}
		else if (time == min_time&&count < min_count)
		{
			min_count = count;
			min_time = time;
			min_time_path = path;
		}
		return;
	}
	for (auto it : time_path[start])
	{
		Time_DFS(graph, it, end, time + graph->time[it][start], count + 1, time_path);
		path.pop_back();
	}
}

int main(int argc, char *argv[])
{
	MGraph *graph = new MGraph{};
	unsigned int i = 0, j = 0;
	unsigned int m = 0, n = 0, temp = 0;
	unsigned int start = 0, end = 0;
	cin >> graph->num_vexes >> graph->num_edges;
	for (i = 0; i < graph->num_vexes; i++)
	{
		for (j = 0; j < graph->num_vexes; j++)
		{
			graph->length[i][j] = INF;
			graph->time[i][j] = INF;
		}
	}
	//memset(graph->length, 0, sizeof(unsigned int)*MAX_NUM_VEX*MAX_NUM_VEX);
	//memset(graph->time, INF, sizeof(unsigned int)*MAX_NUM_VEX*MAX_NUM_VEX);
	for (i = 0; i<graph->num_edges; i++)
	{
		cin >> m >> n >> temp;
		cin >> graph->length[m][n] >> graph->time[m][n];
		if (!temp)
		{
			graph->length[n][m] = graph->length[m][n];
			graph->time[n][m] = graph->time[m][n];
		}
	}
	cin >> start >> end;
	vector<unsigned int> *length_path = new vector<unsigned int>[graph->num_vexes];
	vector<unsigned int> *time_path = new vector<unsigned int>[graph->num_vexes];
	Dijsktra(graph, start, length_path, time_path);
	Dis_DFS(graph, end, start, 0, 0, length_path);
	min_time = INF;
	path.clear();
	Time_DFS(graph, end, start, 0, 1, time_path);
	bool flag = false;
	if (min_dis_path.size() == min_time_path.size())
	{
		flag = true;
		for (i = 0; i<min_time_path.size(); i++)
		{
			if (min_dis_path[i] != min_time_path[i])
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
	{
		cout << "Distance = " << min_dis << "; Time = " << min_time << ": ";
		auto it = min_dis_path.crbegin();
		cout << *it;
		it++;
		for (; it != min_dis_path.crend(); it++)
			cout << " -> " << *it;
		cout << endl;
	}
	else
	{
		cout << "Distance = " << min_dis << ": ";
		auto it = min_dis_path.crbegin();
		cout << *it;
		it++;
		for (; it != min_dis_path.crend(); it++)
			cout << " -> " << *it;
		cout << endl;
		cout << "Time = " << min_time << ": ";
		it = min_time_path.crbegin();
		cout << *it;
		it++;
		for (; it != min_time_path.crend(); it++)
			cout << " -> " << *it;
		cout << endl;
	}
	delete graph;
	delete[] length_path;
	delete[] time_path;
	return 0;
}