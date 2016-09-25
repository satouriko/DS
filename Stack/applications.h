#ifndef DS_STACK_APPLICATIONS_H
#define DS_STACK_APPLICATIONS_H

#include <string>

bool isRightBrackets(string str);
bool isRightPermutation(string ori, string sam);
template <typename T>
T solve_infix(string expression);
template <typename T>
T solve_prefix(string expression);

#endif
