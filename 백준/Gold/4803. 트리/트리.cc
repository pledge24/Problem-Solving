#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<vector<int>>;

bool bfs(Graph& graph, vector<int>& visited, int start){
    queue<int> q;
    q.push(start);
    visited[start] = start;

    bool res = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();

        int visitedN = 0;
        for(int adj : graph[cur]){
            if(visited[adj] == start){
                visitedN++;
                continue;
            }

            if(visited[adj] == -1/*Not Visited*/){
                q.push(adj);
                visited[adj] = start;
            }
        }

        if(visitedN > 1)
            res = false;
    }

    return res;
}

void startTest(int N, int M, int TestN){
    Graph graph(N+1);
    // Draw Graph.
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    int cnt = 0;
    vector<int>visited(N+1, -1);
    for(int i = 1; i <= N; i++){
        if(visited[i] == -1/*Not Visited*/){
            bool isTree = bfs(graph, visited, i);
            cnt += isTree;
        }
    }

    if(cnt == 0)
        printf("Case %d: No trees.\n", TestN);
    else if(cnt == 1)
        printf("Case %d: There is one tree.\n", TestN);
    else
        printf("Case %d: A forest of %d trees.\n", TestN, cnt);

    return;
}

int main(void){
    fastio;

    int T = 0;
    while(true){
        int N, M; cin >> N >> M;
        if(make_pair(N, M) == make_pair(0, 0))
            break;
        startTest(N, M, ++T);
    }


    return 0;
}