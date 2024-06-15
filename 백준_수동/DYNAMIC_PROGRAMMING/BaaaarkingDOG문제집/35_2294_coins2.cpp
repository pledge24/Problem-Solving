#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX_COINS 10001

using namespace std;

int n, k;
vector<int> coins;

int main() {
	fastio;
    cin >> n >> k;
  
    int coin;
    map<int, int> overlap_check;
    for(int i=0; i<n; i++){
        cin >> coin;
        if(overlap_check[coin] == 0){
            coins.push_back(coin);
            overlap_check[coin]++;
        }   
    }

    sort(coins.begin(), coins.end());
   
    vector<int> v1(k+1, MAX_COINS);
    int coins_idx = 0;
    for(int i = 1; i<=k; i++){
        if(coins[coins_idx] == i){
            v1[i] = 1;
            coins_idx++;
            continue;
        }

        for(int coins_temp = 0; coins_temp <= coins_idx; coins_temp++){
            int sub_i = i-coins[coins_temp];
            if(sub_i > 0){
                v1[i] = min(v1[i], v1[sub_i] + 1);
            }
            
        }
    }
    // // print test.
    // for(int elem: coins){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    // // print test.
    // for(int i = 1; i <= k; i++){
    //     cout << i << '\t';
    // }
    // cout << '\n';

    // // print test.
    // for(int i = 1; i <= k; i++){
    //     cout << v1[i] << '\t';
    // }
    // cout << '\n';

    int ans = v1[k] == MAX_COINS ? -1 : v1[k];

    cout << ans << '\n';

}