#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    set<pair<int, int>> s1;
    for(int i = 0; i < operations.size(); i++)
    {
        string& op = operations[i];
        char o1 = op[0];
        int num = stoi(op.substr(2));
        
        if(o1 == 'I')
        {
            s1.insert(make_pair(num, i));
        }
        else if(o1 == 'D')
        {
            if(!s1.empty())
            { 
                auto it = num < 0 ? s1.begin() : --s1.end();
                s1.erase(it);
            }
        }
        
    }
    
    answer = s1.empty() ? vector{0, 0} : vector{(--s1.end())->first, s1.begin()->first};
    
    return answer;
}