#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    long long K; cin >> K;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i = 0; i < K; i++){
        long long num; cin >> num;
        pq.push(num);
    }

    long long cost = 0;
    while(pq.size() > 1){
        long long A = pq.top(); pq.pop();
        long long B = pq.top(); pq.pop();
        // cout << A << " " << B << " " << A+B << "\n";
        cost += A + B;
        pq.push(A + B);
    }

    cout << cost << '\n';
}

int main(void){
    fastio;
    long long T; cin >> T;
    for(long long i = 0; i < T; i++){
        startTest();
    }

    return 0;
}