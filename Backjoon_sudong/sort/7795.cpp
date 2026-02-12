#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<int> B(M);
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }
    sort(B.begin(), B.end());

    int cnt = 0;
    for(int i = 0; i < N; i++){
        int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        cnt += idx;
    }

    cout << cnt << '\n';
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;   
}