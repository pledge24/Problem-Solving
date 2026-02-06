#include <bits/stdc++.h>

using namespace std;

string Normalize(const string& s)
{
    string res = "";
    for(char c : s)
    {
        res += tolower(c);
    }
    
    return res;
}

int solution(string myString, string pat) {
    int answer = 0;
    
    string s1 = Normalize(myString);
    string s2 = Normalize(pat);
    
    answer = s1.find(s2) != string::npos;
    
    return answer;
}