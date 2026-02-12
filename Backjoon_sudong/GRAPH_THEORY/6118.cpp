#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<vector<int>>;

void bfs(Graph& graph, vector<int>& distance, int start){
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int adj : graph[cur]){
            if(distance[adj] == -1){
                q.push(adj);
                distance[adj] = distance[cur] + 1;
            }
        }
    }

    return;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;
    
    Graph graph(N+1);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<int> distance(N+1, -1);
    int start = 1;
    bfs(graph, distance, start);

    int idx = max_element(distance.begin(), distance.end()) - distance.begin();
    int minDistance = distance[idx];
    int cnt = count(distance.begin(), distance.end(), minDistance);

    cout << idx << " " << minDistance << " "<< cnt << '\n';

    return 0;
}