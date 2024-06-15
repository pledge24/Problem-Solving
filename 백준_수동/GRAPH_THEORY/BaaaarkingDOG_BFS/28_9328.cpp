#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;


struct pos_data_9328
{
    int x;
    int y;
};

vector<vector<char>> matrix;
map<char, bool> have_key;
map<char, vector<pos_data_9328>> unopened_door;
int h, w;
int ans;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int r, int c){
    return 0 <= r && r < h && 0 <= c && c < w;
}

void func(queue<pos_data_9328>& q, int i, int j){
    switch (matrix[i][j])
    {
    case '*':
        break;
    case '.':
        matrix[i][j] = '*';
        q.push({i, j});
        break;
    case '$':
        ans++;
        matrix[i][j] = '*';
        q.push({i, j});
        break;
    default:        // a~z OR A~Z
        if(islower(matrix[i][j])){      // a~z
            char key_name = matrix[i][j];
            have_key[matrix[i][j]] = true;
            matrix[i][j] = '*';
            q.push({i, j});

            for(pos_data_9328 cur_pos : unopened_door[toupper(key_name)]){
                matrix[cur_pos.x][cur_pos.y] = '*';
                q.push({cur_pos.x, cur_pos.y});
            }
            unopened_door[toupper(key_name)].clear();
        }
        else{                           // A~Z
            char door_name = matrix[i][j];
            if(have_key[tolower(door_name)]){
                matrix[i][j] = '*';
                q.push({i, j});
            }
            else{
                unopened_door[door_name].push_back({i, j});
            }
        }

        break;
    }

    return;
}

void print_matrix(){
    cout << '\n';
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_queue(queue<pos_data_9328> &q){

    while(!q.empty()){
        pos_data_9328 pos = q.front(); q.pop();

        printf("(%d %d), ", pos.x, pos.y);
    }
    
    printf("\n");
}

void bfs(queue<pos_data_9328>& q){

    int test_cnt = 0;
    while(!q.empty()){
        pos_data_9328 cur_pos = q.front(); q.pop();

        for(int i = 0; i < DIR; i++){
            int nx = cur_pos.x + dx[i];
            int ny = cur_pos.y + dy[i];

            if(inRange(nx, ny)){
                func(q, nx, ny);
            }
        }

        //print_matrix();

     
    }

    return;
}

void initialize(){
    matrix.clear();
    matrix.resize(h, vector<char>(w));
    
    have_key.clear();
    unopened_door.clear();

    ans = 0;
}

void solve(){
    cin >> h >> w;
    
    initialize();

    // input matrix data.
    char c;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c;
            matrix[i][j] = c;
        }   
    }

    // input have_key data
    string str;
    cin >> str;
    for(char c : str){
        if(c == '0') break;
        have_key[c] = true;
    }

    // 건물 벽면에서 입구 찾기.
    queue<pos_data_9328> move_q;
    for(int i = 0; i < h; i++){
        if(i == 0 || i == h-1){                 // 벽면: 위, 아래
            for(int j = 0; j < w; j++){
                func(move_q, i, j);
            }  
        }
        else{                                   // 벽면: 오른쪽, 왼쪽
            func(move_q, i, 0);
            func(move_q, i, w-1);
        }
         
    }

    //print_queue(q);
    bfs(move_q);

    cout << ans << '\n';

    return;
}

int main() {
	fastio;
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        solve();      
    }
    
    return 0;
}