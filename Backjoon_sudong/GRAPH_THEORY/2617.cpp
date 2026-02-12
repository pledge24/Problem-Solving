#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<pair<vector<int>, vector<int>>>; // heavier, lighter

int bfs(Graph& graph, int start, bool isHeavierCount){
    queue<int> q;
    vector<bool> visited(graph.size());

    q.push(start);
    // 4 -> 6, 5 -> 6, 4 -> 5 인 경우 6이 두 번 들어감
    visited[start] = true;    

    int cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();

        vector<int>& adj = isHeavierCount ? graph[cur].first : graph[cur].second;
        for(int elem : adj){
            if(!visited[elem]){
                q.push(elem);
                visited[elem] = true;    
                cnt++;
            }
        }
    }

    return cnt;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;
    Graph graph(N+1);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B;
        graph[A].first.push_back(B); // A is heavier
        graph[B].second.push_back(A); // B is lighter
    }

    vector<int> res(N+1);
    for(int i = 1; i <= N; i++){
        int heavierCount = bfs(graph, i, true);
        int lighterCount = bfs(graph, i, false);
        res[i] = max(heavierCount, lighterCount);

        // cout << heavierCount << " " << lighterCount << '\n';
    }

    int ans = count_if(res.begin(), res.end(), [N](int elem){ return elem > N/2;});

    cout << ans << '\n';

    return 0;
}