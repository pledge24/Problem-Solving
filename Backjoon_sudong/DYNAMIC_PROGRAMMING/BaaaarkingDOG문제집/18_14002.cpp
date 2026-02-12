#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<int> v1(N+1);

    for(int i=1; i<=N; i++){
        cin >> v1[i];       
    }
    
    vector<pair<int,int>> dp(N+1);  // first: cnt, second: before_idx;
    for(int i=1; i<=N; i++){
        int num = v1[i];

        for(int j=1; j<i; j++){
            // 현재 수보다 작은 수 중, 가장 긴 수열을 가진 idx를 찾는다.
            if(v1[j] < num){
                dp[i] = dp[i].first < dp[j].first ? make_pair(dp[j].first, j) : dp[i];
            }
        }
        // 찾은 길이에 1을 더한다.
        dp[i].first++;
                 
    }

    // print test
    //cout << "ans_idx is : " << ans_idx << '\n';
    //cout << "The longest is: " << dp[ans_idx].first << '\n';

    vector<int> ans;

    int ans_idx = 1;
    for(int i=2; i<=N; i++){
        ans_idx = dp[ans_idx].first < dp[i].first ? i : ans_idx;
    }

    cout << dp[ans_idx].first << '\n';

    int cur_idx = ans_idx;
    while(dp[cur_idx].second != 0){   
        ans.push_back(v1[cur_idx]);
        cur_idx = dp[cur_idx].second;       
    }
    ans.push_back(v1[cur_idx]);

    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}