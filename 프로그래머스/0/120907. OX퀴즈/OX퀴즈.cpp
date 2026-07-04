#include <bits/stdc++.h>

using namespace std;

void Split(string expr, vector<string>& splitted)
{
    int pos = 0;
    while(pos < expr.length())
    {
        int nextDelimeterPos = expr.find(' ', pos);
        if(nextDelimeterPos == string::npos)
            nextDelimeterPos = expr.length();
        
        int len = nextDelimeterPos - pos;
        if(len > 0)
        {
            splitted.push_back(expr.substr(pos, len));
            cout << expr.substr(pos, len) << " ][ ";
            pos = nextDelimeterPos + 1;
        }
    }
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(string& expr : quiz)
    {
        vector<string> splitted;
        Split(expr, splitted);
        
        int lhs = 0;
        bool isPlus = true;
        for(string str : splitted)
        {
            if(str[0] == '=')
                break;
            
            if(isdigit(str[0]))
            {
                lhs += isPlus ? stoi(str) : -stoi(str);
                isPlus = true;
            }
            else if(str[0] == '-')
            {
                string temp = str.substr(1);
                isPlus = !isPlus;
                
                if(temp.length() > 0)
                {
                    lhs += isPlus ? stoi(temp) : -stoi(temp);
                    isPlus = true;
                }
            }
        }
        
        int rhs = 0;
        string rhsStr = splitted.back();
        if(rhsStr[0] == '-')
        {
            rhs = -stoi(rhsStr.substr(1));
        }
        else
        {
            rhs = stoi(rhsStr);
        }
        
        string res = lhs == rhs ? "O" : "X";
        answer.push_back(res);
    }
    
    return answer;
}