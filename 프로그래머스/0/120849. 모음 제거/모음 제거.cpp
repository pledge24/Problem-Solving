#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    string ban = "aeiou";
    for(const char c : my_string)
    {
        if(ban.find(c) == string::npos)
            answer += c;
    }
    
    return answer;
}