#include<iostream>
#include<string>
using namespace std;

char base[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

string ConvertRadix(unsigned int N)
{
	string result;
	unsigned int i = 0;
	for(i=0;i<2;i++)
	{
		result.insert(0,1,base[N%13]);
		N /= 13;
	}
	return result;
}

int main(int argc, char *argv[])
{
	unsigned int R_value = 0, G_value = 0, B_value = 0;
	string R, G, B;
	cin >> R_value >> G_value >> B_value;
	R = ConvertRadix(R_value);
	G = ConvertRadix(G_value);
	B = ConvertRadix(B_value);
	cout << '#' << R << G << B << endl;
	return 0;
}