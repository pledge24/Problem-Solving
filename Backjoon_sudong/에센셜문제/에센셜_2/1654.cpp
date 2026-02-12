#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long upperBound(vector<long long>& v1, long long N){
    long long maxLen = INT32_MAX;

    long long start = 1, end = maxLen; 
    while(start + 1 < end){
        long long mid = (start + end) / 2;

        long long cnt = 0;
        for(long long elem : v1){
            cnt += elem / mid;
        }

        if(cnt >= N){    // Satisfying(오른쪽 이동)
            start = mid;
        }
        else{            // Not Satisfying(왼쪽이동)
            end = mid;
        }
    }

    long long cnt = 0;
    for(long long elem : v1){
        cnt += elem / end;
    }

    if(cnt >= N){    // Satisfying(오른쪽 이동)
        start = end;
    }

    return start;
}

int main(void){
    fastio;
    long long K, N; cin >> K >> N;

    vector<long long> v1(K);
    for(long long i = 0; i < K; i++){
        cin >> v1[i];
    }

    // N개 이상을 만들어내는 가장 큰 Len을 구하자
    long long ans = upperBound(v1, N);

    cout << ans << '\n';

    return 0;
}