#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){

    int N, M; cin >> N >> M;

    queue<pair<int, int>> q;
    priority_queue<int, vector<int>, less<int>> pq;

    for(int i = 0; i < N; i++){
        int prior; cin >> prior;

        q.push({i, prior});
        pq.push(prior);
    }
    
    int nextOrder = 1;
    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        
        if(p.second < pq.top()){
            q.push(p);
            continue;
        }

        if(p.first == M){
            cout << nextOrder << '\n';
            return;
        }

        pq.pop();    
        nextOrder++;
    }

    
}

int main(void){
    fastio;

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}