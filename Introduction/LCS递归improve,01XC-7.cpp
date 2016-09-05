#include <iostream>
#include <cstring>

using namespace std;

int lcs(char a[], char b[], int ap, int bp);

//lcsmap[ap,bp] shows lcs(a, b, ap, bp)
int lcsmap[256][256];

int main()
{
	char a[256], b[256];
	memset(lcsmap,-1,sizeof(lcsmap));
	int am, bm;
	cout << "Please input the length of a:" << endl;
	cin >> am;
	cout << "Please input a:" << endl;
	cin	>> a;
	cout << "Please input the length of b:" << endl;
	cin >> bm;
	cout << "Please input b:" << endl;
	cin >> b;
	cout << "LCS:" << lcs(a, b, am-1, bm-1) << endl;
	return 0;
}

///<summary>
///a recuration function caculating lcs
///</summary>
///<param name="a">input string</param>
///<param name="b">input string</param>
///<param name="ap">the position of a on process</param>
///<param name="bp">the position of b on process</param>
///<returns>returns the lcs result of a[0,ap] and b[0,bp]</returns>
int lcs(char a[], char b[], int ap, int bp)
{
	if(ap < 0 || bp < 0)
		return 0;
	if(lcsmap[ap][bp] >= 0)
		return lcsmap[ap][bp];
	if(a[ap] == b[bp]) {
		lcsmap[ap][bp] = lcs(a, b, ap-1, bp-1) + 1;
		return lcsmap[ap][bp];
	}
	else {
		lcsmap[ap][bp] = lcs(a, b, ap-1, bp) > lcs(a, b, ap, bp-1) ?
			   lcs(a, b, ap-1, bp) : lcs(a, b, ap, bp-1);
		return lcsmap[ap][bp];
	}
}
