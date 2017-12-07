#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int M = 0, N = 0, S = 0;
	unsigned int i = 0;
	cin >> M >> N >> S;
	if (S>M)
	{
		cout << "Keep going..." << endl;
		return 0;
	}
	string *names = new string[M];
	set<string> winner;
	unsigned int indice_winner = S - 1;
	for (i = 0; i<M; i++)
	{
		cin >> names[i];
		if (i == indice_winner)
		{
			if (winner.find(names[i]) == winner.end())
			{
				winner.insert(names[i]);
				cout << names[i] << endl;
				indice_winner += N;
			}
			else
				indice_winner++;
		}
	}
	delete[] names;
	return 0;
}