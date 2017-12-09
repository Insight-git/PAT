/*solution 1  DFS*/
#include<iostream>
#include<cstring>
using namespace std;

#define MAX_VEX 	1000
typedef bool EdgeType;
typedef struct
{
	EdgeType arc[MAX_VEX][MAX_VEX];
	unsigned int num_vextexes, num_edges;
}MGraph;

void DFS(MGraph *graph,bool *visited,unsigned int now, unsigned int x)
{
	unsigned int i = 0;
	visited[now] = true;
	for(i=0;i<graph->num_vextexes;i++)
	{
		if(i!=x&&graph->arc[now][i]&&!visited[i])
			DFS(graph,visited,i,x);
	}
}

int main(int argc, char* argv[])
{
	MGraph *graph = new MGraph{};
	unsigned int num_cities_check;
	unsigned int i = 0,j = 0;
	cin >> graph->num_vextexes >> graph->num_edges >> num_cities_check;
	for (i = 0; i<graph->num_edges; i++)
	{
		unsigned int m, n;
		cin >> m >> n;
		graph->arc[m - 1][n - 1] = true;
		graph->arc[n - 1][m - 1] = true;
	}
	unsigned int id_city_check = 0;
	unsigned int num_highways_repair = 0;
	bool *visited = new bool[graph->num_vextexes] {};
	for (i = 0; i<num_cities_check; i++)
	{
		cin >> id_city_check;
		id_city_check--;
		num_highways_repair = 0;
		memset(visited,0,sizeof(bool)*graph->num_vextexes);
		for(j=0;j<graph->num_vextexes;j++)
		{
			if(j!=id_city_check&&!visited[j])
			{
				num_highways_repair++;
				DFS(graph,visited,j,id_city_check);
			}
		}
		num_highways_repair = num_highways_repair>0?num_highways_repair-1:0;
		cout << num_highways_repair << endl;
	}
	delete graph;
	delete [] visited;
	return 0;
}


/*solution 2  BFS*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define MAX_VEX 1000
typedef bool EdgeType;
typedef struct
{
	EdgeType arc[MAX_VEX][MAX_VEX];
	unsigned int num_vextexes, num_edges;
}MGraph;

int main(int argc, char *argv[])
{
	MGraph *graph = new MGraph {};
	unsigned int num_cities_check;
	unsigned int i = 0,j = 0,k = 0;
	cin >> graph->num_vextexes >> graph->num_edges >> num_cities_check; 
	for(i=0;i<graph->num_edges;i++)
	{
		unsigned int m,n;
		cin >> m >> n;
		graph->arc[m-1][n-1] = true;
		graph->arc[n-1][m-1] = true;
	}
	unsigned int id_city_check;
	bool *visited = new bool[graph->num_vextexes];
	unsigned int num_highways_repair = 0;
	for(i=0;i<num_cities_check;i++)
	{
		cin >> id_city_check;
		id_city_check--;
		memset(visited,false,sizeof(bool)*graph->num_vextexes);
		num_highways_repair = 0;
		queue<unsigned int> q;
		for(j=0;j<graph->num_vextexes;j++)
		{
			if(j!=id_city_check&&!visited[j])
			{
				num_highways_repair++;
				visited[j] = true;
				q.push(j);
				while(!q.empty())
				{
					unsigned int cur = q.front();
					q.pop();
					for(k=0;k<graph->num_vextexes;k++)
					{
						if(graph->arc[cur][k]&&!visited[k]&&k!=id_city_check)
						{
							visited[k] = true;
							q.push(k);
						}
					}
				}
			}
		}
		num_highways_repair = num_highways_repair>0?num_highways_repair-1:0;
		cout << num_highways_repair << endl;
	}
	delete graph;
	delete [] visited;
	return 0;
}

/*solution 3  Union-Find Set*/
#include<iostream>
using namespace std;

typedef struct 
{
	unsigned int begin;
	unsigned int end;
}Edge;

unsigned int Find(unsigned int x,unsigned int *parent)
{
	unsigned int root = x;
	while(root!=parent[root])
	{
		root = parent[root];
	}
	unsigned int temp = x;
	while(temp!=root)
	{
		temp = parent[x];
		parent[x] = root;
		x = temp;
	}
	return root;
}

void JoinSet(unsigned int u, unsigned int v, unsigned int *parent)
{
	unsigned int x = Find(u,parent);
	unsigned int y = Find(v,parent);
	if(x!=y)
		parent[x] = y;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0, M = 0, K = 0;
	unsigned int i = 0, j = 0;
	unsigned int temp = 0, sum = 0;
	cin >> N >> M >> K;
	unsigned int *parent = new unsigned int[N+1] {};
	Edge *edge = new Edge[M] {};
	for(i=0;i<M;i++)
	{
		cin >> edge[i].begin >> edge[i].end;
	}
	for(i=0;i<K;i++)
	{
		cin >> temp;
		for(j=0;j<=N;j++)//初始化并查集
		{
			parent[j] = j;
		}
		for(j=0;j<M;j++)
		{
			if(edge[j].begin!=temp&&edge[j].end!=temp)
				JoinSet(edge[j].begin,edge[j].end,parent);
		}
		sum = 0;
		for(j=1;j<=N;j++)
		{
			if(j==temp)
				continue;
			if(parent[j]==j)
				sum++;
		}
		sum = (sum == 0 ? 0 : (sum - 1));
		cout << sum << endl;
	}
	delete [] parent;
	delete [] edge;
	return 0;
}

