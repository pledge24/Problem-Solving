#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for(string& str : strArr)
    {
       if(str.find("ad") == string::npos)
           answer.push_back(str);
    }
    
    return answer;
}