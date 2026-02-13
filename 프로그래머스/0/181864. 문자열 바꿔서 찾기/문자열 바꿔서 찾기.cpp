#include <bits/stdc++.h>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    string temp = "";
    for(char c : myString)
    {
        temp += c == 'A' ? 'B' : 'A';
    }
    
    answer = temp.find(pat) != string::npos;
    
    return answer;
}