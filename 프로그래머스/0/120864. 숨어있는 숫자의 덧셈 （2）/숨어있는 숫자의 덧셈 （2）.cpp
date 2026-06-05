#include <bits/stdc++.h>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    string temp = "";
    for(char c : my_string)
    {
        if(isdigit(c))
            temp += c;
        else
        {
            if(temp.length() > 0)
            {
                answer += stoi(temp);
                temp = "";
            }
        }
    }
    
    if(temp.length() > 0)
    {
        answer += stoi(temp);
        temp = "";
    }
    
    return answer;
}