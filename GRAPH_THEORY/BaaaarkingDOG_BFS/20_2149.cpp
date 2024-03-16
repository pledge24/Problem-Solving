#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

#define GROUND 1
#define SEA 0

# define MAXCNT 10001

using namespace std;

struct pos_data
{
    int island_no;
    int move_cnt;
    bool visited;
};

int N;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

vector<vector<int>> matrix;
vector<vector<pos_data>> bridge_matrix;

queue<pair<int, int>> bridge_queue;

bool alreadyConneted = false;

bool inRange(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < N;
}

bool isConnect(int cur_r, int cur_c, int nx, int ny){
    return bridge_matrix[cur_r][cur_c].island_no != bridge_matrix[nx][ny].island_no;
}

// 해당 함수에 진입 조건: 다리의 길이 2이상.
// 다리의 최소 길이를 반환한다.
int get_min_len_bridge(){
    while(!bridge_queue.empty()){

        queue<pair<int, int>> bridge_queue_temp;

        int cnt = MAXCNT;

        while(!bridge_queue.empty()){
            pair<int, int> p = bridge_queue.front();
            bridge_queue.pop();

            int cur_r = p.first;
            int cur_c = p.second;

            for(int i = 0; i < DIR; i++){
                int nx = cur_r + dx[i];
                int ny = cur_c + dy[i];

                if(inRange(nx, ny)){
                    // 다음 위치가 바다인 경우:
                    // 방문 하지 않았을 경우: {이동해온 섬 번호, 이동한 횟수, 방문 상태: 함}으로 해당 위치에 저장.
                    // 방문을 이미 한 경우: 해당 위치가 다른 섬에서 온 엣지인지 확인 후 맞다면 정답을 반환한다. 
                    if(matrix[nx][ny] == SEA){
                        if(!bridge_matrix[nx][ny].visited){         
                            bridge_matrix[nx][ny] = {bridge_matrix[cur_r][cur_c].island_no, bridge_matrix[cur_r][cur_c].move_cnt+1, true};
                            bridge_queue_temp.push(make_pair(nx, ny));
                        }
                        else{
                            if(isConnect(cur_r, cur_c, nx, ny)){
                                cnt = min(cnt, bridge_matrix[cur_r][cur_c].move_cnt + bridge_matrix[nx][ny].move_cnt);
                            }
                        }
                        
                    }
                    

                }
            }
        }

        // 연결되기 전 상황은 1칸 또는 2칸 남았을 때만 존재한다. 
        if(cnt != MAXCNT){
            return cnt;
        }

        bridge_queue = bridge_queue_temp;
        
    }

    return -1;
}

// 해당 위치에 존재하는 섬의 모든 영토에 섬 번호를 매기고, 섬의 엣지를 큐에 입력한다.
void bfs(int i, int j, int island_no){
    queue<pair<int,int>> q;

    q.push(make_pair(i, j));
    bridge_matrix[i][j] = {island_no, 0, true};

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        int cur_r = p.first;
        int cur_c = p.second;

        for(int i = 0; i < DIR; i++){
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];

            if(inRange(nx, ny)){
                if(matrix[nx][ny] == GROUND && !bridge_matrix[nx][ny].visited){
                    q.push(make_pair(nx, ny));
                    bridge_matrix[nx][ny] = {island_no, 0, true};
                }
                else if(matrix[nx][ny] == SEA){      

                    // 엣지 생성 도중 섬끼리 연결이 되었다면 다리 연결 상태 변수를 true로 변경하고 bfs를 종료한다.
                    if(bridge_matrix[nx][ny].visited && isConnect(cur_r, cur_c, nx, ny)){
                        alreadyConneted = true;
                        return;
                    }

                    bridge_queue.push(make_pair(nx, ny));
                    bridge_matrix[nx][ny] = {island_no, 1, true};  
                }
            }
        }
    }
}

void get_islands_data(){
    int island_no = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matrix[i][j] == GROUND && !bridge_matrix[i][j].visited){
                bfs(i, j, island_no);
                island_no++;
            }
        }
    }
}

int main() {
	fastio;
    cin >> N;

    matrix.resize(N, vector<int>(N));
    bridge_matrix.resize(N, vector<pos_data>(N));

    int num;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num;
            matrix[i][j] = num;
        }
    }

    // print test.
    // cout << '\n';
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << bridge_matrix[i][j].island_no << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    get_islands_data();

    int ans = alreadyConneted ? 1 : get_min_len_bridge();

    cout << ans << '\n';
   

}