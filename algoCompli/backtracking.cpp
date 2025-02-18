#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;              
vector<int> v1;         // v1: 검색 공간을 담고있는 상태공간트리
vector<int> curState;   // curState: 현재 상태

void backtracking(int size, int M){

    // 종료 조건
    if(size == M){
        for(int elem : curState){
            cout << elem << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++){
        if(v1[i] != 0){			        // 해당 노드가 유망한지 판단(isPromising())
            curState[size] = v1[i];

            v1[i] = 0;		 	        // 해당 숫자를 선택했다는 의미로 0 대입
            backtracking(size+1, M); 	// 다음 상태 노드로 이동	
            v1[i] = curState[size];	    // 해당 숫자를 선택하기 전으로 백트래킹
        }

    }
}

int main() {
	fastio;
    
    cin >> N >> M;

    v1.resize(N); curState.resize(M);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    backtracking(0, M);
}
