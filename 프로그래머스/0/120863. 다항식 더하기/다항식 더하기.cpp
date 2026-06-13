#include <bits/stdc++.h>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    
    int nx = 0;
    int m = 0;
    
    // Split.
    string temp = "";
    for(char c : polynomial)
    {
        if(c == 'x' || isdigit(c))
            temp += c;
        else
        {
            if(!temp.empty())
            {
                if(temp.find('x') != string::npos)
                {
                    cout << "check1: " << temp << '\n';
                    temp.pop_back();
                    nx += temp.length() > 0 ? stoi(temp) : 1;
                }
                else
                {
                    cout << "check2: " << stoi(temp) << '\n';
                    m += stoi(temp);
                }
            }
            
            temp = "";
        }
    }
    
    // Last Check.
    if(!temp.empty())
    {
        if(temp.find('x') != string::npos)
        {
            cout << "check1: " << temp << '\n';
            temp.pop_back();
            nx += temp.length() > 0 ? stoi(temp) : 1;
        }
        else
        {
            cout << "check2: " << stoi(temp) << '\n';
            m += stoi(temp);
        }
    }
    
    string nxStr = nx > 1 ? to_string(nx) + "x" : "x";
    if(nx > 0 && m > 0)
        answer = nxStr + " + " + to_string(m);
    else if(nx > 0)
        answer = nxStr;
    else
        answer = to_string(m);
    
    return answer;
}