#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

vector<vector<char>> matrix;

queue<pair<int, int>> J_pos;
queue<pair<int, int>> F_pos;

int N, M;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
}

void print_test(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << matrix[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int bfs(){
       
    int min_time = 0;

    while(!J_pos.empty()){
        // FIRRRRRRRRRRRRR
        queue<pair<int, int>> F_pos_temp;
  
        while(!F_pos.empty()){

            pair<int, int> pos = F_pos.front();
            F_pos.pop();

            int pos_r = pos.first;
            int pos_c = pos.second;

            for(int i = 0; i < DIR; i++){
                int nx = pos_r + dx[i];
                int ny = pos_c + dy[i];

                if(inRange(nx, ny) && (matrix[nx][ny] == 'J' || matrix[nx][ny] == '.')){
                    //printf("nx: %d, ny: %d\n", nx, ny);

                    matrix[nx][ny] = 'F';   
                    F_pos_temp.push(make_pair(nx, ny));
                    
                }
            }
        }

        F_pos = F_pos_temp;

        // CHAR MOVEMENT
        queue<pair<int, int>> J_pos_temp;
  
        while(!J_pos.empty()){

            pair<int, int> pos = J_pos.front();
            J_pos.pop();

            int pos_r = pos.first;
            int pos_c = pos.second;

            for(int i = 0; i < DIR; i++){
                int nx = pos_r + dx[i];
                int ny = pos_c + dy[i];

                //printf("nx: %d, ny: %d\n", nx, ny);

                if(!inRange(nx, ny)){
                    //cout << "check" << '\n';
                    return min_time + 1;
                }
                else if(inRange(nx, ny) && matrix[nx][ny] == '.'){
                    
                    matrix[nx][ny] = 'J';
                    J_pos_temp.push(make_pair(nx, ny));
                    
                }

                
            }
        }

        J_pos = J_pos_temp;


        min_time++;

        //print_test();
    }
    

    return -1;
}

int main() {
	fastio;
    cin >> N >> M;

    matrix.resize(N, vector<char>(M));
   
    // input data.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];

            switch (matrix[i][j])
            {
            case 'F':
                F_pos.push(make_pair(i, j));
                break;
            case 'J':
                J_pos.push(make_pair(i, j));
                break;
            
            }
        }
    }

    // // test print.
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }


    int ans = bfs();
        
    if(ans == -1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << ans << '\n';
    }
}