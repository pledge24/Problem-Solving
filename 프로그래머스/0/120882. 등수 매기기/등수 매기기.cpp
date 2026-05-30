#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    vector<pair<int, int>> v1;
    for(int i = 0; i < score.size(); i++)
    {
        const vector<int>& elem = score[i];
        v1.push_back({elem[0] + elem[1], i});
    }
    
    std::sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    
    answer.resize(v1.size());
    int rank = 1;
    int prevScore = -1;
    for(int i = 0; i < v1.size(); i++)
    {
        auto p = v1[i];

        rank = p.first == prevScore ? rank : i+1;
        answer[p.second] = rank;
            
        prevScore = p.first;
    }
    
    return answer;
}