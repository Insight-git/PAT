#include<iostream>
#include<cmath>
using namespace std;

typedef struct Node
{
	unsigned int data;
	Node *left, *right;
	bool is_black;
	Node()
	{
		this->data = 0;
		this->left = NULL;
		this->right = NULL;
		this->is_black = true;
	}
};

int num_black_path = -1;
bool black_red_tree_flag = true;

Node* CreateTree(int left, int right, int *data)
{
	if(left>right)
		return NULL;
	Node *node = new Node();
	if(data[left]>0)
		node->is_black = true;
	else
		node->is_black = false;
	node->data = abs(data[left]);
	unsigned int i = left+1;
	for(;i<=right;i++)
	{
		if(abs(data[i])>abs(data[left]))
			break;
	}
	node->left = CreateTree(left+1,i-1,data);
	node->right = CreateTree(i,right,data);
	return node;
}

void DFS(Node *node,unsigned int num_black)
{
	if(!node)
	{
		if(num_black_path==-1)
			num_black_path = num_black;
		else if(num_black_path!=num_black)
			black_red_tree_flag = false;
		return;
	}
	if(node->is_black)
		num_black++;
	else
	{
		if(node->left&&!node->left->is_black)
		{
			black_red_tree_flag = false;
			return;
		}
		if(node->right&&!node->right->is_black)
		{
			black_red_tree_flag = false;
			return;
		}
	}
	DFS(node->left,num_black);
	DFS(node->right,num_black);
}

void DeleteTree(Node *node)
{
	if(!node)
		return;
	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
}

int main(int argc, char *argv[])
{
	unsigned int K = 0, N = 0;
	unsigned int i = 0, j = 0;
	cin >> K;
	for(i=0;i<K;i++)
	{
		cin >> N;
		int *data = new int[N] {};
		for(j=0;j<N;j++)
			cin >> data[j];
		Node *root = CreateTree(0,N-1,data);
		black_red_tree_flag = root->is_black;//根结点必须是黑色
		num_black_path = -1;//容易忘记初始化
		DFS(root,0);
		if(black_red_tree_flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		DeleteTree(root);
		delete [] data;
	}
	return 0;
}