#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct craftData{
    int craftCost;
    int pathCost = INT32_MIN;
};

void ACMCraftSolve(){
    int N, K; cin >> N >> K;

    vector<craftData> craftings;
    craftings.resize(N+1);

    for(int i = 1; i <= N; i++){
        cin >> craftings[i].craftCost;
    }

    vector<vector<int>> graph(N+1);
    vector<int> indeg(N+1);
    
    int vtx1, vtx2;
    for(int i = 0; i < K; i++){
        cin >> vtx1 >> vtx2;

        graph[vtx1].push_back(vtx2);
        indeg[vtx2]++;
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

    // for(int i = 1; i <= N; i++){
    //     cout << craftings[i].pathCost << ' ';
    // }
    // cout << '\n';

    int W; cin >> W;

    int ans = craftings[W].craftCost + craftings[W].pathCost;
    cout << ans << '\n';
}

int main() {
	//fastio;
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        ACMCraftSolve();
    }
    
}