#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<vector<int>> graph;  // 인접 노드 방식
vector<bool> visited;
vector<int> path;

void dfs(int here){
    
    // 방문 처리.
    visited[here] = true;
    path.push_back(here);

    // 조건 만족시 실행
    // if(isCondition){
        
    // }

    for(int there : graph[here]){
        if(!visited[there]){
            dfs(there);
        } 
    }

    return;
}

void dfsAll(){
    for(int here = 1; here < graph.size(); here++){
        if(!visited[here]){
            dfs(here);
        } 
    }
}

int main() {
	fastio;
    
    int N, M, V; cin >> N >> M >> V;

    graph.resize(N+1);
    visited.resize(N+1);
    for(int i = 0; i < M; i++){
        int s, t; cin >> s >> t;
        graph[s].push_back(t);
    }

    dfsAll();

    for(int elem : path){
        cout << elem << ' ';
    }
    cout << '\n';
}
