#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    
    vector<int> delimeterPos;
    string delimeters = "abc";
    int prev = 0;
    for(int i = 0; i < myStr.length(); i++)
    {
        char c = myStr[i];
        if(delimeters.find(c) != string::npos)
        {
            int len = i - prev;
            if(len > 0)
            {
                answer.push_back(myStr.substr(prev, len));
            }
            
            prev = i+1;
        }
    }
    
    if(prev < myStr.length())
        answer.push_back(myStr.substr(prev));

    if(answer.empty())
        answer = {"EMPTY"};
    
    return answer;
}