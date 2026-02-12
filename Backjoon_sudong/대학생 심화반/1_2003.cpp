#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N, M; cin >> N >> M;

    vector<int> v1(N);

    // input data
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = i; j < N; j++){
            sum += v1[j];
            if(sum == M){
                //cout << j << '\n';
                cnt++;
                break;
            }
        }
    }
    
    int ans = cnt;

    cout << ans << '\n';
}