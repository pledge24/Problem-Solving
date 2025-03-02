#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<bool> visited;
vector<bool> prevVisited;

void Backtracking(vector<int>& v1, int& M, int idx/*nextIdx*/, int lastNum, int cnt){
    if(cnt == M){
        if(visited == prevVisited)
            return;

        for(int i = 0; i < v1.size(); i++){
            if(visited[i])
                cout << v1[i] << ' ';
        }
        cout << '\n';

        prevVisited = visited;
        return;
    }

    for(int i = idx; i < v1.size(); i++){
        if(lastNum >= v1[i])
            continue;
        
        visited[i] = true;
        Backtracking(v1, M, i, v1[i], cnt+1);
        visited[i] = false;
    }

    return;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    // input Data.
    vector<int> v1(N);
    visited.resize(N);

    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());

    int startIdx = 0;
    int prevNum = -1;
    int cnt = 0;
    Backtracking(v1, M, startIdx, prevNum, cnt);

    return 0;
}