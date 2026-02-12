#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct edgeData{
    int next;
    int k;
};

int main()
{
    fastio;
    int N, M; cin >> N >> M;

    vector<vector<edgeData>> graph;
    vector<int> indeg;
    graph.resize(N+1);
    indeg.resize(N+1);

    // graph 생성
    int X, Y, K;
    for (int i = 0; i < M; i++)
    {
        cin >> X >> Y >> K;
        graph[Y].push_back({X, K});
        indeg[X]++;
    }

    queue<int> q;
    vector<map<int, int>> vtxData(N+1);
    for(int i = 1; i <= N; i++){
        if(indeg[i] == 0){
            q.push(i);
            vtxData[i][i] = 1;
        } 
    }

    while(!q.empty()){
        int vtx = q.front(); q.pop();
        
        for(edgeData nextEdge : graph[vtx]){
            //cout << vtx << " " << nextEdge.next << " " << nextEdge.k << '\n';
            indeg[nextEdge.next]--;

            for(auto it : vtxData[vtx]){
                vtxData[nextEdge.next][it.first] += it.second*nextEdge.k;
            }

            if(indeg[nextEdge.next] == 0){
                q.push(nextEdge.next);
            } 
        }
    }

    for(auto it : vtxData[N]){
        if(it.second > 0)
            cout << it.first << " " << it.second << '\n';
    }
}