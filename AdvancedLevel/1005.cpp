#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string integer;
	unsigned int n = 0, sum = 0;
	vector<int> digit;
	cin >> integer;
	for(n=0;n<integer.size();n++)
	{
		sum += integer[n] - '0';
	}
	//cout << sum << endl;
	n = sum;
	do
	{
		digit.push_back(n%10);
		n = n / 10;
	}while(n);
	for(auto it=digit.rbegin();it!=digit.rend();it++)
	{
		switch(*it)
		{
			case 1:
				if(it==digit.rend()-1)
					cout << "one";
				else
					cout << "one ";
				break;
			case 2:
				if(it==digit.rend()-1)
					cout << "two";
				else
					cout << "two ";
				break;
			case 3:
				if(it==digit.rend()-1)
					cout << "three";
				else
					cout << "three ";
				break;
			case 4:
				if(it==digit.rend()-1)
					cout << "four";
				else
					cout << "four ";
				break;
			case 5:
				if(it==digit.rend()-1)
					cout << "five";
				else
					cout << "five ";
				break;
			case 6:
				if(it==digit.rend()-1)
					cout << "six";
				else
					cout << "six ";
				break;
			case 7:
				if(it==digit.rend()-1)
					cout << "seven";
				else
					cout << "seven ";
				break;
			case 8:
				if(it==digit.rend()-1)
					cout << "eight";
				else
					cout << "eight ";
				break;
			case 9:
				if(it==digit.rend()-1)
					cout << "nine";
				else
					cout << "nine ";
				break;
			case 0:
				if(it==digit.rend()-1)
					cout << "zero";
				else
					cout << "zero ";
				break;
			default:
				break;
		}
	}
	return 0;
}