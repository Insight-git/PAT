#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define LH 1
#define RH -1
#define EH 0

typedef struct Node
{
	int data;
	int bf;
	Node *left, *right;
	Node(int val)
	{
		this->data = val;
		this->bf = 0;
		this->left = NULL;
		this->right = NULL;
	}
}Node;

Node* L_Roate(Node *root)
{
	Node *node = root->right;
	root->right = node->left;
	node->left = root;
	root = node;
	return root;
}

Node* R_Roate(Node *root)
{
	Node *node = root->left;
	root->left = node->right;
	node->right = root;
	root = node;
	return root;
}

Node* LeftBalance(Node *root)
{
	Node *L, *Lr;
	L = root->left;
	switch (L->bf)
	{
	case LH:
		root->bf = EH;
		L->bf = EH;
		root = R_Roate(root);
		break;
	case RH:
		Lr = L->right;
		switch (Lr->bf)
		{
		case LH:
			root->bf = RH;
			L->bf = EH;
			break;
		case EH:
			root->bf = EH;
			L->bf = EH;
			break;
		case RH:
			root->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		root->left = L_Roate(root->left);
		root = R_Roate(root);
		break;
	}
	return root;
}

Node* RightBalance(Node *root)
{
	Node *R, *Rl;
	R = root->right;
	switch (R->bf)
	{
	case LH:
		Rl = R->left;
		switch (Rl->bf)
		{
		case LH:
			root->bf = EH;
			R->bf = RH;
			break;
		case EH:
			root->bf = EH;
			R->bf = EH;
			break;
		case RH:
			root->bf = LH;
			R->bf = EH;
			break;
		}
		Rl->bf = EH;
		root->right = R_Roate(root->right);
		root = L_Roate(root);
		break;
	case RH:
		root->bf = EH;
		R->bf = EH;
		root = L_Roate(root);
		break;
	}
	return root;
}

Node* InsertAVL(Node *root, int key, bool &taller)
{
	if (!root)
	{
		root = new Node(key);
		taller = true;
		return root;
	}
	if (key == root->data)
	{
		taller = false;
		return root;
	}
	if (key<root->data)
	{
		root->left = InsertAVL(root->left, key, taller);
		if (taller)
		{
			switch (root->bf)
			{
			case LH:
				root = LeftBalance(root);
				taller = false;
				break;
			case EH:
				root->bf = LH;
				taller = true;
				break;
			case RH:
				root->bf = EH;
				taller = false;
				break;
			}
		}
	}
	else
	{
		root->right = InsertAVL(root->right, key, taller);
		if (taller)
		{
			switch (root->bf)
			{
			case LH:
				root->bf = EH;
				taller = false;
				break;
			case EH:
				root->bf = RH;
				taller = true;
				break;
			case RH:
				root = RightBalance(root);
				taller = false;
				break;
			}
		}
	}
	return root;
}

vector<int> LevelOrderTraversal(Node *root, bool &complete_flag)
{
	queue<Node*> q;
	vector<int> level_order_seq;
	bool flag = false;
	Node *node = NULL;
	q.push(root);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		level_order_seq.push_back(node->data);
		if (node->left)
		{
			if(flag)
				complete_flag = false;
			q.push(node->left);
		}
		else
			flag = true;
		if (node->right)
		{
			if(flag)
				complete_flag = false;
			q.push(node->right);
		}
		else
			flag = true;
	}
	return level_order_seq;
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
	int key = 0;
	cin >> N;
	Node *root = NULL;
	bool taller = false;
	for (i = 0; i<N ; i++)
	{
		cin >> key;
		root = InsertAVL(root, key, taller);
	}
	bool complete_flag = true;
	vector<int> res = LevelOrderTraversal(root, complete_flag);
	cout << res[0];
	for (auto it = res.cbegin() + 1; it != res.cend(); it++)
		cout << ' ' << *it;
	cout << endl;
	if (complete_flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	DeleteTree(root);
	return 0;
}