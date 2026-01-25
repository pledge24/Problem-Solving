#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> s;
    int N = prices.size();
    
    // Init
    answer.resize(N);
           
    // Process
    for(int i = 0; i < N; i++)
    {
        int price = prices[i];
        while(!s.empty() && s.top().first > price)
        {
            int idx = s.top().second;
            answer[idx] = i - idx;
            s.pop();
        }
        s.push(make_pair(prices[i], i));
    }
    
    while(!s.empty())
    {
        int idx = s.top().second;
        answer[idx] = N - 1 - idx;
        s.pop();
        
        // cout << "idx: " << idx << '\n';
    }
    
    return answer;
}