#include<iostream>
#include<cstring>
#include<set>
using namespace std;

typedef struct Item
{
	unsigned int id;
	unsigned int time;
	bool operator < (const Item &a)const
	{
		if (this->time>a.time)
			return true;
		if (this->time == a.time&&id<a.id)
			return true;
		return false;
	}
}Item;

int main(int argc, char *argv[])
{
	unsigned int N = 0, K = 0;
	unsigned int i = 0;
	unsigned int index = 0;
	cin >> N >> K;
	unsigned int *times = new unsigned int[N + 1]{};
	set<Item> items;
	Item item;
	for (i = 0; i<N; i++)
	{
		cin >> index;
		if (i)
		{
			cout << index << ':';
			unsigned int count = 0;
			for (auto it = items.cbegin(); it != items.cend() && count<K; it++, count++)
			{
				cout << ' ' << it->id;
			}
			cout << endl;
		}
		item.id = index;
		item.time = times[index];
		if (items.find(item) != items.end())
			items.erase(item);
		times[index]++;
		item.id = index;
		item.time = times[index];
		items.insert(item);
	}
	delete[] times;
	return 0;
}

/*solution2 会超时*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct
{
	unsigned int id;
	unsigned int time;
}Item;

bool cmp(Item a, Item b)
{
	if (a.time > b.time)
		return true;
	if (a.time == b.time&&a.id < b.id)
		return true;
	return false;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0, K = 0;
	unsigned int i = 0, j = 0;
	unsigned int index = 0;
	cin >> N >> K;
	Item *item = new Item[N+1] {};
	Item *copy_item = new Item[N+1]{};
	for (i = 0; i<N; i++)
	{
		cin >> index;
		if (i)
		{
			memcpy(copy_item, item, sizeof(Item)*N);
			stable_sort(copy_item, copy_item + N, cmp);
			cout << index << ':';
			for (j = 0; j < 3; j++)
			{
				if (copy_item[j].time)
				{
					cout << ' ' << copy_item[j].id;
				}
			}
			cout << endl;
		}
		item[index].id = index;
		item[index].time++;
	}
	return 0;
}