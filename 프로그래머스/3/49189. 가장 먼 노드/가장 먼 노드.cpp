#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

void Bfs(Graph& graph, map<int, int>& m1){   
    queue<pair<int, int>> q;
    vector<bool> visited(graph.size());
    
    q.push(make_pair(1, 0));
    visited[1] = true;
    m1[0]++;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        
        for(auto adj : graph[cur.first]){
            if(!visited[adj]){
                q.push(make_pair(adj, cur.second+1));
                visited[adj] = true;
                m1[cur.second + 1]++;
            }
            
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    Graph graph(n+1);
    for(auto e : edge){
        int vtx1 = e[0];
        int vtx2 = e[1];
        
        graph[vtx1].push_back(vtx2);
        graph[vtx2].push_back(vtx1);
    }
    
    map<int, int> m1;
    Bfs(graph, m1);
    
    // for(auto elem : m1){
    //     cout << elem.first << " " << elem.second << ' ';
    // }
    // cout << '\n';
    
    answer = (*max_element(m1.begin(), m1.end())).second;
    
    return answer;
}