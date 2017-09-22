#include<iostream>
using namespace std;
typedef unsigned char BYTE;

bool Judge(long long *data)
{
	if(data[0]+data[1]>data[2])
		return true;
	else
		return false;
}

int main()
{
	unsigned short int T = 0;
	long long data[3] = {0};
	BYTE i = 0;
	
	cin >> T;
	
	bool *result = new bool[T];
	
	for(i=0;i<T;i++)
	{
		cin >> data[0] >> data[1] >> data[2];
		result[i] = Judge(data);
	}
	for(i=0;i<T;i++)
	{
		switch(result[i])
		{
			case 0:
				cout << "Case #" << i+1 << ": false" << endl;
				break;
			case 1:
				cout << "Case #" << i+1 << ": true" << endl;
				break;
		}
	}
	delete [] result;
	return 0;
}


#include<vector>

int main()
{
	BYTE T = 0;
	long long data[3] = {0};
	BYTE i = 0;
	
	cin >> T;
	
	vector<bool> result;
	
	for(i=0;i<T;i++)
	{
		cin >> data[0] >> data[1] >> data[2];
		result.push_back(Judge(data));
	}
	for(i=0;i<T;i++)
	{
		switch(result[i])
		{
			case 0:
				cout << "Case #" << i+1 << ": false" << endl;
				break;
			case 1:
				cout << "Case #" << i+1 << ": true" << endl;
				break;
			default:
				break;
		}
	}
	return 0;
}