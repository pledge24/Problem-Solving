// N*N 지도가 제공됨.
// 길이가 L인 경사로가 무한히 있음.
// 길은 한 행 또는 한 열의 끝에서 끝까지 이동.
// 경사로를 두어서 만들 수 있는 길의 개수?
// 경사로 조건
// 1. 경사로 밑에 땅이 다 접해있어야한다.
// 2. 경사로 높이는 1칸이다.
// 3. 경사로를 겹쳐서 놓을 수 없다.

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

using Matrix = vector<vector<int>>;

bool canPass(vector<int>& path, int L){

    int desired = -1;
    int leftL = 0;
    int streak = 1;
    for(int i = 1; i < path.size(); i++){

        // 높이 차가 2이상인 경우.
        if(abs(path[i-1]-path[i]) >= 2)
            return false;

        // 요구하는 높이가 아닌 경우.
        if(desired > 0 && desired != path[i])
            return false;

        // leftL이 남아있다면, 경사로 배치가 보장되어야한다.
        if(leftL > 0){
            // 보장이 안 된 경우.
            if(desired != path[i])
                return false;
            
            leftL--;

            if(leftL == 0){
                streak = 0;
                desired = -1;
            }
            
            continue;
        }

        // ===예약된 경사로 배치가 없는 경우 진입===

        // 1) 이전 높이랑 같은 경우
        if(path[i-1] == path[i]){ 
            streak++;
        }
        // 2) 이전 높이가 낮은 경우(오르막길 발생)
        else if(path[i-1] < path[i]){ 
            if(streak < L)
                return false;
                
            streak = 1;
            continue;
        }
        // 3) 이전 높이가 높은 경우(내리막길 발생)
        else{ 
            leftL = L-1;
            desired = path[i];

            if(leftL == 0){
                streak = 0;
                desired = -1;
            }
        }

    }

    // 경사로를 전부 배치하기 전에 길이 끝난 경우.
    if(leftL > 0)
        return false;

    return true;
}

int main(void){
    fastio;
    int N, L; cin >> N >> L;

    Matrix matrix(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    int ans = 0;

    // rows
    for(int i = 0; i < N; i++){
        vector<int>& path = matrix[i];
        if(canPass(path, L)){
            ans++;
            // cout << "Pass row Idx: " << i << '\n';
        }
    }

    // cols
    for(int i = 0; i < N; i++){
        vector<int> path;
        for(int j = 0; j < N; j++){
            path.push_back(matrix[j][i]);
        }
        if(canPass(path, L)){
            ans++;
            // cout << "Pass col Idx: " << i << '\n';
        }
    }

    cout << ans << '\n';

    return 0;
}