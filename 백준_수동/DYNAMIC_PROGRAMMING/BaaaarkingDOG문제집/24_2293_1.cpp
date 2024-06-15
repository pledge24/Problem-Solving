#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int ans = 0;
int n, k;
vector<int> coins;

void dfs(int k, int idx){
    if(k <= 0){
        if(k == 0) ans++;       
        return;
    }

    for(int i=idx; i<n; i++){
        if(k-coins[i] >= 0){
            dfs(k-coins[i], i);
        }
        
    }
}

int main() {
	fastio;
    cin >> n >> k;
  
    coins.resize(n);
    for(int i=0;i <n; i++){
        cin >> coins[i];
    }
    sort(coins.rbegin(), coins.rend());

    // for(int i=0;i <n; i++){
    //     cout << coins[i] <<' ';
    // }
    // cout << '\n';

    dfs(k, 0);

    cout << ans << '\n';

}