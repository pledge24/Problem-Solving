#include <bits/stdc++.h>

using namespace std;

vector<char> digitList = 
{
'0', '1', '2', '3', '4', 
'5', '6', '7', '8', '9',    
'A', 'B', 'C', 'D', 'E', 'F'
};

string ToStr(int num, int n)
{
    string res = "";
    do
    {
        res += digitList[num % n];
        num /= n;
    }
    while(num > 0);
        
    std::reverse(res.begin(), res.end());
    
    return res;
}
// 
string solution(int n, int t, int m, int p) {
    string answer = "";
    int maxLen = t*m;
    string str = "";
    int num = 0;
    
    while(str.length() < maxLen)
    {
        str += ToStr(num, n);
        num++;
    }
    
    // Process
    for(int i = 0; i < t; i++)
    {
        int idx = i*m + (p-1);
        answer += str[idx];
    }
    
    // cout << str << '\n';
    
    return answer;
}