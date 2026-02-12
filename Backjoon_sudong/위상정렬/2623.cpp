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
    int taskN, cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int prevVtx, curVtx;
        cin >> taskN >> prevVtx;
        for(int t = 1; t < taskN; t++){
            cin >> curVtx;

            if(find(graph[prevVtx].begin(), graph[prevVtx].end(), curVtx) == graph[prevVtx].end()){
                graph[prevVtx].push_back(curVtx);
                indeg[curVtx]++;
            }
            prevVtx = curVtx;
        }
        
    }

    queue<int> q;
    vector<int> ans;
    for(int i = 1; i <= N; i++){
        if(indeg[i] == 0){
            q.push(i);
            cnt++;
        } 
    }

    int orderNo = 1;
    while(!q.empty()){
        int vtx = q.front(); q.pop();
        ans.push_back(vtx);
        
        for(int adjVtx : graph[vtx]){
            indeg[adjVtx]--;
            if(indeg[adjVtx] == 0){
                q.push(adjVtx);
                cnt++;
            } 
        }
    }

    if(cnt != N){
        cout << 0 << '\n';
        return 0;
    }

    for(int vtx : ans){
        cout << vtx << '\n';
    }
}