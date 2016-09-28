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
    if(a == EOF || a == '(' || a == ')')
        return 0;
    else if(a == '+' || a == '-')
        return 1;
    else if(a == '*' || a == '/')
        return 2;
    else if(a == '^')
        return 3;
    else if(a == '.')
        return 4;
    else {
        cerr << "Undefined operator: " << a << endl;
        return -1;
    }
}

int otorandnum(char a)
{
    if(a == EOF || a == '(' || a == ')' || a == '.')
        return 0;
    else if(a == '!')
        return 1;
    else if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
        return 2;
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
    bool isReadingDits = false;
    bool isBeginning = true;
    int decidits = 0;
    expression.push_back(EOF);
    for(string::iterator iter = expression.begin(); iter != expression.end(); ++iter) {
        if(isdigit(*iter)) {
            isBeginning = false;
            int a = *iter - '0';
            if(otor.top() == '.') {
                ++decidits;
                oand.push(oand.pop() + a / pow(10,decidits));
            }
            else if(isReadingDits) {
                oand.push(oand.pop() * 10 + a);
            }
            else {
                oand.push(a);
                isReadingDits = true;
            }
        }
        else if(otorpri(*iter) >= 0) {
            isReadingDits = false;
            if(isBeginning) {
                oand.push(0);
                isBeginning = false;
            }
            if(*iter == '(')
                isBeginning = true;
            else while(otor.size() != 0 && otorpri(*iter) <= otorpri(otor.top())) {
                char o = otor.pop();
                if(otorandnum(o) == 2) {
                    T r = oand.pop();
                    T l = oand.pop();
                    oand.push(solve(o,l,r)); 
                }
            }
            if(otor.top() == '.')
                otor.pop();
            if(*iter == '.') {
                decidits = 0;
            }
            if(*iter != ')' && *iter != EOF)
                otor.push(*iter);
        }
    }
    return oand.top();
}

// 前缀表达式 
template <typename T>
T solve_prefix(string expression)
{
    
}

