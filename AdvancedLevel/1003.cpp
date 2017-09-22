#include <iostream>
using namespace std;

#define MAX_VERTEX	500
#define INFINITY	65535

typedef unsigned int VertexType;
typedef unsigned int EdgeType;
typedef struct
{
	VertexType vex[MAX_VERTEX];
	EdgeType arc[MAX_VERTEX][MAX_VERTEX];
	unsigned int num_vexs, num_edges;
}MGraph;

void CreateMGraph(MGraph *graph)
{
	unsigned int i = 0, j = 0;
	unsigned int c1 = 0, c2 = 0, L = 0;
	for(i=0;i<graph->num_vexs;i++)
	{
		cin >> graph->vex[i];
		for(j=0;j<graph->num_vexs;j++)
		{
			graph->arc[i][j] = INFINITY;
		}
	}
	for(i=0;i<graph->num_edges;i++)
	{
		cin >> c1 >> c2 >> L;
		graph->arc[c1][c2] = L;
		graph->arc[c2][c1] = L;
	}
}

void SearchShortestPath(MGraph *graph, unsigned int *path, unsigned int *rescue, unsigned int c1, unsigned int c2)
{
	unsigned int i = 0, j = 0;
	bool visited[MAX_VERTEX];
	unsigned int distance[MAX_VERTEX];
	unsigned int new_pos = 0;
	unsigned int min = 0;
	for(i=0;i<graph->num_vexs;i++)
	{
		visited[i] = false;
		distance[i] = graph->arc[c1][i];
		rescue[i] = graph->vex[i];
		path[i] = 1;//初始化每个顶点的路径只有一条
		//if(graph->arc[c1][i]<INFINITY)//与c1相邻的节点
		//{
		//	path[i] = 1;
		//	rescue[i] += graph->vex[c1];
		//}
	}
	path[c1] = 1;
	distance[c1] = 0;
	visited[c1] = true;
	rescue[c1] = graph->vex[c1];
	
	for(i=0;i<graph->num_vexs;i++)
	{
		min = INFINITY;
		for(j=0;j<graph->num_vexs;j++)
		{
			if(!visited[j]&&distance[j]<min)
			{
				min = distance[j];
				new_pos = j;
			}
		}
		visited[new_pos] = true;
		for(j=0;j<graph->num_vexs;j++)
		{
			if(!visited[j]&&graph->arc[new_pos][j]<INFINITY)//与new_pos相邻的节点
			{
				if((min+graph->arc[new_pos][j])<distance[j])
				{
					distance[j] = min + graph->arc[new_pos][j];
					rescue[j] = rescue[new_pos] + graph->vex[j];
					path[j] = path[new_pos];//细节
				}
				else if((min+graph->arc[new_pos][j])==distance[j])
				{
					path[j] += path[new_pos];//细节
					if((rescue[new_pos]+graph->vex[j])>rescue[j])
						rescue[j] = rescue[new_pos] + graph->vex[j];
				}
			}
		}
	}
	for(j=0;j<graph->num_vexs;j++)
	{
		if(j==c1)
			continue;
		rescue[j] += rescue[c1];
	}
}


int main(int argc, char *argv[])
{
	MGraph *emergency_map = new MGraph;
	unsigned int current_pos = 0, saved_pos = 0;
	unsigned int path[MAX_VERTEX] = {0}, rescue[MAX_VERTEX] = {0};
	cin >> emergency_map->num_vexs >> emergency_map->num_edges >> current_pos >> saved_pos;
	CreateMGraph(emergency_map);
	SearchShortestPath(emergency_map, path, rescue, current_pos, saved_pos);
	cout << path[saved_pos] << " " << rescue[saved_pos];
}