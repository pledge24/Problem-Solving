#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

// 양쪽 끝 등대 중 하나는 켜져있어야한다의 조건 (그래프는 트리형태)
// 1) 인접 노드중 켜져있거나 켜져있는 노드와 연결된 상태가 아닌 노드가 존재한다면,
// 현재 노드를 켠다. (시작 위치는 상관없을듯?)
void DfsUtil(Graph& graph, vector<bool>& connected, vector<bool>& visited, int& answer, int curVtx){
    visited[curVtx] = true;
    
    bool existNotConnected = false;
    // int childN = 0;
    for(int adj : graph[curVtx]){
        // cout << "curVtx, adj: " << curVtx << " " << adj << '\n';
        // 방문한 노드(ex. 부모 노드)는 pass.
        if(visited[adj] == true)
            continue;
        
        // childN++;
        
        DfsUtil(graph, connected, visited, answer, adj);    
        
        // 방문한 해당 인접 노드가 연결되어있지 않다면, 해당 내용을 기록.
        if(connected[adj] == false)
            existNotConnected = true;
    }
    
    // 연결되어 있지 않은 노드가 존재한다면, 현재 노드를 켠다.
    if(existNotConnected == true){
        answer++;
        connected[curVtx] = true;
    }             
      
    return;
}

void Dfs(Graph& graph, int& answer, int n){
    vector<bool> visited(n+1);
    vector<bool> connected(n+1);
    
    int start = 1;
    DfsUtil(graph, connected, visited, answer, 1);    
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;

    Graph graph(n+1);
    for(auto edge : lighthouse){
        int vtx1 = edge[0];
        int vtx2 = edge[1];
        
        graph[vtx1].push_back(vtx2);
        graph[vtx2].push_back(vtx1);    
    }
    
    Dfs(graph, answer, n);
    
    return answer;
}