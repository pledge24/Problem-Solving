#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Board = vector<vector<int>>;
using Sticker = vector<vector<int>>;

int N, M;
enum {NONE=0, FILLED};

// void printSticker(Sticker& sticker){
//     for(int i = 0; i < sticker.size(); i++){
//         for(int j = 0; j < sticker[0].size(); j++){
//             cout << sticker[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }

// void printBoard(Board& board){
//     for(int i = 0; i < board.size(); i++){
//         for(int j = 0; j < board[0].size(); j++){
//             cout << board[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }

int countCells(Board& board){
    int cnt = 0;
    for(auto row : board){
        cnt += count(row.begin(), row.end(), 1);
    }

    return cnt;
}

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool Paste(Board& board, Sticker sticker, int offsetR, int offsetC){
    // canPaste?
    for(int i = 0; i < sticker.size(); i++){
        for(int j = 0; j < sticker[0].size(); j++){
            int nx = i + offsetR;
            int ny = j + offsetC;
            if(!inRange(nx, ny) || (board[nx][ny] == FILLED && sticker[i][j] == FILLED))
                return false;
        }
    }

    // realPaste;
    for(int i = 0; i < sticker.size(); i++){
        for(int j = 0; j < sticker[0].size(); j++){
            if(sticker[i][j] == FILLED)
                board[i+offsetR][j+offsetC] = FILLED;
        }
    }
    
    return true;
}   

bool TryPaste(Board& board, Sticker& sticker){
    for(int offsetR = 0; offsetR < board.size(); offsetR++){
        for(int offsetC = 0; offsetC < board[0].size(); offsetC++){
            if(Paste(board, sticker, offsetR, offsetC)){
                return true;
            }
        }
    }
    return false;
}

void rotateSticker(Sticker& sticker/*Only Square Sticker*/, int h, int w){
    Sticker tempSticker(w, vector<int>(h));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            tempSticker[j][h-1-i] = sticker[i][j];
        }
    }

    swap(sticker, tempSticker);
}

void simulate(Board& board, vector<Sticker>& stickers){
    const int rotN = 4;

    for(int i = 0; i < stickers.size(); i++){
        Sticker curSticker = stickers[i];
        int h = curSticker.size();
        int w = curSticker[0].size();

        // 1) 무회전 붙이기 시도
        // 2) 회전 붙이기 시도 (90 -> 180 -> 270 -> 360 순으로)
        for(int r = 0; r < rotN; r++){
            // printSticker(curSticker);

            if(TryPaste(board, curSticker))
                break;

            if(r % 2 == 0) /*0, 180도 회전인 상태*/
                rotateSticker(curSticker, h, w);
            else /*90, 270도 회전인 상태*/
                rotateSticker(curSticker, w, h);

        }

        // printBoard(board);
        
    }
}

int main(void){
    // fastio;
    int K; cin >> N >> M >> K;
    Board board(N, vector<int>(M));
    vector<Sticker> stickers(K);
    for(int i = 0; i < K; i++){
        int r, c; cin >> r >> c;

        // input one sticker.
        Sticker sticker(r, vector<int>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> sticker[i][j];
            }
        }
        stickers[i] = move(sticker);
    }

    simulate(board, stickers);

    int ans = countCells(board);

    cout << ans << '\n';

    return 0;
}