#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M; 
vector<int> v1, curState;

// v1: 검색 공간을 담고있는 상태공간트리
// curState: 현재 상태

void dfs(int size, int M){

    if(size > 0 && curState[size-1] == 0) return;

    // 종료 조건
    if(size == M){
        for(int elem : curState){
            cout << elem << ' ';
        }
        cout << '\n';

        return;
    }

    for(int i = 0; i < N; i++){   
        curState[size] = v1[i];

        v1[i] = 0;
        dfs(size+1, M);
        v1[i] = curState[size];
    }
    
    return;
}

int main() {
	fastio;
    
    cin >> N >> M;

    v1.resize(N); curState.resize(M);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    dfs(0, M);
}
