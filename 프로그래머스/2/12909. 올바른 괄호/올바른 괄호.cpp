#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> s1;
    for(char c : s)
    {
        if(s1.empty())
        {
            s1.push(c);
            continue;
        }
        
        char prev = s1.top();
        if(prev == '(' && c == ')')
        {
            s1.pop();
        }
        else
        {
            s1.push(c);
        }
    }
    
    answer = s1.empty();
    
    return answer;
}