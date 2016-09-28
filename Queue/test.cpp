#include "queue.h"

using namespace std;

int main()
{
    queue<int> que;
    que.enqueue(2);
    que.enqueue(6);
    que.enqueue(4);
    que.enqueue(5);
    cout << que << endl;
    for(int i = 0; i < 4; ++i) {
        cout << que.front() << endl;
        que.dequeue();
        cout << que << endl;
    }
    return 0;
}
