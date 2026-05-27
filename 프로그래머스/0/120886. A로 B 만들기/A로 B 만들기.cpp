#include <bits/stdc++.h>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    
    map<char, int> s1;
    map<char, int> s2;
    
    for(char c : before)
    {
        s1[c]++;
    }
    
    for(char c : after)
    {
        s2[c]++;
    }
    
    answer = s1 == s2;
    
    return answer;
}