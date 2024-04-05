#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N, M; cin >> N >> M;

    vector<vector<int>> matrix(N+1, vector<int>(N+1));
    
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            cin >> matrix[r][c];
        }
    }

    // 1 X 1, 1 X 2 ... 1 X N 크기의 직사각형 크기 저장.
    vector<vector<int>> matrix_accu(N+1, vector<int>(N+1));
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            int accu_num = c-1 > 0 ? matrix_accu[r][c-1] : 0;
            matrix_accu[r][c] = matrix[r][c] + accu_num; 
        }
    }

    // n X 1, n X 2, ... n X N 크기의 직사각형 크기 저장.
    for(int r=2; r<=N; r++){
        for(int c=1; c<=N; c++){         
            matrix_accu[r][c] += matrix_accu[r-1][c];
        }
    }

    // print test (matrix).
    // cout << '\n';
    // for(int r=1; r<=N; r++){
    //     for(int c=1; c<=N; c++){
    //         cout << matrix[r][c] << ' ';
    //     }
    //     cout << '\n';
    // }

    // // print test (matrix_accu).
    // cout << '\n';
    // for(int r=1; r<=N; r++){
    //     for(int c=1; c<=N; c++){
    //         cout << matrix_accu[r][c] << ' ';
    //     }
    //     cout << '\n';
    // }


    int r1, c1, r2, c2;
    for(int i = 0; i < M; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        // ans = 큰 정사각형 - (위로 길쭉 직사각형 + 옆으로 길쭉 직사각형 - 중복 직사각형)

        int ans = matrix_accu[r2][c2] - (matrix_accu[r2][c1-1] + matrix_accu[r1-1][c2] - matrix_accu[r1-1][c1-1]);
        
        cout << ans << '\n';
    }
}