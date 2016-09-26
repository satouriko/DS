#include "stack.h"
#include "applications.h"

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
    cout << isRightBrackets("(define (factorial_rec n)\
        (if (= n 1)\
            1\
            (* n (factorial_rec (- n 1)))))\
        (define (factorial_itr n)\
        (define (fact-iter product counter max-count)\
        (if (> counter max-count)\
            product\
            (fact-iter (* product counter)\
                        (+ counter 1)\
                        max-count)))\
        (fact-iter 1 1 n))\
        \
        (factorial_rec 2645)\
        (factorial_itr 2645)") << endl;
    cout << isRightPermutation("1234","4312") << endl;
    cout << solve_infix<int>("3+2*4-1") << endl;
    return 0;
}
