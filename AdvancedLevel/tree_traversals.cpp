#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct Node
{
	unsigned int val;
	Node *left, *right;
	Node()
	{
		this->val = 0;
		this->left = NULL;
		this->right = NULL;
	}
}Node;

Node* BuildBinaryTree(unsigned int *post, unsigned int *in, unsigned int N)
{
	unsigned int i = 0;
	if (N == 0)
		return NULL;
	Node *root = new Node;
	for (i = 0; in[i] != post[N - 1]; i++);
	root->val = in[i];
	root->left = BuildBinaryTree(post, in, i);
	root->right = BuildBinaryTree(post + i, in + i + 1, N - 1 - i);
	return root;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0;
	unsigned int i = 0;
	vector<unsigned int> result;
	cin >> N;
	Node *root = new Node;
	unsigned int *post_order = new unsigned int[N]();
	unsigned int *in_order = new unsigned int[N]();
	for (i = 0; i<N; i++)
		cin >> post_order[i];
	for (i = 0; i<N; i++)
		cin >> in_order[i];

	root = BuildBinaryTree(post_order, in_order, N);
	queue<Node*> q;
	Node *node = new Node;
	if (root)
	{
		q.push(root);
		while (!q.empty())
		{
			node = q.front();
			result.push_back(node->val);
			q.pop();
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
	auto it = result.cbegin();
	for (; it != result.cend() - 1; it++)
		cout << *it << ' ';
	cout << *it << endl;
	return 0;
}