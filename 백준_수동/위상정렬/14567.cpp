#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct craftData{
    int craftCost;
    int pathCost = INT32_MIN;
};

int main() {
	//fastio;
    int N, M; cin >> N >> M;

    vector<craftData> craftings;
    vector<vector<int>> graph(N+1);
    vector<int> indeg(N+1);

    craftings.resize(N+1);

    int vtx1, vtx2;
    for(int vtx = 1; vtx <= M; vtx++){
        cin >> vtx1 >> vtx2;
        graph[vtx1].push_back(vtx2);
        indeg[vtx2]++;
    }

    queue<int> q;
    for(int i = 1; i <= N; i++){
        craftings[i].craftCost = 1;
        if(indeg[i] == 0){
            craftings[i].pathCost = 0;
            q.push(i);
        } 
    }


    while(!q.empty()){
        int vtx = q.front(); q.pop();

        for(int nextVtx : graph[vtx]){
            indeg[nextVtx]--;

            craftings[nextVtx].pathCost = max(craftings[nextVtx].pathCost, craftings[vtx].pathCost + craftings[vtx].craftCost);
            if(indeg[nextVtx] == 0){     
                q.push(nextVtx);
            } 
        }
    }

    for(int vtx = 1; vtx <= N; vtx++){
        int cost = craftings[vtx].craftCost + craftings[vtx].pathCost;
        cout << cost << ' ';
    }
    cout << '\n';
}