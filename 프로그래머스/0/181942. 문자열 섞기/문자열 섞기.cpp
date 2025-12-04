#include <bits/stdc++.h>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int maxLen = max(str1.length(), str2.length());
    for(int i = 0; i < maxLen; i++){
        if(i < str1.length())
            answer += str1[i];
        
        if(i < str2.length())
            answer += str2[i];
    }
    
    return answer;
}