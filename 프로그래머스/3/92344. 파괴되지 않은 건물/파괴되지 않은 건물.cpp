#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size();
    int M = board[0].size();
    
    vector<vector<int>> resBoard(N+1, vector<int>(M+1, 0));
    for(vector<int> s : skill)
    {
        int type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int degree = (type == 1) ? -s[5] : s[5];
        
        resBoard[r1][c1] += degree;
        resBoard[r1][c2+1] -= degree;
        resBoard[r2+1][c1] -= degree;
        resBoard[r2+1][c2+1] += degree;
    }
    
    // 1. 가로 방향 누적합
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            resBoard[i][j] += resBoard[i][j - 1];
        }
    }

    // 2. 세로 방향 누적합
    for (int j = 0; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            resBoard[i][j] += resBoard[i - 1][j];
        }
    }

    // 3. 최종 board와 합산하여 정답 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] + resBoard[i][j] > 0) answer++;
        }
    }
    
    return answer;
}