#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    
    int idx = 0;
    while(true)
    {
        int pos = idx*m + c-1;
        if(pos >= my_string.length())
            break;
        
        answer += my_string[pos];
        idx++;
    }
    
    return answer;
}