#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int K = 0, N = 0;
	unsigned int i = 0, j = 0, x = 0, y = 0;
	unsigned int temp = 0;
	vector<unsigned int> queens;
	cin >> K;
	for (i = 0; i<K; i++)
	{
		cin >> N;
		queens.clear();
		bool flag = false;
		for (j = 0; j<N; j++)
		{
			cin >> temp;
			queens.push_back(temp);
		}
		for (x = 1; x <= N - 1 && !flag; x++)
		{
			for (y = x + 1; y <= N; y++)
			{
				if (queens[x - 1] == queens[y - 1])
				{
					cout << "NO" << endl;
					flag = true;
					break;
				}
				if (abs((int)queens[x - 1] - (int)queens[y - 1]) == (y - x))
				{
					cout << "NO" << endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag)
			cout << "YES" << endl;
	}
	return 0;
}

/*solution 2*/
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int K = 0, N = 0;
	unsigned int i = 0, j = 0;
	cin >> K;
	for (i = 0; i<K; i++)
	{
		cin >> N;
		unsigned int *queens = new unsigned int[N] {};
		bool **occupied = new bool* [3];
		bool flag = false;
		for(j=0;j<3;j++)
			occupied[j] = new bool[2*N] {};
		for (j = 0; j<N; j++)
		{
			cin >> queens[j];
			if(occupied[0][queens[j]]||occupied[1][N-queens[j]+j+1]||occupied[2][queens[j]+j])
				flag = true;
			occupied[0][queens[j]] = true;
			occupied[1][N-queens[j]+j+1] = true;
			occupied[2][queens[j]+j] = true;
		}
		if(flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		delete [] queens;
		for(j=0;j<3;j++)
			delete [] occupied[j];
		delete [] occupied;
	}
	return 0;
}