#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct craftData{
    int craftCost;
    int pathCost = INT32_MIN;
};

int main() {
	fastio;
    int N; cin >> N;

    vector<craftData> craftings;
    vector<vector<int>> graph(N+1);
    vector<int> indeg(N+1);

    craftings.resize(N+1);
    for(int vtx = 1; vtx <= N; vtx++){
        cin >> craftings[vtx].craftCost;
        
        int preVtxs; cin >> preVtxs;
        int pv;
        while(preVtxs > 0){
            cin >> pv;
            graph[vtx].push_back(pv);
            indeg[pv]++;

            preVtxs--;
        }
        
    }

    queue<int> q;
    for(int i = 1; i <= N; i++){
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

    int minTaskTime = 0;
    for(int vtx = 1; vtx <= N; vtx++){
        int cost = craftings[vtx].craftCost + craftings[vtx].pathCost;
        minTaskTime = max(minTaskTime, cost);
    }

    cout << minTaskTime << '\n';
}