#include <bits/stdc++.h>

using namespace std;

// 두 도둑은 물건을 훔치면 흔적을 남긴다.
// A 도둑은 n개 이상의 흔적을 남기면 잡히고,
// B 도둑은 m개 이상의 흔적을 남기면 잡힌다.
// 두 도둑이 붙잡히지 않고 모든 물건을 훔쳤을 때, A 도둑이 남긴 흔적의 최소값을 구해라.
// 두 도둑 모두 경찰에 붙잡히지 않고 모든 물건을 훔칠 수 없다면 -1을 반환해라.
int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int N = info.size();
    
    // dp적으로 풀까? dp[i-1]: 흔적의 한 쌍들(A, B)
    vector<map<int, int>> DP(N+1);
    DP[0].insert(make_pair(0, 0));
    for(int i = 1; i <= N; i++){
        int costA = info[i-1][0];
        int costB = info[i-1][1];
        
        for(auto elem : DP[i-1]){
            // 도둑 A가 훔침.
            if(elem.first + costA < n){
                if(DP[i].find(elem.first + costA) != DP[i].end())
                    DP[i][elem.first + costA] = min(DP[i][elem.first + costA], DP[i-1][elem.first]);
                else
                    DP[i][elem.first + costA] = DP[i-1][elem.first];
            }
                
            // 도둑 B가 훔침.
            if(DP[i-1][elem.first] + costB < m){
                if(DP[i].find(elem.first) != DP[i].end())
                    DP[i][elem.first] = min(DP[i][elem.first], DP[i-1][elem.first] + costB);
                else
                    DP[i][elem.first] = DP[i-1][elem.first] + costB;
            }
        }
        
        // for(pair<int, int> elem : DP[i]){
        //     cout << elem.first << " " << elem.second << '\n';
        // }
        // cout << '\n';
    }
    
    answer = DP[N].size() > 0 ? DP[N].begin()->first : -1; 
    
    return answer;
}