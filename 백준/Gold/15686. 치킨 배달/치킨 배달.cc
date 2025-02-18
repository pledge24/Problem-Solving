#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M; 
int chickenN;
int houseN;
vector<bool> visited;

void dfs(vector<vector<int>>& cdMatrix, int idx, int choiceN, int& ans){
    // calc minDist
    if(choiceN == M){   
        vector<int> minDistList(houseN, INT32_MAX);
        for(int i = 0; i < chickenN; i++){
            if(visited[i]){
                for(int j = 0; j < houseN; j++)
                    minDistList[j] = min(minDistList[j], cdMatrix[i][j]);
            }
        }
                
        int sum = accumulate(minDistList.begin(), minDistList.end(), 0);
        ans = min(ans, sum);

        return;
    }

    // dfs
    for(int i = idx+1; i < chickenN; i++){
        visited[i] = true;
        dfs(cdMatrix, i, choiceN+1, ans);
        visited[i] = false;
    }

    return;
}

int main(void){
    fastio;

    cin >> N >> M;
    vector<pair<int, int>> chickenPos;
    vector<pair<int, int>> housePos;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num; cin >> num;
            if(num == 1) housePos.push_back({i, j});
            else if(num == 2) chickenPos.push_back({i, j});
        }
    }

    chickenN = chickenPos.size();
    houseN = housePos.size();

    // 집에서 각 치킨집까지의 거리를 저장.
    vector<vector<int>> cdMatrix;
    for(auto p1 : chickenPos){
        vector<int> distList;
        for(auto p2 : housePos){
            int dist = abs(p1.first - p2.first) + abs(p1.second - p2.second);
            distList.push_back(dist);
        }
        cdMatrix.push_back(distList);
    }

    // 각 집에서의 최소 치킨 거리 세팅
    int ans = INT32_MAX;
    visited.resize(chickenN);
    for(int i = 0; i < chickenN; i++){
        visited[i] = true;
        dfs(cdMatrix, i, 1, ans);
        visited[i] = false;
    }
    
    cout << ans << '\n';

    return 0;
}