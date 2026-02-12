#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N; 

bool inRange(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

pair<int, int> addPair(pair<int, int>& p1,  pair<int, int>& p2){
    return make_pair(p1.first+p2.first, p1.second+p2.second);
}

bool canMove(vector<vector<int>> &matrix, pair<int, int>& p1,  pair<int, int>& p2){

    bool isDiagnose = p1.first != p2.first && p1.second != p2.second;

    vector<pair<int, int>> v1 = {p1, p2};
    if(isDiagnose){
        v1.push_back(make_pair(p1.first, p2.second));
        v1.push_back(make_pair(p2.first, p1.second));
    }
        
    for(pair<int, int> tempP : v1){
        int nx = tempP.first;
        int ny = tempP.second;

        if(/*범위 넘음*/!inRange(nx, ny) || /*벽*/matrix[nx][ny] == 1){
            return false;
        }
    }

    return true;
}

void bfs(vector<vector<int>> &matrix, int &cnt){

    if(N == 1)
        return;
        
    enum ROT_TYPE { NONE=0, ROW, COL, DIA};

    struct posData{
        pair<int, int> pos1;        // smallPos (왼쪽 위 기준)
        pair<int, int> pos2;        // bigPos
        ROT_TYPE type;
        ROT_TYPE nextType = NONE;
    };

    vector<vector<posData>> offset = {
        // NONE
        {

        },
        // ROW Move
        {
        {make_pair(0, 1), make_pair(0, 1), ROW, ROW},
        {make_pair(0, 1), make_pair(1, 1), ROW, DIA},
        },
        {
        // COL Move
        {make_pair(1, 0), make_pair(1, 0), COL, COL},
        {make_pair(1, 0), make_pair(1, 1), COL, DIA},
        },
        {
        // DIA Move
        {make_pair(1, 1), make_pair(0, 1), DIA, ROW},
        {make_pair(1, 1), make_pair(1, 0), DIA, COL},
        {make_pair(1, 1), make_pair(1, 1), DIA, DIA}
        }
    };

    queue<posData> q;
    q.push({
        make_pair(1, 1),
        make_pair(1, 2),
        ROW
    });

    pair<int, int> goal = {N, N};
    while(!q.empty()){
        posData curPos = q.front(); q.pop();

        int type = (int)curPos.type;
        for(int i = 0; i < offset[type].size(); i++){

            pair<int, int> Xpos1 = addPair(curPos.pos1, offset[type][i].pos1);
            pair<int, int> Xpos2 = addPair(curPos.pos2, offset[type][i].pos2);

            if(canMove(matrix, Xpos1, Xpos2)){
                if(goal == Xpos1 || goal == Xpos2){
                    // cout << Xpos1.first << " " << Xpos1.second << '\n';
                    // cout << Xpos2.first << " " << Xpos2.second << '\n';
                    // cout << '\n';
                    cnt++;
                }
                else
                    q.push({Xpos1, Xpos2, offset[type][i].nextType});
            }
        }

    }
}

int main(void){
    fastio;
    cin >> N;
    vector<vector<int>> matrix(N+1, vector<int>(N+1));

    // input Data;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    bfs(matrix, ans);

    cout << ans << '\n';


    return 0;
}