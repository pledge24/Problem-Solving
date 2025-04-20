#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;
using Board = vector<string>;

const int ROWS = 12;
const int COLS = 6;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

void printBoard(Board& board){
    for(const string& row : board){
        cout << row << '\n';
    }
    cout << '\n';
    cout << '\n';
}

bool inRange(int x, int y){
    return 0 <= x && x < ROWS && 0 <= y && y < COLS;
}

bool bfs(Board& board, int r, int c){
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS));

    char curColor = board[r][c];
    vector<pair<int, int>> PosList;
    PosList.push_back(make_pair(r, c));

    // bfs init.
    queue<pair<int, int>> q;   
    q.push(make_pair(r, c));
    visited[r][c] = true;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        
        for(int i = 0; i < DIR; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(inRange(nx, ny) && board[nx][ny] == curColor && !visited[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;

                PosList.push_back(make_pair(nx, ny));
            }
        }
    }

    if(PosList.size() >= 4){
        for(pair<int, int> pos : PosList){
            board[pos.first][pos.second] = '.';
        }

        return true;
    }


    return false;
}

bool tryRemove(Board& board){
    bool isDisappear = false;

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(board[i][j] != '.'){
                isDisappear |= bfs(board, i, j);
            }
        }
    }

    return isDisappear; 
}

void applyGravity(Board& board){
    for(int col = 0; col < COLS; col++){
        vector<char> sequence;
        for(int row = 0; row < ROWS; row++){
            if(board[row][col] != '.'){
                sequence.push_back(board[row][col]);
            }
            board[row][col] = '.'; // each block clear
        }

        // each col apply gravity
        int offset = ROWS - sequence.size();
        for(int i = 0; i < sequence.size(); i++){
            board[i + offset][col] = sequence[i];
        }
    }

    // printBoard(board);
}

int simulate(Board& board){
    int cnt = 0;

    while(tryRemove(board)){
        // cout << "=======Remove Complete=========\n";
        // printBoard(board);
        cnt++;
        applyGravity(board);

        // cout << "=======apply Gravity=========\n";
        // printBoard(board);
    }

    return cnt;
}

int main(void){
    fastio;

    // input Board
    Board board(ROWS);
    for(int i = 0; i < ROWS; i++){
        cin >> board[i];
    }

    int ans = simulate(board);

    cout << ans << '\n';
    

    return 0;
}