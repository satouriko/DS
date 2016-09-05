#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main()
{
	srand(time(0));
	int num, numold;
	cout<<"Please input a num:";
	cin>>num;
	numold = num;
	string s;
	while(num--)
		s += (char)(rand() % '0' + 'z' - '0' + 1);
	cout<<"#### The original string:"<<endl;
	cout<<s<<endl;
	int cnt = rand() % numold;
	string subs;
	int n = 0;
	while(cnt--)
	{
		if(n >= s.length())
			break;
		else
		{
			//cout<<"n:"<<n<<endl;
			subs += s[n];
			int rnd = rand() % 10;
			n += (rnd == 0 ? 1 : rnd);
		}
	}
	cout<<"#### Substring:"<<endl;
	cout<<subs<<endl;
	cout<<"#### The length of substr:"<<subs.length()<<endl;
	return 0;
}
