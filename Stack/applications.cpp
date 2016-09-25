#include "stack.h"
#include <string>

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

// 中缀表达式
template <typename T>
T solve_infix(string expression)
{
    
}

// 逆波兰表达式 
template <typename T>
T solve_prefix(string expression)
{

}

