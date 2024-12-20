#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long getResult(vector<long long> &v1, vector<long long> &salesPointList, int N){
    long long res = 0;

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(v1[i] < salesPointList[i]){
            cnt++;
            res -= v1[i];
        }
        else if(v1[i] == salesPointList[i]){
            res += cnt * v1[i];
            cnt = 0;
        }
    }

    return res;
}

void startTest(){
    int N; cin >> N;

    vector<long long> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    vector<long long> salesPointList(N);
    long long max_point = 0;
    for(int i = N-1; i >= 0; i--){
        max_point = max(max_point, v1[i]);
        salesPointList[i] = max_point;
    }

    long long ans = getResult(v1, salesPointList, N);
    cout << ans << '\n';

    return;
}

int main() {
	fastio;
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        startTest();
    }
    
}