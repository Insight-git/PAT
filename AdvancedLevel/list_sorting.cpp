#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct
{
	unsigned int id;
	string name;
	unsigned int grade;
}Record;

bool cmp1(Record a, Record b)
{
	if (a.id<b.id)
		return true;
	return false;
}

bool cmp2(Record a, Record b)
{
	if (a.name<b.name)
		return true;
	else if (a.name == b.name)
		return (a.id<b.id);
	return false;
}

bool cmp3(Record a, Record b)
{
	if (a.grade<b.grade)
		return true;
	else if (a.grade == b.grade)
		return (a.id<b.id);
	return false;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0, C = 0;
	unsigned int i = 0;
	cin >> N >> C;
	Record *rec = new Record[N]{};
	char s[8] = { 0 };
	for (i = 0; i < N; i++)
	{
		scanf("%d%s%d", &rec[i].id, s, &rec[i].grade);
		rec[i].name = s;
	}
	switch (C)
	{
		case 1:
		{
			sort(rec, rec + N, cmp1);
			break;
		}
		case 2:
		{
			sort(rec, rec + N, cmp2);
			break;
		}
		case 3:
		{
			sort(rec, rec + N, cmp3);
			break;
		}
		default:
			break;
	}
	for (i = 0; i < N; i++)
	{
		printf("%06d %s %d\n", rec[i].id, rec[i].name.c_str(), rec[i].grade);
	}
	return 0;
}