#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    vector<pair<int, int>> v1;
    for(int i = 0; i < emergency.size(); i++)
    {
        v1.push_back(make_pair(emergency[i], i));
    }
    
    std::sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    
    answer.resize(emergency.size());
    for(int i = 0; i < v1.size(); i++)
    {
        auto p = v1[i];
        answer[p.second] = i+1;
    }
    
    return answer;
}