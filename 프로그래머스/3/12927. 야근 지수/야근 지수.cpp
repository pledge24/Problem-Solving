#include <bits/stdc++.h>

using namespace std;

// 야근 피로도 = 남은 작업량 ^ 2의 합
// N시간 동안 야근 피로도 최소 -> 시간당 작업량 1처리
// 야근 피로도 최소값?
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(int& elem : works)
    {
        pq.push(elem);
    }
    
    while(n-- > 0)
    {
        if(pq.empty())
            break;
        
        int elem = pq.top(); pq.pop();
        elem--;
        
        if(elem > 0)
            pq.push(elem);
    }
    
    while(!pq.empty())
    {
        long long elem = pq.top(); pq.pop();
        
        answer += elem * elem;
    }
    
    return answer;
}