#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
    fastio;
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph;
    vector<int> indeg;
    graph.resize(N+1);
    indeg.resize(N+1);

    // graph 생성
    int vtx1, vtx2;
    for (int i = 0; i < M; i++)
    {
        cin >> vtx1 >> vtx2;
        graph[vtx1].push_back(vtx2);
        indeg[vtx2]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i = 1; i <= N; i++){
        if(indeg[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int vtx = pq.top(); pq.pop();
        cout << vtx << ' ';
        ans.push_back(vtx);
        for(int adjVtx : graph[vtx]){
            indeg[adjVtx]--;
            if(indeg[adjVtx] == 0) pq.push(adjVtx);
        }
    }

    
}