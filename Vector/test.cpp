#include <iostream>
#include "Vector.h"
using namespace std;

int main() {

	vector<int> t1;
	int array[] = { 1, 2, 3, 4 };
	vector<int> t2(array, array + 4);
	vector<int> t3(t2);

	cout << "size:" << t3.size() << endl;
	t2.push(2645);
	cout << "size:" << t2.size() << endl;
	cout << t2.get(4) << endl;
	t3.insert(1, 2222);
	t3.put(2, 155);
	cout << t3.get(1) << '\t' << t3.get(2) << '\t' << t3.get(4) << endl;
	cout << t3.get(5);

	return 0;
}
