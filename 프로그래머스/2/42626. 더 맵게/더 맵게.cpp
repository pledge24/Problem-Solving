#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int64, vector<int64>, greater<int64>> pq;
    for(int elem : scoville)
    {
        pq.push(elem);
    }
    
    while(pq.top() < K)
    {
        if(pq.size() <= 1)
        {
            break;
        }
        
        int64 scv1 = pq.top(); pq.pop();
        int64 scv2 = pq.top(); pq.pop();
        
        // cout << scv1 << " " << scv2 << '\n';
        int64 newScv = scv1 + scv2*2;
        
        answer++;
        pq.push(newScv);
    }
    
    if(pq.top() < K)
        answer = -1;
    
    return answer;
}