#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    int maxlen = 0;
    int len = 0;
    int currlen = 0;
    
    stack<int> st;
    st.push(-1);
        
    while(currlen < s.length())
    {
        if(s[currlen] == '(' )
        {
            st.push(currlen);
        }
        else
        {
            if(st.empty())
            {
                st.push(currlen);
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    int topelem = st.top();
                    len = currlen - topelem;
                    if(maxlen < len)
                    {
                        maxlen = len;
                    }
                }
                else
                {
                    st.push(currlen);
                }
            }
        }
        currlen++;
    }
        
    return maxlen;
}
