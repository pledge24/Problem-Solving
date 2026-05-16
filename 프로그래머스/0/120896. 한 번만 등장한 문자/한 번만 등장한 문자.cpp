#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    map<char, int> m1;
    for(char c : s)
    {
        m1[c]++;
    }
    
    for(char c = 'a'; c <= 'z'; c++)
    {
        if(m1[c] == 1)
            answer += c;
    }
    
    return answer;
}