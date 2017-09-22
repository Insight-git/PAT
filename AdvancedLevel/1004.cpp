#include <iostream>
using namespace std;

#define MAX_NODES	100

typedef struct ChildNode
{
	unsigned short int child_id;
	ChildNode *next;
	ChildNode()//默认构造函数
	{
		child_id = 0;
		next = NULL;
	}
}ChildNode;
typedef struct CTBox
{
	unsigned short int num_child;
	ChildNode *first_child;
	CTBox()
	{
		num_child = 0;
		first_child = NULL;
	}
}CTBox;

typedef struct
{
	CTBox nodes[MAX_NODES];
	unsigned short int num_nodes;
	unsigned short int num_levels;
}Tree;

/*void DFS(Tree *tree, unsigned short int level, unsigned short int id, \
	unsigned short int *num_nochild_level)
{
	ChildNode *child = tree->nodes[id].first_child;
	level++;
	while(child)
	{
		if(level>tree->num_levels)
			tree->num_levels = level;
		if(tree->nodes[child->child_id].num_child==0)	
			num_nochild_level[level]++;
		else
			DFS(tree, level, child->child_id, num_nochild_level);	//递归遍历该节点的孩子节点
		child = child->next;	//指向兄弟节点
	}
}*/

void DFS(Tree *tree, unsigned short int level, unsigned short int id, \
	unsigned short int *num_nochild_level)
{
	unsigned short int i = 0;
	ChildNode *child = NULL;
	if(tree->nodes[id].num_child==0)
	{
		num_nochild_level[level]++;
		if(tree->num_levels<level)
			tree->num_levels = level;
		return;
	}
	child = tree->nodes[id].first_child;
	for(i=0;i<tree->nodes[id].num_child;i++)
	{
		DFS(tree, level+1, child->child_id, num_nochild_level);//递归遍历该节点的孩子节点
		child = child->next;//指向兄弟节点
	}
}

int main(int argc, char *argv[])
{
	Tree *tree = new Tree {};//定义并初始化结构体，成员全部初始化为0
	unsigned short int num_nonleaf_nodes = 0;
	unsigned short int i = 0, j = 0;
	unsigned short int id = 0;
	unsigned short int num_nochild_level[MAX_NODES] = {0};
	cin >> tree->num_nodes >> num_nonleaf_nodes;
	tree->num_levels = 1;
	for(i=0;i<num_nonleaf_nodes;i++)
	{
		cin >> id;
		cin >> tree->nodes[id].num_child;
		for(j=0;j<tree->nodes[id].num_child;j++)
		{
			ChildNode *child = new ChildNode {};
			cin >> child->child_id;
			child->next = tree->nodes[id].first_child;
			tree->nodes[id].first_child = child;
		}
	}
	DFS(tree, tree->num_levels, 1, num_nochild_level);
	for(i=1;i<tree->num_levels;i++)
	{
		cout << num_nochild_level[i] << ' ';
	}
	cout << num_nochild_level[tree->num_levels];
	return 0;
}