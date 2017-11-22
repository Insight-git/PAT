#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

#define NUM_HOURS 	24

typedef struct
{
	char name[20];
	unsigned int month;
	unsigned int day;
	unsigned int hh;
	unsigned int mm;
	bool on_line;
}Records;

bool cmp(const Records &a, const Records &b)
{
	int t = strcmp(a.name, b.name);
	if (t)
	{
		return (t < 0);
	}
	return (a.day * 1440 + a.hh * 60 + a.mm) < (b.day * 1440 + b.hh * 60 + b.mm);
}

unsigned int CalcPay(Records rec1, Records rec2, unsigned int *cents)
{
	unsigned int time = 0, pay = 0;
	Records rec = rec1;
	for (; rec.day < rec2.day; rec.day++)
	{
		time += (60 - rec.mm);
		pay += (60 - rec.mm) * cents[rec.hh++];
		rec.mm = 0;
		for (; rec.hh < NUM_HOURS; rec.hh++)
		{
			time += 60;
			pay += 60 * cents[rec.hh];
		}
		rec.hh = 0;
	}
	for (; rec.hh < rec2.hh; rec.hh++)
	{
		time += (60 - rec.mm);
		pay += (60 - rec.mm) * cents[rec.hh];
		rec.mm = 0;
	}
	time += (rec2.mm - rec.mm);
	pay += (rec2.mm - rec.mm) * cents[rec.hh];
	cout << time << ' ' << '$';
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << (float)pay / 100 << endl;
	return pay;
}


int main(int argc, char *argv[])
{
	unsigned int cents_minute[NUM_HOURS] = { 0 };
	unsigned int N_records = 0;
	unsigned int i = 0, j = 0;

	for (i = 0; i<NUM_HOURS; i++)
		cin >> cents_minute[i];
	cin >> N_records;
	Records *rec = new Records[N_records]{};
	char temp[20];
	for (i = 0; i<N_records; i++)
	{
		scanf("%s%d:%d:%d:%d%s", rec[i].name, &rec[i].month, &rec[i].day, &rec[i].hh, &rec[i].mm, temp);
		rec[i].on_line = (temp[1] == 'n');
	}
	sort(rec, rec + N_records, cmp);
	for (i = 0; i < N_records;)
	{
		bool flag = false;
		unsigned int total_pay = 0;
		for (j = i; i < N_records; i++)
		{
			for (; i < N_records && !strcmp(rec[i].name, rec[j].name) && !rec[i].on_line; i++);
			if (i >= N_records || strcmp(rec[i].name, rec[j].name))
				break;
			for (; i < N_records && !strcmp(rec[i].name, rec[j].name) && rec[i].on_line; i++);
			if (i >= N_records || strcmp(rec[i].name, rec[j].name))
				break;
			if (!flag)
			{
				flag = true;
				cout << rec[i].name << ' ';
				cout << setw(2) << setfill('0') << rec[i].month << endl;
			}
			cout << setw(2) << setfill('0') << rec[i - 1].day;
			cout << ':';
			cout << setw(2) << setfill('0') << rec[i - 1].hh;
			cout << ':';
			cout << setw(2) << setfill('0') << rec[i - 1].mm;
			cout << ' ';
			cout << setw(2) << setfill('0') << rec[i].day;
			cout << ':';
			cout << setw(2) << setfill('0') << rec[i].hh;
			cout << ':';
			cout << setw(2) << setfill('0') << rec[i].mm;
			cout << ' ';
			total_pay += CalcPay(rec[i-1],rec[i],cents_minute);
		}
		if (flag)
		{
			cout << "Total amount: $";
			cout << setiosflags(ios::fixed) << setprecision(2) << (float)total_pay / 100 << endl;
		}
	}
	return 0;
}