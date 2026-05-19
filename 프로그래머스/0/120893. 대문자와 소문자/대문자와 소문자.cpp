#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(char c : my_string)
    {
        answer += islower(c) ? toupper(c) : tolower(c);
    }
    
    return answer;
}