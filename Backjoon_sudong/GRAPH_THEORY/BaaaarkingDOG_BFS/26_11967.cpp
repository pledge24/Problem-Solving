#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

struct pos_data
{
    int x;
    int y;
};

struct room_data
{
    bool visited = false;
    bool light_on = false;
    vector<pos_data> switches;
};

int N, M;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
vector<vector<room_data>> matrix;

bool inRange(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

void print_visited_data(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << matrix[i][j].visited << ' ';
        }
        cout << '\n';
    }
}
void bfs(){
    
    int room_cnt = 1;
    
    queue<pos_data> light_on_rooms;
    matrix[1][1].visited = true;
    matrix[1][1].light_on = true;

    // (1, 1)에 있는 스위치 켜기.
    for(pos_data pd : matrix[1][1].switches){
        if(!matrix[pd.x][pd.y].light_on){
            matrix[pd.x][pd.y].light_on = true;
            room_cnt++;
            light_on_rooms.push({pd.x, pd.y});
        }
        
    }

    while(!light_on_rooms.empty()){

        pos_data cur_pos = light_on_rooms.front(); light_on_rooms.pop();

        
        for(int i = 0; i < DIR; i++){
            int nx = cur_pos.x + dx[i]; 
            int ny = cur_pos.y + dy[i]; 

            // 인접한 방이 방문한 방이라면, 해당 조건문 진입.
            if(inRange(nx, ny) && matrix[nx][ny].visited){

                
                // 또다른 BFS 실행: 해당 위치에 연결된 모든 방문하지 않는 불켜진 방을 방문 및 스위치 켜기.
                queue<pos_data> q_way;
                q_way.push({nx, ny});
                while(!q_way.empty()){
                    
                    pos_data way_pos = q_way.front(); q_way.pop();

                    for(int j = 0; j < DIR; j++){
                        int nx_way = way_pos.x + dx[j]; 
                        int ny_way = way_pos.y + dy[j];

                        // 해당 위치가 방문하지 않은 불켜진 방이라면, 방문하고 스위치를 켠다.
                        if(inRange(nx_way, ny_way) && matrix[nx_way][ny_way].light_on && !matrix[nx_way][ny_way].visited){
                            
                            // (nx_way, ny_way) 방문 처리.
                            matrix[nx_way][ny_way].visited = true;

                            // (nx_way, ny_way)에 있는 스위치 켜기.
                            for(pos_data pd : matrix[nx_way][ny_way].switches){
        
                                if(!matrix[pd.x][pd.y].light_on){
                                    matrix[pd.x][pd.y].light_on = true;
                                    room_cnt++;
                                    light_on_rooms.push({pd.x, pd.y});
                                }                                
                                // light_on_rooms.push({pd.x, pd.y});
                            }
                            q_way.push({nx_way, ny_way});
                        }
                    }
                }

            }
        }
    }

    cout << room_cnt << '\n';

    //print_visited_data();
}

int main() {
	fastio;
    cin >> N >> M;
    matrix.resize(N+1, vector<room_data>(N+1));

    int x1, y1, x2, y2;
    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        matrix[x1][y1].switches.push_back({x2, y2});
    }
    
    bfs();
}