#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef struct Node
{
	unsigned int data;
	unsigned int level;
	Node *left, *right;
	Node()
	{
		this->data = 0;
		this->level = 0;
		this->left = NULL;
		this->right = NULL;
	}
}Node;

Node* BuildTree(unsigned int N, unsigned int level, unsigned int *in_order, unsigned int *post_order)
{
	if (N == 0)
		return NULL;
	Node *node = new Node();
	int i = 0;
	for (i = 0; in_order[i] != post_order[N - 1]; i++);
	node->data = in_order[i];
	node->level = level;
	node->left = BuildTree(i, level + 1, in_order, post_order);
	node->right = BuildTree(N - i - 1, level + 1, in_order + i + 1, post_order + i);
	return node;
}

void LevelOrderTraversal(Node *root)
{
	stack<Node*> s;
	queue<Node*> q;
	unsigned int i = 0;
	q.push(root);
	Node *node;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node->level == 1)
			cout << node->data;
		else
			cout << ' ' << node->data;
		if (node->level % 2 != 0)
		{
			if (node->right)
				s.push(node->right);
			if (node->left)
				s.push(node->left);
			if (q.empty())
			{
				while (!s.empty())
				{
					Node *temp = s.top();
					s.pop();
					q.push(temp);
				}
			}
		}
		else
		{
			if (node->left)
				s.push(node->left);
			if (node->right)
				s.push(node->right);
			if (q.empty())
			{
				while (!s.empty())
				{
					Node *temp = s.top();
					s.pop();
					q.push(temp);
				}
			}
		}
	}
	cout << endl;
}

void DeleteTree(Node *node)
{
	if (!node)
		return;
	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0;
	unsigned int i = 0;
	cin >> N;
	unsigned int *in_order = new unsigned int[N] {};
	unsigned int *post_order = new unsigned int[N] {};
	for (i = 0; i<N; i++)
		cin >> in_order[i];
	for (i = 0; i<N; i++)
		cin >> post_order[i];
	Node *root = BuildTree(N, 1, in_order, post_order);
	LevelOrderTraversal(root);
	DeleteTree(root);
	delete[] in_order;
	delete[] post_order;
	return 0;
}