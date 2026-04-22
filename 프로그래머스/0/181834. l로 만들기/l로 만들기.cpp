#include <bits/stdc++.h>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(char c : myString)
    {
        answer += max(c, 'l');
    }
    
    return answer;
}