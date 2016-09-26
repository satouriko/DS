#include "stack.h"
#include <string>
#include <cmath>

using namespace std;

// 括号匹配
bool isRightBrackets(string str)
{
    stack<int> stk;
    for(string::iterator iter = str.begin(); iter != str.end(); ++iter) {
            if(*iter == '(')
                stk.push(iter - str.begin());
            else if(*iter == ')') {
                if(stk.size() != 0)
                    stk.pop();
                else
                    return false;
            }
    }
    if(stk.size() != 0)
        return false;
    return true;
}

// 栈混洗
bool isRightPermutation(string ori, string sam)
{
    stack<int> stk;
    for(string::iterator ori_it = ori.begin(), sam_it = sam.begin(); sam_it != sam.end();) {
        if(*sam_it == stk.top()) {
            ++sam_it;
            stk.pop();
        }
        else if(ori_it != ori.end()) {
            stk.push(*ori_it);
            ++ori_it;
        }
        else
            return false;
    }
    return true;
}

int otorpri(char a)
{
    if(a == EOF)
        return 0;
    else if(a == '+' || a == '-')
        return 1;
    else if(a == '*' || a == '/')
        return 2;
    else if(a == '^')
        return 3;
    else if(a == '(' || a == ')')
        return 4;
    else {
        cerr << "Undefined operator: " << a << endl;
        return -1;
    }
        
}

template <typename T>
T solve(char otor, T l, T r)
{
    if(otor == '+')
        return l + r;
    else if(otor == '-')
        return l - r;
    else if(otor == '*')
        return l * r;
    else if(otor == '/')
        return l / r;
    else if(otor == '^')
        return pow(l, r);
    else {
        cerr << "Undefined operator: " << otor << '\n' << "With operand: " << l << ' ' << r << endl;
        return -1;
    }
}

// 中缀表达式
template <typename T>
T solve_infix(string expression)
{
    stack<char> otor;
    stack<T> oand;
    bool flag = false;
    if(!isdigit(expression[0]))
        oand.push(0);
    expression.push_back(EOF);
    for(string::iterator iter = expression.begin(); iter != expression.end(); ++iter) {
        if(isdigit(*iter)) {
            int a = *iter - '0';
            if(flag) {
                oand.push(oand.pop() * 10 + a);
            }
            else {
                oand.push(a);
                flag = true;
            }
        }
        else if(otorpri(*iter) >= 0) {
            flag = false;
            while(otor.size() != 0 && otorpri(*iter) <= otorpri(otor.top())) {
                char o = otor.pop();
                T r = oand.pop();
                T l = oand.pop();
                oand.push(solve(o,l,r)); 
            }
            otor.push(*iter);
        }
        //cout << "otor:\t" << otor << endl;
        //cout << "oand:\t" << oand << endl;
    }
    return oand.top();
}

// 逆波兰表达式 
template <typename T>
T solve_prefix(string expression)
{

}

