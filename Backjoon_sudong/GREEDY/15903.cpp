#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;

    int N, M; cin >> N >> M;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long num;
    for(int i = 0; i < N; i++){
        cin >> num;
        pq.push(num);
    }

    for(int i = 0; i < M; i++){
        long long x = pq.top(); pq.pop();
        long long y = pq.top(); pq.pop();

        pq.push(x + y);
        pq.push(x + y);
    }

    long long ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans << '\n';
}