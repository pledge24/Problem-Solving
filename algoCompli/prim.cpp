#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int v, e;

vector<vector<pair<int, int>>> adj;

// 시간복잡도 O(ElogE)
int prim(){
    vector<bool> visited; visited.resize(v+1);
    int cnt = 0;
    int ans = 0;
    int start = 1;

    // tuple<int, int, int> : {가중치, 정점 1, 정점 2}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    visited[start] = true;
    for(auto ed : adj[start]){
        pq.push({ed.first, start, ed.second});
    }

    while(cnt < v - 1){
        int weight, vtx1, vtx2;
        tie(weight, vtx1, vtx2) = pq.top(); pq.pop();

        // 이미 방문한 정점이면 넘어간다.
        if(visited[vtx2]) continue;

        visited[vtx2] = true;
        cnt++;
        ans += weight;

        // 인접한 간선들을 우선순위 큐에 삽입한다.
        for(auto ed : adj[vtx2]){
            pq.push({ed.first, vtx2, ed.second});
        }
    }

    return ans;
}

int main() {
	fastio;

    
}