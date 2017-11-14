#include<iostream>
#include<string>
#include<string.h>
using namespace std;

typedef struct Student
{
	char id[6];
	unsigned int grade[4];
	unsigned int rank[4];
	Student()
	{
		memset(this, 0, sizeof(Student));
	}

}Student;

int FindId(Student *stu, unsigned int N, string id)
{
	unsigned int i = 0;
	string cmp_id;
	for (i = 0; i<N; i++)
	{
		cmp_id = stu[i].id;
		if (cmp_id == id)
			return i;
	}
	return -1;
}

int main(int argc, char* argv[])
{
	unsigned int N, M;
	int i = 0, j = 0;
	char sub_name[4] = { 'A','C','M','E' };
	cin >> N >> M;
	Student *stu = new Student[N];
	unsigned int *num_stu = new unsigned int[101] {};
	string id;
	for (i = 0; i<N; i++)
	{
		cin >> id;
		memcpy(stu[i].id, id.data(),id.length());
		cin >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3;
	}
	for (i = 0; i<4; i++)
	{
		memset(num_stu, 0, sizeof(unsigned int) * 101);
		for (j = 0; j<N; j++)
		{
			num_stu[stu[j].grade[i]]++;
		}
		for (j = 99; j >= 0; j--)
		{
			num_stu[j] += num_stu[j + 1];
		}
		for (j = 0; j<N; j++)
		{
			stu[j].rank[i] = num_stu[stu[j].grade[i] + 1] + 1;
		}
	}
	string temp_id;
	int temp = 0;
	for (i = 0; i<M; i++)
	{
		cin >> temp_id;
		temp = FindId(stu, N, temp_id);
		if (temp == -1)
			cout << "N/A" << endl;
		else
		{
			int x = 0;
			for (j = 1; j<4; j++)
			{
				if (stu[temp].rank[j]<stu[temp].rank[x])
					x = j;
			}
			cout << stu[temp].rank[x] << ' ' << sub_name[x] << endl;
		}
	}
	delete [] stu;
	delete [] num_stu;
	return 0;
}