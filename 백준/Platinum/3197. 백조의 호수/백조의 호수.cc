#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define SWANS 2

using namespace std;

struct pos_data_3197
{
    int x;
    int y;
};

struct visited_data_3197
{
    bool visited = false;
    bool next_melted = false;
    int swans_no = -1;
};

int R, C; 
vector<vector<char>> matrix;
vector<vector<visited_data_3197>> matrix_visited_data;
queue<pos_data_3197> ice_bergs;
vector<pos_data_3197> swans_pos;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

enum swans_name {first_swan = 0, second_swan = 1};

bool inRange(int r, int c){
    return 0 <= r && r < R && 0 <= c && c < C;
}

void print_matrix(){
    cout << '\n';
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_visited_matrix(){
    cout << '\n';
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << matrix_visited_data[i][j].visited << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool have_path(int days, vector<pos_data_3197> &curr_melting_ice){
    if(days > 0){
        for(pos_data_3197 cur_pos : curr_melting_ice){

            if(matrix_visited_data[cur_pos.x][cur_pos.y].visited) continue;

            for(int i = 0; i < DIR; i++){
                int nx = cur_pos.x + dx[i];
                int ny = cur_pos.y + dy[i];

                // 인접한 칸이 백조가 방문한 칸이라면 해당 백조 번호로 연결된 모든 방을 방문 처리.
                if(inRange(nx, ny) && matrix_visited_data[nx][ny].visited){
                    queue<pos_data_3197> q;
                    q.push({nx, ny});
                    int swan_No = matrix_visited_data[nx][ny].swans_no;

                    while(!q.empty()){
                        pos_data_3197 cur_pos = q.front(); q.pop();

                        for(int i = 0; i < DIR; i++){
                            int nx = cur_pos.x + dx[i];
                            int ny = cur_pos.y + dy[i];
                            
                            if(inRange(nx, ny) && !matrix_visited_data[nx][ny].visited && matrix[nx][ny] != 'X'){
                                matrix_visited_data[nx][ny].visited = true;
                                matrix_visited_data[nx][ny].swans_no = swan_No;
                                
                                q.push({nx, ny});
                            }
                            else if(inRange(nx, ny) && matrix_visited_data[nx][ny].visited && matrix_visited_data[nx][ny].swans_no != swan_No){
                                return true;
                            }
                        }

                    }
                }
            }
        }

    }
    else{       // days = 0 일 때, 처음에 백조가 갈 수 있는 모든 칸들을 visted처리한다.
        
        matrix_visited_data[swans_pos[first_swan].x][swans_pos[first_swan].y] = {true, false, first_swan};
        matrix_visited_data[swans_pos[second_swan].x][swans_pos[second_swan].y] = {true, false, second_swan};

        // swans(just 2) BFS
        for(int swan_No = first_swan; swan_No < SWANS; swan_No++){
            queue<pos_data_3197> q;
            q.push(swans_pos[swan_No]);

            // 각 백조가 갈 수 있는 모든 칸들을 방문.
            while(!q.empty()){
                pos_data_3197 cur_pos = q.front(); q.pop();

                for(int i = 0; i < DIR; i++){
                    int nx = cur_pos.x + dx[i];
                    int ny = cur_pos.y + dy[i];
                    
                    if(inRange(nx, ny) && !matrix_visited_data[nx][ny].visited && matrix[nx][ny] != 'X'){
                        matrix_visited_data[nx][ny] = {true, false, swan_No};
                        q.push({nx, ny});
                    }
                    else if(inRange(nx, ny) && matrix_visited_data[nx][ny].visited && matrix_visited_data[nx][ny].swans_no != swan_No){
                        return true;
                    }
                }

            }
        }
               
    }

    return false;
}

void init_next_melting_icebergs(vector<pos_data_3197> &next_melting_icebergs){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            
            for(int dir = 0; dir < DIR; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(inRange(nx, ny) && matrix[nx][ny] != 'X'){
                    matrix_visited_data[nx][ny].next_melted = true;
                    next_melting_icebergs.push_back({i, j});
                    break;
                }
            }  
        }
    }
}

int solve(){

    vector<pos_data_3197> curr_melting_icebergs;
    vector<pos_data_3197> next_melting_icebergs;

    int days = 0;

    init_next_melting_icebergs(next_melting_icebergs);
 
    while(curr_melting_icebergs.size() > 0 || days == 0){
        
        //print_matrix();
          
        if(have_path(days, curr_melting_icebergs)) return days;
        days++;

        //print_visited_matrix();

        // next데이터를 curr로 옮기고 next vector 비움
        curr_melting_icebergs.swap(next_melting_icebergs);
        next_melting_icebergs.clear();

        // "melt" iceBergs & "get" next_melting_icebergs
        for(pos_data_3197 melting_pos : curr_melting_icebergs){
            matrix[melting_pos.x][melting_pos.y] = '.';  

            for(int i = 0; i < DIR; i++){
                int nx = melting_pos.x + dx[i];
                int ny = melting_pos.y + dy[i];

                if(inRange(nx, ny) && matrix[nx][ny] == 'X' && !matrix_visited_data[nx][ny].next_melted){
                    matrix_visited_data[nx][ny].next_melted = true;
                    next_melting_icebergs.push_back({nx, ny});
                }
            }  
        }

        

    }

    return days;
}

int main() {
	fastio;
    cin >> R >> C;

    matrix.resize(R, vector<char>(C));
    matrix_visited_data.resize(R, vector<visited_data_3197>(C));
   
    char c;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> c;   
            if(c == 'X'){
                ice_bergs.push({i, j});
            } 
            else if(c == 'L'){
                swans_pos.push_back({i, j});
            }
            matrix[i][j] = c;
        }
    }

    int ans = solve();
    cout << ans << '\n';

}