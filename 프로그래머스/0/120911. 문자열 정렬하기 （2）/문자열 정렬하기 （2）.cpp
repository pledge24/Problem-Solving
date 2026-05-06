#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(char c : my_string)
    {
        answer += tolower(c);
    }
    
    std::sort(answer.begin(), answer.end());
    
    return answer;
}