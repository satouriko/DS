#include "list.h"
#include <iostream>

using namespace std;

int main()
{
    int array1[] = { 1, 6, 5, 3, 7, 5 };
    list<int> l1(array1, array1 + 6);
    cout << l1 << endl;
    l1.selectionSort();
    cout << l1 << endl;
    l1.deduplicate();
    cout << l1 << endl;
    return 0;
}
