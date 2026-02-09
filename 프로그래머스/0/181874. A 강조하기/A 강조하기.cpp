#include <bits/stdc++.h>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(char c : myString)
    {
        c = tolower(c);
        if(c == 'a')
            c = toupper(c);
        
        answer += c;
    }
    
    return answer;
}