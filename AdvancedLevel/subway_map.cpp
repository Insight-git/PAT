#include<iostream>
#include<vector>
#include<climits>
#include<iomanip>
//#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_NUM_STOPS 10000

vector<unsigned int> vex[MAX_NUM_STOPS];//邻接表
unsigned int line[MAX_NUM_STOPS][MAX_NUM_STOPS];

vector<unsigned int> result, path;
unsigned int min_stops = 0, min_trans = 0;
bool visited[MAX_NUM_STOPS] = {0};

void Print(vector<unsigned int> path)
{
	unsigned int pre_line = line[path[0]][path[1]];
	unsigned int pre_trans_stop = path[0];
	unsigned int i = 0;
	for(i=2;i<path.size();i++)
	{
		unsigned int temp_line = line[path[i-1]][path[i]];
		if(pre_line!=temp_line)
		{
			cout << "Take Line#" << pre_line << " from ";
			cout << setw(4) << setfill('0') << pre_trans_stop;
			cout << " to ";
			cout << setw(4) << setfill('0') << path[i-1];
			cout << '.' << endl;
			//printf("Take Line#%d from %04d to %04d.\n",pre_line,pre_trans_stop,path[i-1]);
			pre_line = temp_line;
			pre_trans_stop = path[i-1];
		}
	}
	cout << "Take Line#" << pre_line << " from ";
	cout << setw(4) << setfill('0') << pre_trans_stop;
	cout << " to ";
	cout << setw(4) << setfill('0') << path[i-1];
	cout << '.' << endl;
	//printf("Take Line#%d from %04d to %04d.\n",pre_line,pre_trans_stop,path[i-1]);
}
unsigned int GetTransfer(vector<unsigned int> path)
{
	unsigned int count = 0, pre_line = 0;
	unsigned int i = 0;
	for(i=1;i<path.size();i++)
	{
		unsigned int temp_line = line[path[i-1]][path[i]];
		if(pre_line!=temp_line)
		{
			count++;
			pre_line = temp_line;
		}
	}
	return count;
}
void DFS(unsigned int start, unsigned int end, unsigned int num_stops)
{
	path.push_back(start);
	visited[start] = true;
	if(start==end)
	{
		unsigned int num_trans = GetTransfer(path);
		if(num_stops<min_stops||(num_stops==min_stops&&num_trans<min_trans))
		{
			min_stops = num_stops;
			min_trans = num_trans;
			result = path;
		}
		return;
	}
	for(auto it=vex[start].cbegin();it!=vex[start].cend();it++)
	{
		if(!visited[*it])
		{
			DFS(*it, end, num_stops+1);
			path.pop_back();
			visited[*it] = false;
		}
	}
}

int main(int argc, char *argv[])
{
	unsigned int N = 0, M = 0, K = 0;
	unsigned int i = 0, j = 0;
	cin >> N;
	//scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		unsigned int S1 = 0, S2 = 0;
		cin >> M >> S1;
		//scanf("%d%d",&M,&S1);
		for(j=0;j<M-1;j++)
		{
			cin >> S2;
			//scanf("%d",&S2);
			line[S1][S2] = i;
			line[S2][S1] = i;
			vex[S1].push_back(S2);
			vex[S2].push_back(S1);
			S1 = S2;
		}
	}
	cin >> K;
	//scanf("%d",&K);
	for(i=0;i<K;i++)
	{
		unsigned int start = 0, end = 0;
		cin >> start >> end;
		//scanf("%d%d",&start,&end);
		min_stops = UINT_MAX;
		min_trans = UINT_MAX;
		path.clear();
		result.clear();
		memset(visited,false,sizeof(bool)*MAX_NUM_STOPS);
		DFS(start, end, 1);
		cout << result.size()-1 << endl;
		//printf("%d\n",result.size()-1);
		Print(result);
	}
	return 0;
}