#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 100'000'000
using namespace std;

struct edgeData{
    int vtx1;
    int vtx2;
    int weight;
};

vector<long long> bellmanFord(vector<vector<int>> graph, vector<edgeData> edgeList){
    vector<long long> minDist(graph.size(), INF);
    minDist[1] = 0;

    int st = 1;
    int N = graph.size()-1, E = edgeList.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < E; j++){
            int vtx1 = edgeList[j].vtx1;
            int vtx2 = edgeList[j].vtx2;
            int weight = edgeList[j].weight;
            
            if(minDist[vtx1] != INF && minDist[vtx1] + graph[vtx1][vtx2] < minDist[vtx2]){
                minDist[vtx2] = minDist[vtx1] + graph[vtx1][vtx2];

                if(i == N-1) return {};
            }
        }
    }
    
    for(long long& elem : minDist){
        if(elem >= INF) elem = -1;
    }

    return minDist;
}

int main() {
	fastio;
    int N, M; cin >> N >> M;

    vector<vector<int>> graph;
    vector<edgeData> edgeList;
    graph.resize(N+1, vector<int>(N+1, INF));

    for(int i = 1; i <= N; i++){
        graph[i][i] = 0;
    }

    int A, B, C;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;
        graph[A][B] = min(graph[A][B], C);
        edgeList.push_back({A, B, C});
    }

    // int는 안되고 longlong은 되는 이유가 뭘까...
    vector<long long> ans = bellmanFord(graph, edgeList);

    if(ans.size() > 0){
        for(int i = 2; i <= N; i++){
            cout << ans[i] << '\n';
        }
    }
    else{
        cout << -1 << '\n';
    }
    
    
}