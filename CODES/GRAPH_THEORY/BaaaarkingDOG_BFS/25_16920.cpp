#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

struct pos_data
{
    int x;
    int y;
};

struct player_data
{
    int moveN;
    int castles = 0;
    queue<pos_data> pos_list;
};

vector<player_data> player_data_list;     // first: moveN, second: castles cnt
vector<vector<char>> matrix;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
int N, M, P;
int left_space;

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void print_matrix(){
    for(int i = 0; i < N; i++){  
        for(int j = 0; j < M; j++){
            cout << matrix[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_ans(){
    // Print answer
    for(int i = 1; i <= P; i++){
        cout << player_data_list[i].castles << ' ';
    }
    cout << '\n';
}

void bfs(){
    
    queue<int> player_turns;
    for(int i = 1; i <= P; i++){
        player_turns.push(i);
    }

    // 플레이어 턴 변경용 while문
    while(left_space > 0 && !player_turns.empty()){
        int player_No = player_turns.front(); player_turns.pop();

        // 현재 플레이어의 pos queue
        queue<pos_data>* q = &player_data_list[player_No].pos_list;
        
        int curr_moveN = 0;       
        // 더이상 이동할 수 있는 성이 없거나, 이동 횟수를 초과하는 이동이라면 while문을 나온다.
        while(!q->empty() && curr_moveN < player_data_list[player_No].moveN){
            int curr_q_size = q->size();

            // curr_moveN 만큼 이동한 성들의 확장
            for(int i = 0; i < curr_q_size; i++){
                pos_data cur_pos = q->front(); q->pop();
            
                for(int i = 0; i < DIR; i++){
                    int nx = cur_pos.x + dx[i]; 
                    int ny = cur_pos.y + dy[i]; 

                    if(inRange(nx, ny) && matrix[nx][ny] == '.'){
                        q->push({nx, ny});
                        matrix[nx][ny] = '0' + player_No;
                        player_data_list[player_No].castles++;
                        left_space--;
                    }
                }
            }
            curr_moveN++;
            
            // 더이상 확장을 할 수 없을때 확장 게임 자체를 종료한다.
            if(left_space <= 0) return;
        }

        // 다음 턴이 돌아왔을 때 이동할 위치가 queue에 존재한다면, 해당 플레이어를 player_turns 큐에 추가.
        if(!q->empty()){
            player_turns.push(player_No);
        }
    }  

    return;
}

int main() {
	fastio;
    cin >> N >> M >> P;

    matrix.resize(N, vector<char>(M));
    player_data_list.resize(P+1);
  
    int moveN, castles = 0;
    for(int player_no = 1; player_no <= P; player_no++){
        cin >> moveN;
        player_data_list[player_no].moveN = moveN;
    }
    
    char c;
    for(int i = 0; i < N; i++){  
        for(int j = 0; j < M; j++){
            cin >> c;
            matrix[i][j] = c;

            if(c == '.'){
                left_space++;
            }
            else if(isdigit(c)){ 
                player_data_list[c-'0'].castles++;
                player_data_list[c-'0'].pos_list.push({i, j});              
            }
         
        }
    }

    bfs();
    
    print_ans();
    //print_matrix();

    return 0;
}