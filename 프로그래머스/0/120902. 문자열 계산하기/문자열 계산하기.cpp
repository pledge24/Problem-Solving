#include <bits/stdc++.h>

using namespace std;

void Split(string str, vector<string>& splitted)
{
    int pos = 0;
    while(pos < str.length())
    {
        int nextDelimeterPos = str.find(" ", pos);
        if(nextDelimeterPos == string::npos)
            nextDelimeterPos = str.length();
        
        int len = nextDelimeterPos - pos;
        if(len > 0)
        {
            splitted.push_back(str.substr(pos, len));
        }
        
        pos = nextDelimeterPos + 1;
    }
}

int solution(string my_string) {
    int answer = 0;
    
    vector<string> splitted;
    Split(my_string, splitted);
    
    bool isPlus = true;
    for(string str : splitted)
    {
        if(str.find("+") != string::npos)
            continue;
        
        if(str.find("-") != string::npos && str.length() == 1)
        {
            isPlus = !isPlus;
            continue;
        }
        
        answer += isPlus ? stoi(str) : -stoi(str);
        isPlus = true;
    }
    
    return answer;
}