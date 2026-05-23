#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    set<char> s1;
    for(char c : my_string)
    {
        if(s1.find(c) == s1.end())
        {
            answer += c;
            s1.insert(c);
        }
    }
    
    return answer;
}