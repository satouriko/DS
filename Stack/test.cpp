#include "stack.h"

using namespace std;

int main()
{
    stack<int> stk;
    stk.push(2);
    stk.push(6);
    stk.push(4);
    stk.push(5);
    cout << stk << endl;
    for(int i = 0; i < 4; ++i) {
        cout << stk.top() << endl;
        stk.pop();
        cout << stk << endl;
    }
    return 0;
}
