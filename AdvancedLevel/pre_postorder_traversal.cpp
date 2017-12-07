#include<iostream>
#include<vector>
using namespace std;

typedef struct Node
{
	int data;
	Node *left, *right;
	Node(int val)
	{
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
}Node;

Node* BuildTree(int *preorder_seq, int *postorder_seq, unsigned int N, bool &unique_flag)
{
	if (N == 0)
		return NULL;
	unsigned int i = 0;
	Node *node = new Node(preorder_seq[0]);
	if (N > 2)
	{
		for (i = 0; i<N&&preorder_seq[i] != postorder_seq[N - 2]; i++);
		node->left = BuildTree(preorder_seq + 1, postorder_seq, i - 1, unique_flag);
		node->right = BuildTree(preorder_seq + i, postorder_seq + i - 1, N - i, unique_flag);
	}
	else if (N == 2)
	{
		node->left = BuildTree(preorder_seq+1, postorder_seq, 1, unique_flag);
		unique_flag = false;
	}
	return node;
}

void InorderTraversal(Node *root, vector<int> &inorder_seq)
{
	if (!root)
		return;
	InorderTraversal(root->left,inorder_seq);
	inorder_seq.push_back(root->data);
	InorderTraversal(root->right,inorder_seq);
}

int main(int argc, char *argv[])
{
	unsigned int N = 0;
	unsigned int i = 0;
	cin >> N;
	int *preorder_seq = new int[N] {};
	int *postorder_seq = new int[N] {};
	for (i = 0; i<N; i++)
		cin >> preorder_seq[i];
	for (i = 0; i<N; i++)
		cin >> postorder_seq[i];
	bool unique_flag = true;
	Node *root = BuildTree(preorder_seq, postorder_seq, N, unique_flag);
	if (unique_flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	vector<int> inorder_seq;
	InorderTraversal(root, inorder_seq);
	for (i = 0; i<N; i++)
	{
		if (!i)
			cout << inorder_seq[i];
		else
			cout << ' ' << inorder_seq[i];
	}
	cout << endl;
	delete[] preorder_seq;
	delete[] postorder_seq;
	return 0;
}