#include<iostream>
#include<queue>
using namespace std;

typedef struct Node
{
	int data;
	Node *left, *right;
	unsigned int level;
	Node(int val, unsigned int l)
	{
		this->data = val;
		this->level = l;
		this->left = NULL;
		this->right = NULL;
	}
}Node;

Node* InsertBST(Node *root, int data, unsigned int level, unsigned int &max_level)
{
	if (!root)
	{
		Node *node = new Node(data, level);
		if (level>max_level)
			max_level = level;
		return node;
	}
	if (data<=root->data)
		root->left = InsertBST(root->left, data, level + 1, max_level);
	else
		root->right = InsertBST(root->right, data, level + 1, max_level);
	return root;
}

Node* BuildTree(unsigned int N, unsigned int &max_level, int *seq)
{
	Node *root = new Node(seq[0], 1);
	unsigned int i = 0;
	max_level = 1;
	for (i = 1; i<N; i++)
		root = InsertBST(root, seq[i], 1, max_level);
	return root;
}

void LevelOrderTraversal(Node *root, unsigned int *count, unsigned int max_level)
{
	queue<Node*> q;
	Node *node = NULL;
	q.push(root);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node->level == max_level)
			count[0]++;
		if (node->level == max_level-1)
			count[1]++;
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
}

void DeleteTree(Node *root)
{
	if (!root)
		return;
	DeleteTree(root->left);
	DeleteTree(root->right);
	delete root;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0;
	unsigned int i = 0;
	cin >> N;
	int *seq = new int [N] {};
	for (i = 0; i<N; i++)
		cin >> seq[i];
	unsigned int max_level = 0;
	Node *root = BuildTree(N, max_level, seq);
	unsigned int *count = new unsigned int[2]{};
	LevelOrderTraversal(root, count, max_level);
	cout << count[0] << " + " << count[1] << " = " << (count[0] + count[1]) << endl;
	DeleteTree(root);
	delete[] seq;
	delete[] count;
	return 0;
}