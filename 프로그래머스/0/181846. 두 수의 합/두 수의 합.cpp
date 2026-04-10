#include <bits/stdc++.h>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    
    if(a.length() < b.length())
    {
        a.swap(b);
    }

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    
    int carry = 0;
    for(int i = 0; i < a.length(); i++)
    {
        int num1 = a[i] - '0';
        int num2 = i < b.length() ? b[i] - '0' : 0;
        
        answer += (num1 + num2 + carry) % 10 + '0';
        carry = (num1 + num2 + carry) / 10;
    }
    
    if(carry > 0)
        answer += '1';
    
    std::reverse(answer.begin(), answer.end());
    
    return answer;
}