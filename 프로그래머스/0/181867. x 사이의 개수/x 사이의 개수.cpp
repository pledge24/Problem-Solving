#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    int pos = 0;
    while(pos < myString.length())
    {
        int next = myString.find("x", pos);
        if(next == string::npos)
        {
            next = myString.length();
        }
        
        answer.push_back(next - pos);
        pos = next + 1;
    }
    if(myString.back() == 'x')
        answer.push_back(0);
    
    return answer;
}