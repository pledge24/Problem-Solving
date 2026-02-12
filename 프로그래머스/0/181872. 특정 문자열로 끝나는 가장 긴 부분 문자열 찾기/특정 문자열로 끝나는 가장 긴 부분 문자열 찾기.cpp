#include <bits/stdc++.h>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    int pos = 0;
    while(true)
    {
        int next = myString.find(pat, pos);
        if(next == string::npos)
        {
            break;
        }
        
        pos = next + pat.length();
    }
    
    answer = myString.substr(0, pos);
    
    return answer;
}