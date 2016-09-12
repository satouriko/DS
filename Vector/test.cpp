#include <iostream>
#include "Vector.h"
using namespace std;

int main() {

	vector<int> t1;
	int array[] = { 1, 2, 3, 4 };
	vector<int> t2(array, array + 4);
	//vector<int> t3(t2);
	string t3 = "";

	cout << t1 << '\n' << t2 << '\n' << t3 << endl;
	cout << "size:" << t3.size() << '\n' << endl;

	t2.push(2645);
	cout << "size:" << t2.size() << endl;
	cout << t1 << '\n' << t2 << '\n' << t3 << endl;

	t2.insert(1, 2222);
	t2.put(2, 155);
	cout << t1 << '\n' << t2 << '\n' << t3 << endl;
	cout << t2.get(5) << endl;

	int a = t2.find(2222);
	int b = t2.find(2143);
	cout << a << '\t' << b << endl;

	t2.destroy(a);
	cout << t2 << endl;

	int array4[] = {1111, 1111, 1111, 1111};
	vector<int> t4(array4, array4 + 4);
	t4.deduplicate();
	cout << t4 << endl;

	cout << "-----------华丽的分割线-----------" << endl;

	int array10[] = { 5, 6, 6, 6, 4, 3, 9, 1, 1, 2 };
	vector<int> t10(array10, array10 + 10);
	cout << t10 << endl;
	t10.bubbleSortB1();
	cout << t10 << endl;
	cout << t10.search(10) << endl;
	t10.uniquify();
	cout << t10 << endl;

	return 0;
}
