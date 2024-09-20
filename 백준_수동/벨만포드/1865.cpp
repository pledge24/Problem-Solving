#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1'000'000'000

using namespace std;

struct edgeData{
    int vtx1;
    int vtx2;
    int weight;
};

vector<long long> bellmanFord(vector<vector<int>> graph, vector<edgeData> edgeList, int st){
    vector<long long> minDist(graph.size(), INF);
    minDist[st] = 0;

    int N = graph.size()-1, E = edgeList.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < E; j++){
            int vtx1 = edgeList[j].vtx1;
            int vtx2 = edgeList[j].vtx2;
            int weight = edgeList[j].weight;
            
            if(minDist[vtx1] != INF && minDist[vtx1] + graph[vtx1][vtx2] < minDist[vtx2]){
                minDist[vtx2] = minDist[vtx1] + graph[vtx1][vtx2];

                if(i == N-1){
                    minDist[vtx2] = -INF;
                }
            }
        }
    }

    return minDist;
}

bool solve(){
    int N, M, W; cin >> N >> M >> W;

    vector<vector<int>> graph(N+1, vector<int>(N+1, INF));
    vector<edgeData> edgeList;

    for(int i = 1; i <= N; i++){
        graph[i][i] = 0;
    }

    int vtx1, vtx2, weight;
    for(int i = 0; i < M; i++){
        cin >> vtx1 >> vtx2 >> weight;

        graph[vtx1][vtx2] = min(graph[vtx1][vtx2], weight);
        graph[vtx2][vtx1] = min(graph[vtx2][vtx1], weight);

        edgeList.push_back({vtx1, vtx2, weight});
    }

    for(int i = 0; i < W; i++){
        cin >> vtx1 >> vtx2 >> weight;

        graph[vtx1][vtx2] = min(graph[vtx1][vtx2], -weight);

        edgeList.push_back({vtx1, vtx2, -weight});
    }

    vector<vector<long long>> minPathList(N+1);
    for(int i = 1; i <= N; i++){
        minPathList[i] = bellmanFord(graph, edgeList, i);

        // for(long long elem : minDist){
        //     cout << elem << ' ';
        // }
        // cout << '\n';
    }
    
    for(int from = 1; from <= N; from++){
        for(int to = 1; to <= N; to++){
            if(minPathList[from][to] == -INF || minPathList[to][from] == -INF){
                if(minPathList[from][to] != INF && minPathList[to][from] != INF){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
	fastio;
    int TC; cin >> TC;

    for(int tc = 0; tc < TC; tc++){
        bool res = solve();

        string ans = res ? "YES" : "NO";
        cout << ans << '\n';
    }
}