#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = -1;
    
    // Init
    set<char> s;
    for(char c : skill)
        s.insert(c);
    
    int cnt = 0;
    for(const string& skillStr : skill_trees)
    {
        int idx = 0;
        bool valid = true;
        
        // Process
        for(char c : skillStr)
        {
            if(s.find(c) == s.end())
                continue;
            
            char nextSkill = skill[idx];
            if(c != nextSkill)
            {
                valid = false;
                break;
            }
            else
            {
                idx++;
                if(idx == skill.length())
                    break;
            }
            
        }
        
        if(valid)
            cnt++;
    }
    
    // cout << cnt << '\n';
    
    answer = cnt;
     
    return answer;
}