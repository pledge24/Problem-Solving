#include <bits/stdc++.h>

using namespace std;

void Split(string& s, vector<string>& splitted)
{
    int pos = 0;
    while(pos < s.length())
    {
        int nextDelimeterPos = s.find(' ', pos);
        if(nextDelimeterPos == string::npos)
            nextDelimeterPos = s.length();
        
        int len = nextDelimeterPos - pos;
        if(len > 0)
        {
            splitted.push_back(s.substr(pos, len));
        }
        
        pos = nextDelimeterPos + 1;
    }
}

int solution(string s) {
    int answer = 0;
    
    vector<string> splitted;
    Split(s, splitted);
    
    int prevNum = 0;
    for(string s : splitted)
    {
        if(s == "Z")
            answer -= prevNum;
        else
        {
            int num = stoi(s);
            answer += num;
            prevNum = num;
        }
    }
    
    return answer;
}