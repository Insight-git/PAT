#include<iostream>
#include<set>
using namespace std;

#define MAX_VEX 200
typedef struct
{
	bool arc[MAX_VEX][MAX_VEX];
	unsigned int num_vexes, num_edges;
}MGraph;

int main(int argc, char *argv[])
{
	MGraph *graph = new MGraph{};
	unsigned int K = 0, n = 0;
	unsigned int i = 0, j = 0;
	unsigned int temp_m = 0, temp_n = 0;
	set<unsigned int> path;
	unsigned int pre_vex = 0, cur_vex = 0;
	bool flag = false;
	cin >> graph->num_vexes >> graph->num_edges;
	for (i = 0; i<graph->num_edges; i++)
	{
		cin >> temp_m >> temp_n;
		graph->arc[temp_m - 1][temp_n - 1] = true;
		graph->arc[temp_n - 1][temp_m - 1] = true;
	}
	cin >> K;
	for (i = 0; i<K; i++)
	{
		path.clear();
		flag = false;
		cin >> n;
		cin >> pre_vex;
		temp_n = pre_vex;
		for (j = 0; j<n - 1; j++)
		{
			cin >> cur_vex;
			auto it = path.insert(cur_vex - 1);
			if (!it.second)
				flag = true;
			if (!graph->arc[pre_vex - 1][cur_vex - 1])
				flag = true;
			pre_vex = cur_vex;
		}
		if (temp_n != pre_vex)
			flag = true;
		if (path.size() != graph->num_vexes)
			flag = true;
		if (flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	delete graph;
	return 0;
}