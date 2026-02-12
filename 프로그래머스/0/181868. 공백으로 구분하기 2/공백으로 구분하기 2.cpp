#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    int pos = 0;
    while(pos < my_string.length())
    {
        int next = my_string.find(" ", pos);
        if(next == string::npos)
        {
            next = my_string.length();
        }
        
        int len = next - pos;
        if(len > 0)
            answer.push_back(my_string.substr(pos, len));
        
        pos = next + 1;
    }
    
    return answer;
}