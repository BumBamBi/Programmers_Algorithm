#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.size() > 0)
            {
                st.pop();
            }
            else{
                answer = false;
                break;
            }
        }
    }
    
    if(st.size() != 0)
    {
        answer = false;
    }
    
    
    return answer;
}