#include <bits/stdc++.h>

using namespace std;

// 알파벳 소문자 구성 문자열
// 같은 알파벳 2개가 붙어있으면 제거 -> 남은 문자열 병합
// 전부 다 제거 가능한지 체크
int solution(string s)
{
    int answer = -1;
    stack<char> s1;
    for(char c : s)
    {
        if(s1.empty())
        {
            s1.push(c);
            continue;
        }
        
        char prev = s1.top();
        if(prev == c)
        {
            s1.pop();
        }
        else
            s1.push(c);
            
    }
    
    answer = s1.empty();
    
    return answer;
}