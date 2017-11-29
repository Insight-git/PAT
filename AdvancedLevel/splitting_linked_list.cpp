#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef struct Node
{
	int addr;
	int data;
	int next;
}Node;

int main(int argc, char *argv[])
{
	int head = 0, N = 0, K = 0;
	int i = 0;
	Node *list = new Node[100000] {};
	cin >> head >> N >> K;
	for(i=0;i<N;i++)
	{
		int pos;
		cin >> pos;
		cin >> list[pos].data >> list[pos].next;
		list[pos].addr = pos;
	}
	vector<Node> result;
	int p = head;
	while(p!=-1)
	{
		if(list[p].data<0)
			result.push_back(list[p]);
		p = list[p].next;
	}
	p = head;
	while(p!=-1)
	{
		if(list[p].data>=0&&list[p].data<=K)
			result.push_back(list[p]);
		p = list[p].next;
	}
	p = head;
	while(p!=-1)
	{
		if(list[p].data>K)
			result.push_back(list[p]);
		p = list[p].next;
	}
	for(i=0;i<result.size()-1;i++)
	{
		cout << setw(5) << setfill('0') << result[i].addr << ' ';
		cout << result[i].data << ' ';
		cout << setw(5) << setfill('0') << result[i+1].addr << endl;
	}
	cout << setw(5) << setfill('0') << result[i].addr << ' ';
	cout << result[i].data << ' ' << "-1" << endl;
	delete [] list;
	return 0;
}