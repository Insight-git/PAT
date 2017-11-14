#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	double data;
	vector<unsigned int> index;
	vector<double> odd;
	unsigned int i = 0, j = 0;
	double result = 0;
	for(i=0;i<3;i++)
	{
		double max_data = 0;
		unsigned int max_index = 0;
		for(j=0;j<3;j++)
		{
			cin >> data;
			if(data>max_data)
			{
				max_data = data;
				max_index = j;
			}
		}
		index.push_back(max_index);
		odd.push_back(max_data);
	}
	result = (odd[0] * odd [1] * odd[2] * 0.65 - 1) * 2;
	cout << index[0] << ' ' << index[1] << ' ' << index[2] << ' ' << result <<endl;
	return 0;
}