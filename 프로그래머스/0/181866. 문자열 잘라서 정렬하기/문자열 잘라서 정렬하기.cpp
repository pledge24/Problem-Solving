#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    
    int pos = 0;
    while(pos < myString.length())
    {
        int next = myString.find("x", pos);
        if(next == string::npos)
        {
            next = myString.length();
        }
        
        int len = next - pos;
        if(len > 0)
            answer.push_back(myString.substr(pos, len));
        
        pos = next+1;
    }
    
    std::sort(answer.begin(), answer.end());
    
    return answer;
}