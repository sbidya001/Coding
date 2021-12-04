#include<bits/stdc++.h>
using namespace std;

bool isBalancedParentheses(string exp)
{
    stack<char> st;
    bool result = false;
    
    int len = exp.length();
    int currlen = 0;
    while(currlen < len)
    {
        if(st.empty() && isOpenPar(exp[currlen]))
        {
            st.push(exp[currlen]);
        }
        else if (st.empty()  && !isOpenPar(exp[currlen]))
        {
            return false;
        }
        else if(!st.empty() && !isOpenPar(exp[currlen]))
        {
            if(exp[currlen] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if(exp[currlen] == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if(exp[currlen] == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            st.push(exp[currlen]);
        }
        currlen++;
    }
    if(st.empty())
    {
        return true;
    }
    return false;
}