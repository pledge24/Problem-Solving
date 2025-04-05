#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        int cardN; cin >> cardN;
        pq.push(cardN);
    }

    int cnt = 0;
    while(pq.size() > 1){
        int A, B; 
        A = pq.top(); pq.pop();
        B = pq.top(); pq.pop();

        cnt += A + B;
        pq.push(A + B);
    }

    cout << cnt << '\n';

    return 0;
}