#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<vector<int>>;

int V, E; 

bool bfs(const Graph& graph, vector<pair<bool, char>>& visited, int start){
    queue<pair<int, char>> q; // idx, color
    
    
    q.push(make_pair(start, 'r'));
    visited[start] = make_pair(true, 'r');

    while(!q.empty()){
        pair<int, char> cur = q.front(); q.pop();

        for(int adj : graph[cur.first]){
            if(visited[adj] == make_pair(true, cur.second))
                return false;
            
            if(!visited[adj].first){
                char nextChar = cur.second == 'r' ? 'c' : 'r';
                q.push(make_pair(adj, nextChar));
                visited[adj] = make_pair(true, nextChar);
            }
            
        }
    }

    return true;
}

void startTest(){
    cin >> V >> E;
    Graph graph(V+1);
    for(int i = 0; i < E; i++){
        int s, t; cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }

    vector<pair<bool, char>> visited(V+1); // visited, color
    bool flag = true;
    for(int i = 1; i <= V; i++){
        if(!visited[i].first){
            flag &= bfs(graph, visited, i);
        }
    }
    
    string ans = flag ? "YES" : "NO";

    cout << ans << '\n';

    return;
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}