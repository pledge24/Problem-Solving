#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Board = vector<vector<int>>;

int N, M;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

class Dice{
public:
    Dice(int x, int y) { 
        pos = make_pair(x, y);
        cellNum.resize(6+1);
        rowSequence = {4, 1, 3, 6}; // left, on, right, under
        colSequence = {2, 1, 5, 6}; // up, on, down, under        
    }

    bool tryMove(Board& board, int dir){
        int nx = pos.first + dx[dir];
        int ny = pos.second + dy[dir];

        if(!inRange(nx, ny)){
            return false;
        }

        // curPos 갱신
        setPos(nx, ny);

        // move dice
        switch (dir)
        {
        case Direction::RIGHT:
            // CW roatation
            rowSequence.push_front(rowSequence.back());
            rowSequence.pop_back();
            colSequence[1] = rowSequence[1];
            colSequence[3] = rowSequence[3];
            break;
        case Direction::LEFT:
            rowSequence.push_back(rowSequence.front());
            rowSequence.pop_front();
            colSequence[1] = rowSequence[1];
            colSequence[3] = rowSequence[3];
            break;
        case Direction::DOWN:
            colSequence.push_front(colSequence.back());
            colSequence.pop_back();
            rowSequence[1] = colSequence[1];
            rowSequence[3] = colSequence[3];
            break;
        case Direction::UP:
            colSequence.push_back(colSequence.front());
            colSequence.pop_front();
            rowSequence[1] = colSequence[1];
            rowSequence[3] = colSequence[3];
            break;
        default:
            break;
        }

        int underIdx = rowSequence.back();
        // update board or dice num;
        if(board[nx][ny] == 0)
            board[nx][ny] = cellNum[underIdx];
        else{
            cellNum[underIdx] = board[nx][ny];
            board[nx][ny] = 0;
        }

        return true;
    }

    int getOnNum() { 
        int onIdx = rowSequence[1];
        return cellNum[onIdx]; 
    }

    /* pos getter-setter */
    pair<int, int> getPos() { return pos; }
    void setPos(int x, int y){ pos = make_pair(x, y);}

private:
    int curOnIdx = 1; // 윗면 idx
    pair<int, int> pos;
    deque<int> rowSequence; // No, num
    deque<int> colSequence;
    vector<int> cellNum;
    enum Direction {NONE, RIGHT, LEFT, UP, DOWN};
};

int simulate(Board& board, Dice& dice, int dir){
     
    if(!dice.tryMove(board, dir)){
        return -1;
    }
     
    return dice.getOnNum();
}

int main(void){
    fastio;
    int startX, startY, K;
    cin >> N >> M >> startX >> startY >> K;

    Board board(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    Dice dice(startX, startY);
    for(int i = 0; i < K; i++){
        int dir; cin >> dir;
        int onNum = simulate(board, dice, dir);
        if(onNum != -1)
            cout << onNum << '\n';
    }

    return 0;
}