#include <iostream>
#include <cstring>

using namespace std;

int lcs(char a[], char b[], int am, int bm);

//The max length of the input string
#define MAX 256

int main()
{
	char a[MAX], b[MAX];
	//am, bm: The length of the input string
	int am, bm;
	cout << "Please input the length of a:" << endl;
	cin >> am;
	cout << "Please input a:" << endl;
	cin	>> a;
	cout << "Please input the length of b:" << endl;
	cin >> bm;
	cout << "Please input b:" << endl;
	cin >> b;
	cout << "LCS:" << lcs(a, b, am, bm) << endl;
	return 0;
}

///<summary>
///a dp function caculating lcs
///</summary>
///<param name="a">input string</param>
///<param name="b">input string</param>
///<param name="am">the length of a</param>
///<param name="bm">the length of b</param>
///<returns>returns the lcs result of a and b</returns>
int lcs(char a[], char b[], int am, int bm)
{
	int lcsmap[am+1][bm+1];
	memset(lcsmap,0,sizeof(lcsmap));
	for(int i = 1; i < am+1; ++i)
	{
		for(int j = 1; j < bm+1; ++j)
		{
			if(a[i-1] == b[j-1])
				lcsmap[i][j] = lcsmap[i-1][j-1] + 1;
			else
				lcsmap[i][j] = lcsmap[i-1][j] > lcsmap[i][j-1] ?
					lcsmap[i-1][j] : lcsmap[i][j-1];
		}
	}
	return lcsmap[am][bm];
}
