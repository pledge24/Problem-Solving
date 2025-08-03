#include <bits/stdc++.h>

using namespace std;

// 크레인은 멈춘 열에서 가장 위에 있는 인형을 집을 수 있다.
// (인형은 아래서부터 빈 공간없이 쌓여있다.)
// 같은 종류의 인형을 두 개 연속으로 바구니에 쌓이면 "인형은 사라진다".
// (인형이 없는 열은 크레인을 내려도 아무런 일도 일어나지 않는다.)
// -> 크레인을 모두 작동시켰을 때 사라진 인형의 개수는?

// board: 각 행의 인형의 종류 (인형 id: 1~100)
// board의 크기는 N*N 정사각형 모양
using Col = queue<int>;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int N = board.size();
    vector<Col> cols(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 0)
                continue;
            
            int dollId = board[i][j];
            cols[j].push(dollId);
        }
    }
    
    // DEBUG: print
    // for(int i = 0; i < N; i++){
    //     queue<int> q = cols[i];
    //     while(!q.empty()){
    //         cout << q.front() << ' ';
    //         q.pop();
    //     }
    //     cout << '\n';
    // }
    
    stack<int> bag;
    for(int i = 0; i < moves.size(); i++){
        int colId = moves[i] - 1;
        
        Col& curCol = cols[colId];
        if(curCol.empty())
            continue;
        
        int dollId = curCol.front(); curCol.pop();
        
        // 바구니가 비어있으면 넣기만 하고 다음으로 진행.
        if(bag.empty() == true || bag.top() != dollId){
            bag.push(dollId);
            continue;
        }
        
        bag.pop();
        answer += 2;

    }
    
    return answer;
}