#include <bits/stdc++.h>

#define fastio cin.tie(nullptr)->sync_with_stdio(false)
#define DIR 4

using namespace std;
using Board = vector<vector<int>>;
using Pos = pair<int, int>;
using Cmd = queue<pair<int, char>>;

int N;
// 북 시작 시계방향(CW)
int dx[DIR] = {-1, 0, 1, 0};
int dy[DIR] = {0, 1,  0, -1};

enum class BOARD_DATA {NONE, APPLE, SNAKE_BODY};
enum DIRECTION {UP, RIGHT, DOWN, LEFT};

bool inRange(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

class Snake{
public:
    Snake(int dir, pair<int, int> startPos) : _dir(dir), body({startPos}) {}

    bool TryMove(Board& board){
        Pos HeadPos = body.front();
        int nx = HeadPos.first + dx[_dir];
        int ny = HeadPos.second + dy[_dir];

        // cannot move
        if(!inRange(nx, ny) || board[nx][ny] == (int)BOARD_DATA::SNAKE_BODY/*snake's body*/)
            return false;
        
        // can move: add snake body
        int temp = board[nx][ny];
        board[nx][ny] = (int)BOARD_DATA::SNAKE_BODY;
        body.push_front(make_pair(nx, ny));

        // if not exist apple, remove snake's body.
        if(temp != (int)BOARD_DATA::APPLE){
            Pos tailPos = body.back();
            board[tailPos.first][tailPos.second] = (int)BOARD_DATA::NONE;
            body.pop_back();
        }
        
        return true;
    }
    void changeDirection(char dir){
        // -1 : left rotation, 1 : right rotation
        int offset = dir == 'L' ? -1 : 1;
        _dir = ((_dir + offset) + DIR ) % DIR;
    }

private:
    deque<Pos> body;
    int _dir;
};

void printBoard(Board& board){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void simulate(Board& board, Snake& snake, int& endTime, Cmd& commands){
  
    bool isDead = false;

    while(!isDead){
        pair<int, char> next = !commands.empty() ? commands.front() : make_pair(-1, 'x');

        if(endTime == next.first){
            snake.changeDirection(next.second);
            commands.pop();
        }

        bool succesMove = snake.TryMove(board);
        endTime++;

        if(!succesMove)
            isDead = true;
   
        // printBoard(board);
  
    }



}

int main(void){
    fastio;
    int K; cin >> N >> K;
    Board board(N+1, vector<int>(N+1));

    // board init
    board[1][1] = (int)BOARD_DATA::SNAKE_BODY;

    // input apple Pos
    for(int i = 0; i < K; i++){
        int x, y; cin >> x >> y;
        board[x][y] = (int)BOARD_DATA::APPLE;
    }

    // input commands
    int L; cin >> L;
    Cmd commands;
    for(int i = 0; i < L; i++){
        int t; char dir; cin >> t >> dir;
        commands.push(make_pair(t, dir));
    }

    int endTime = 0;
    Snake snake(RIGHT, make_pair(1, 1));
    
    simulate(board, snake, endTime, commands);

    cout << endTime << '\n';

    return 0;
}