#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

int Bfs(Graph& graph, int src, int dst){
    vector<bool> visited(graph.size());
    
    queue<pair<int, int>> q; // vtx, dist
    q.push(make_pair(src, 0));
    visited[src] = true;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        
        int curVtx = cur.first;
        int curDist = cur.second;
        
        if(curVtx == dst)
            return curDist;
        
        for(int adj : graph[curVtx]){           
            if(!visited[adj]){
                q.push(make_pair(adj, curDist + 1));
                visited[adj] = true;                
            }
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    Graph graph(n+1);
    for(auto edge : roads){
        int vtx1 = edge[0];
        int vtx2 = edge[1];
        
        graph[vtx1].push_back(vtx2);
        graph[vtx2].push_back(vtx1);
    }
    
    int dst = destination;
    for(auto src : sources){
        int ans = Bfs(graph, src, dst);
        answer.push_back(ans);
    }
    
    return answer;
}