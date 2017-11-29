# 解题思路
- 方法：
	- 将结点用list[100000]保存，list为Node类型，Node中保存结点的地址，结点的data，结点的next地址，list的下标就是结点的地址;
	- 遍历三次list，把<0,0~K,K>三部分结点依次保存在vector<Node> result中；
	- 最后依次输出result中的结点值，result[i].addr,result[i].data,result[i+1].addr;
	- 注意最后一个结点的next地址为-1；
