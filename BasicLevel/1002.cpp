#include<iostream>
#include<iomanip>
using namespace std;
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
	unsigned short int count = 0;
	int i = 0;
	unsigned short int data = 0;
	int A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
	int temp = 0;
	BYTE flag = 0;
	unsigned short int A2_count = 0, A4_count = 0;
	cin >> count;
	while(i<count)
	{
		cin >> data;
		temp = data % 5;
		switch(temp)
		{
		case 0:
			if(data%2==0)
			{
				A1 += data;
			}
			break;
		case 1:
			A2_count++;
			if(A2_count%2==1)
			{
				A2 += data;
				flag = 1;
			}
			else
			{
				A2 -= data;
				flag = 1;
			}
			break;
		case 2:
			A3++;
			break;
		case 3:
			A4 += data;
			A4_count++;
			break;
		case 4:
			if(data>A5)
			{	
				A5 = data;
			}
			break;
		}
		i++;
	}
	if(A1==0)
		cout << "N ";
	else
		cout << A1 << " ";
	if(!flag)
		cout << "N ";
	else
		cout << A2 << " ";
	if(A3==0)
		cout << "N ";
	else
		cout << A3 << " ";
	if(A4_count==0)
		cout << "N ";
	else
	{
		cout << setiosflags(ios::fixed);  //只有在这项设置后，setprecision才是设置小数的位数
		cout << setprecision(1) << (double)A4/A4_count << " ";
	}
	if(A5==0)
		cout << "N";
	else
		cout << A5;
	return 0;
}