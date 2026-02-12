#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<vector<int>>;
using moveData = pair<int, int>;
void bfs(Graph graph, int& ans, int src, int dst){

    vector<bool> visited(graph.size());
    queue<moveData> q; 
    
    q.push(make_pair(src, 0));
    visited[src] = true;

    while(!q.empty()){
        moveData moveData = q.front(); q.pop();

        int vtx = moveData.first;
        int cnt = moveData.second;

        for(int next : graph[vtx]){
            if(!visited[next]){
                q.push(make_pair(next, cnt+1));
                visited[vtx] = true;

                if(next == dst){
                    ans = cnt+1;
                    return;
                }
            }
        }
    }

    return;
}

int main(void){
    fastio;
    int N; cin >> N;
    int a, b; cin >> a >> b;
    int M; cin >> M;

    Graph graph(N+1);
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = -1;
    bfs(graph, ans, a, b);

    cout << ans << '\n';

    return 0;
}