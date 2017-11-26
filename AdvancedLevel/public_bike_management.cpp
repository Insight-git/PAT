#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

#define MAX_NUM_VEX 501
#define INF (UINT_MAX>>1)
typedef unsigned int VertexType;
typedef unsigned int EdgeType;
typedef struct
{
	VertexType vex[MAX_NUM_VEX];
	EdgeType arc[MAX_NUM_VEX][MAX_NUM_VEX];
	unsigned int num_vexes, num_edges;
}MGraph;

unsigned int num_perfect = 0;
unsigned int best_in = INF, best_out = INF;
vector<unsigned int> answer;

void Dijkstra(MGraph *graph, unsigned int start, vector<unsigned int> *next)
{
	bool *mark = new bool[graph->num_vexes] {};
	unsigned int *distance = new unsigned int[graph->num_vexes] {};
	unsigned int i = 0, j = 0;
	for(i=0;i<graph->num_vexes;i++)
		distance[i] = INF;
	distance[start] = 0;
	for(i=0;i<graph->num_vexes;i++)
	{
		int k = 0;
		for(j=0;j<graph->num_vexes;j++)
		{
			if(!mark[j]&&(distance[j]<distance[k]))
			{
				k = j;
			}
		}
		mark[k] = true;
		for(j=0;j<graph->num_vexes;j++)
		{
			if(!mark[j]&&(distance[k]+graph->arc[k][j])<distance[j])
			{
				distance[j] = distance[k] + graph->arc[k][j];
				next[j].clear();
				next[j].push_back(k);
			}
			else if(!mark[j]&&(distance[k]+graph->arc[k][j])==distance[j])
			{
				next[j].push_back(k);
			}
		}
	}
}

void DFS(MGraph *graph,unsigned int start, unsigned int end, int may_in, int may_out, vector<unsigned int> &path,vector<unsigned int> *next)
{
	unsigned int i = 0;
	if(may_in>best_in)//该路径上需要send的车数量大于best_in，提前剪枝返回，提高效率
		return;
	path.push_back(start);
	if(graph->vex[start] >= num_perfect)
		may_out += (graph->vex[start] - num_perfect);
	else
	{
		may_out -= (num_perfect - graph->vex[start]);
		if(may_out<0)
		{
			may_in -= may_out;
			may_out = 0;
		}
	}
	if(start==end)
	{
		if(may_in<best_in)
		{
			best_in = may_in;
			best_out = may_out;
			answer = path;
		}
		else if(may_in==best_in&&may_out<best_out)
		{
			best_in = may_in;
			best_out = may_out;
			answer = path;
		}
		path.pop_back();
		return;
	}
	for(i=0;i<next[start].size();i++)
	{
		DFS(graph,next[start][i],end,may_in,may_out,path,next);
	}
	path.pop_back();
}

int main(int argc, char *argv[])
{
	MGraph *graph = new MGraph {};
	unsigned int max_capacity = 0, id_problem_station = 0;
	unsigned int i = 0, j = 0;
	cin >> max_capacity >> graph->num_vexes >> id_problem_station >> graph->num_edges;
	graph->num_vexes += 1;
	graph->vex[0] = max_capacity >> 1; // !!!重点注意这个顶点，该顶点的值为num_perfect，不然在DFS的时候容易多算
	for(i=1;i<graph->num_vexes;i++)
	{
		cin >> graph->vex[i];
	}
	for(i=0;i<graph->num_vexes;i++)
	{
		for(j=0;j<graph->num_vexes;j++)
			graph->arc[i][j] = INF;
	}
	for(i=0;i<graph->num_edges;i++)
	{
		unsigned int m,n,t;
		cin >> m >> n >> t;
		graph->arc[m][n] = t;
		graph->arc[n][m] = t;
	}
	vector<unsigned int> *next = new vector<unsigned int>[graph->num_vexes];
	Dijkstra(graph,id_problem_station,next);
	num_perfect = max_capacity >> 1;
	vector<unsigned int> path;
	DFS(graph,0,id_problem_station,0,0,path,next);
	cout << best_in << ' ' << answer[0];
	for(i=1;i<answer.size();i++)
	{
		cout << "->" << answer[i];
	}
	cout << ' ' << best_out << endl;
	delete graph;
	delete [] next;
	return 0;
}