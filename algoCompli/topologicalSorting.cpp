#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int V;                      // 정점 개수
vector<vector<int>> graph;  // 그래프
vector<int> indeg;          // 각 정점의 indegree값이 저장된 배열

bool topologicalSorting(vector<int>& result){

    queue<int> q;
    
    // indeg가 0인 정점들을 큐에 추가
    for(int i = 1; i <= V; i++){
        if(indeg[i] == 0){
            q.push(i);
        } 
    }

    // indeg가 0인 정점이 큐에 존재하지 않을 때까지 반복
    while(!q.empty()){
        int vtx1 = q.front(); q.pop();
        result.push_back(vtx1);

        for(int vtx2 : graph[vtx1]){
            indeg[vtx2]--;

            if(indeg[vtx2] == 0){     
                q.push(vtx2);
            } 
        }
    }

    // 사이클이 발생했다면 false 반환.
    if(result.size() != V) return false;

    return true;
}

int main() {
	fastio;

    
}