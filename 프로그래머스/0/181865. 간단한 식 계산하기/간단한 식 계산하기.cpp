#include <bits/stdc++.h>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    
    vector<string> splitted;
    int pos = 0;
    while(pos < binomial.length())
    {
        int next = binomial.find(" ", pos);
        if(next == string::npos)
        {
            next = binomial.length();
        }
        
        int len = next - pos;
        splitted.push_back(binomial.substr(pos, len));
        
        pos = next + 1;
    }
    
    int num1 = stoi(splitted[0]);
    char op = splitted[1][0];
    int num2 = stoi(splitted[2]);
    
    if(op == '+')
        answer = num1 + num2;
    else if(op == '-')
        answer = num1 - num2;
    else if(op == '*')
        answer = num1 * num2;
    
    return answer;
}