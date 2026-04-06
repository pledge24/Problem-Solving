#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<pair<int, int>> v1;
    for(int i = 0; i < rank.size(); i++)
    {
        v1.push_back(make_pair(rank[i], i));
    }
    
    std::sort(v1.begin(), v1.end());
    
    vector<int> selected;
    int i = 0;
    while(selected.size() < 3)
    {
        auto p = v1[i];
        // cout << p.first << " " << p.second << '\n';
        if(attendance[p.second])
        {
            selected.push_back(p.second);            
        }
        
        i++;
    }
    
    answer = selected[0]*10000 + selected[1]*100 + selected[2];
    
    return answer;
}