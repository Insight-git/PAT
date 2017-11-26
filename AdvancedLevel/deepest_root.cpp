#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX_NUM_VEX 10000
typedef struct EdgeNode
{
	unsigned int adjvex;
	EdgeNode *next;
	EdgeNode()
	{
		this->adjvex = 0;
		this->next = NULL;
	}
}EdgeNode;

typedef struct VertexNode
{
	EdgeNode *first_adge;
	VertexNode()
	{
		this->first_adge = NULL;
	}
}VertexNode;
typedef struct
{
	VertexNode vex[MAX_NUM_VEX];
	unsigned int num_vexes, num_edges;
}Graph;

unsigned int max_depth = 0;

void DFS(Graph *graph, unsigned int n, bool *visited, unsigned int depth)
{
	EdgeNode *p;
	depth++;
	if (depth>max_depth)
		max_depth = depth;
	visited[n] = true;
	p = graph->vex[n].first_adge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(graph, p->adjvex, visited,depth);
		p = p->next;
	}
}

int main(int argc, char *argv[])
{
	Graph *graph = new Graph();
	unsigned int i = 0, j = 0;
	cin >> graph->num_vexes;
	graph->num_edges = graph->num_vexes - 1;
	//建立图
	for (i = 0; i<graph->num_edges;i++)
	{
		unsigned int m, n;
		cin >> m >> n;
		EdgeNode *node1 = new EdgeNode;
		node1->adjvex = n-1;
		node1->next = graph->vex[m-1].first_adge;
		graph->vex[m-1].first_adge = node1;

		//对称
		EdgeNode *node2 = new EdgeNode;
		node2->adjvex = m-1;
		node2->next = graph->vex[n-1].first_adge;
		graph->vex[n-1].first_adge = node2;
	}
	unsigned int *result = new unsigned int[graph->num_vexes] ();
	bool *visited = new bool[graph->num_vexes]();
	unsigned int count = 0;
	for (i = 0; i<graph->num_vexes; i++)
	{
		max_depth = 0;
		memset(visited, 0, sizeof(bool)*graph->num_vexes);
		count = 0;
		for (j = 0; j<graph->num_vexes; j++)
		{
			if (!visited[j])
			{
				count++;
				DFS(graph, count>1?j:i, visited, 0);
			}
		}
		if (count>1)
		{
			cout << "Error: " << count << " components" << endl;
			delete graph;
			delete [] visited;
			return 0;
		}
		result[i] = max_depth;
	}
	max_depth = *max_element(result, result+graph->num_vexes);
	for (i = 0; i<graph->num_vexes; i++)
	{
		if (result[i] == max_depth)
			cout << i+1 << endl;
	}
	delete graph;
	delete [] visited;
	return 0;
}