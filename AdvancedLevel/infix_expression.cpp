#include<iostream>
#include<string>
#include<set>
using namespace std;

typedef struct 
{
	string data;
	int left, right;
}Node;

void InOrderTraversal(Node *node, int indice, int root)
{
	if(indice==-1)
		return;
	if(indice!=root&&(node[indice].left!=-1||node[indice].right!=-1))
		cout << '(';
	InOrderTraversal(node,node[indice].left,root);
	cout << node[indice].data;
	InOrderTraversal(node,node[indice].right,root);
	if(indice!=root&&(node[indice].left!=-1||node[indice].right!=-1))
		cout << ')';
}

int main(int argc, char *argv[])
{
	unsigned int N = 0;
	unsigned int i = 0;
	unsigned int root = 0;
	cin >> N;
	Node *node = new Node[N+1] {};
	set<int> indices;
	for(i=1;i<=N;i++)
	{
		cin >> node[i].data >> node[i].left >> node[i].right;
		indices.insert(node[i].left);
		indices.insert(node[i].right);
	}
	for(i=1;i<=N;i++)
	{
		if(indices.find(i)==indices.end())
		{
			root = i;
			break;
		}
	}
	InOrderTraversal(node,root,root);
	delete [] node;
	return 0;
}