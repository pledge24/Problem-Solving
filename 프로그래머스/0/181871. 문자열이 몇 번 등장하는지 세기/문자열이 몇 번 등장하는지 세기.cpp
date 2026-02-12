#include <bits/stdc++.h>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for(int i = 0; i < myString.length() - pat.length() + 1; i++)
    {
        string temp = myString.substr(i, pat.length());
        // cout << temp << ' ';
        if(temp == pat)
            answer++;
    }
    
    return answer;
}