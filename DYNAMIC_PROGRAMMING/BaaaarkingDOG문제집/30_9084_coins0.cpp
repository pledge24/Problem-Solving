#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int n, k;
vector<int> coins;

int main() {
	fastio;

    int T; cin >> T;

    for(int i = 0; i < T; i++){
        cin >> n;
        coins.resize(n);
        //input coins value.
        for(int i=0; i<n; i++){
            cin >> coins[i];
        }
        sort(coins.rbegin(), coins.rend());

        cin >> k;

        vector<int> v1(k+1);
        // 코인 수 만큼 반복.
        for(int i=0; i<n; i++){
            vector<int> v2(k+1);
            // 1부터 원하는 동전의 합(k)까지 순차적으로 경우의 수 저장(v2)
            for(int j=1; j<=k; j++){
                int temp_j = j;
                while(temp_j > 0){
                    v2[j] += v1[temp_j];

                    temp_j -= coins[i];
                }
                
                if(j % coins[i] == 0) v2[j]++;
            }
            
            v1=v2;
        }

        int ans = v1[k];

        cout << ans << '\n';    
    }

}