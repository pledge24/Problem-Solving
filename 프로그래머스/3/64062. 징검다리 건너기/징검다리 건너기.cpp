#include <bits/stdc++.h>

#define INF 1'000'000'000

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INF;
    
    // 개수를 관리하면서 가장 큰 값을 알아야함.
    map<int, int> m1; // Slide Window <value, count>
    
    // Init
    for(int i = 0; i < k-1; i++)
    {
        int value = stones[i];
        m1[value]++;
    }
    
    for(int i = k-1; i < stones.size(); i++)
    {
        // Push
        int value = stones[i];
        m1[value]++;
        
        // Eval
        pair<int, int> p = *m1.rbegin();
        answer = min(answer, p.first);
        
        // for(auto x : m1)
        // {
        //     cout << x.first << " ";
        // }
        // cout << '\n';
        
        // Pop
        int head = stones[i - k + 1];
        m1[head]--;
        if(m1[head] <= 0)
            m1.erase(head);
    }
    
    // for(int i = 0; i < stones.size() - k + 1; i++)
    // {
    //     int maxValue = 0;
    //     for(int j = i; j < i + k; j++)
    //     {
    //         maxValue = max(maxValue, stones[j]);
    //     }
    //     answer = min(answer, maxValue);
    // }
    
    return answer;
}