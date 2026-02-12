#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF INT32_MAX

using namespace std;
using EdgeData = pair<int, int>; // dst, weight
using PathData = pair<int, int>; // pathLen, vtx
using Graph = vector<vector<EdgeData>>; 

int N, M; 

// 같은 (s, t) 처리 안 한 상태
int dijkstra(Graph& graph){
    int s = 1;
    int t = N;

    vector<int> minDist(N+1, INF);
    minDist[1] = 0;

    priority_queue<PathData, vector<PathData>, greater<PathData>> pq;
    pq.push(PathData(0, 1));

    while(!pq.empty()){
        PathData curPath = pq.top(); pq.pop();

        int curPathLen = curPath.first;
        int curVtx = curPath.second;

        if(minDist[curVtx] < curPathLen)
            continue;

        vector<EdgeData>& adj = graph[curVtx];
        for(int i = 0; i < adj.size(); i++){
            int nextVtx = adj[i].first;
            int dist = curPath.first + adj[i].second;
            if(dist < minDist[nextVtx]){
                minDist[nextVtx] = dist;
                pq.push(PathData(dist, nextVtx));
            }
        }
    }

    return minDist[N];
}

int main(void){
    fastio;
    cin >> N >> M;

    Graph graph(N+1);
    for(int i = 0; i < M; i++){
        int A, B, W; cin >> A >> B >> W;

        graph[A].push_back(make_pair(B, W));
        graph[B].push_back(make_pair(A, W));
    }

    int ans = dijkstra(graph);

    cout << ans << '\n';

    return 0;
}