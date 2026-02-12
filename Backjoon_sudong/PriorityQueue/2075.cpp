#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N*N; i++){
        int num; cin >> num;

        if(pq.empty() || pq.top() < num){
            pq.push(num);
        }

        while(pq.size() > N)
            pq.pop();
    }

    cout << pq.top() << '\n';

    return 0;
}