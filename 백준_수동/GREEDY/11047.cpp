#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; int K; cin >> N >> K;

    vector<int> v1;
    v1.resize(N);

    for(int i = N-1; i >= 0; i--){
        cin >> v1[i];
    }
    
    int sum = 0;
    int cnt = 0;

    for(int i = 0; i < N && sum < K; i++){
        if(v1[i] > K) continue;

        while(K - sum >= v1[i]){
            sum += v1[i];
            cnt++;
        }

        if(sum == K) break;
    }

    cout << cnt << '\n';
}