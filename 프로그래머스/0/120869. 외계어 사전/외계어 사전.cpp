#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    
    for(const string& d : dic)
    {
        bool verified = true;
        
        for(string c : spell)
        {
            if(std::count(d.begin(), d.end(), c[0]) != 1)
            {
                verified = false;
                break;
            }
        }
            
        if(!verified)
            continue;
        
        answer = 1;
        break;
    }
    
    return answer;
}