#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<string> v1;


int main() {
	fastio;
    int N; cin >> N;
   
    vector<string> dp(N+1);

    dp[1] = dp[3] = dp[4] = "SK";

    vector<int> caseA{2, 4, 5, 6, 7, 8};

    for(int i = 2; i<=N; i++){
        if(!dp[i].empty()) continue;

        for(auto elem : caseA){
            if(i-elem >= 0 &&dp[i - elem] == "SK"){
                dp[i] = "SK";
            }
        }

        if(dp[i].empty()) dp[i] = "CK";
    }

    for(auto elem : dp){
        cout << elem << " ";
    }
    cout << '\n';

    cout << dp[N] << '\n';
}