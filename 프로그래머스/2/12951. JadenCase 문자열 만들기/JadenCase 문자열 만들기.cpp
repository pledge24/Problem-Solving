#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.length(); i++){
        if(i == 0 || i-1 > 0 && s[i-1] == ' '){
            s[i] = toupper(s[i]);
        }
        else{
            s[i] = tolower(s[i]);
        }
    }
    
    answer = s;
    
    return answer;
}