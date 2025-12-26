#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(vector<int>& range : targets)
    {
        int s = range[0];
        int e = range[1];
        pq.push(make_pair(s, e));    
    }
    
    int maxEnd = pq.top().second - 1; // 가장 멀리 갈 수 있는 위치
    while(!pq.empty())
    {
        pair<int, int> p1 = pq.top(); pq.pop();
        
        if(maxEnd < p1.first)
        {
            // cout << "check" << '\n';
            answer++;
            maxEnd = p1.second - 1;        
        }
        else
        {
            maxEnd = min(maxEnd, p1.second - 1);
        }
        
        // cout << p1.first << " " << p1.second << '\n';
    }
    
    return answer+1;
}