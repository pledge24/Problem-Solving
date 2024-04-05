#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int N, M;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int r, int c){
    return 0 <= r && r < M && 0 <= c && c < N;
}

void print_test(vector<vector<char>> matrix){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int bfs(vector<vector<char>> matrix, queue<pair<int, int>> J_pos, queue<pair<int, int>> F_pos){
       
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

                if(inRange(nx, ny) && (matrix[nx][ny] == '@' || matrix[nx][ny] == '.')){
                    //printf("nx: %d, ny: %d\n", nx, ny);

                    matrix[nx][ny] = '*';   
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
                    
                    matrix[nx][ny] = '@';
                    J_pos_temp.push(make_pair(nx, ny));
                    
                }

                
            }
        }

        J_pos = J_pos_temp;


        min_time++;

        //print_test(matrix);
    }
    

    return -1;
}

int main() {
	fastio;
    int T; cin >> T;

    for(int t = 0 ; t < T; t++){
   
        cin >> N >> M;

        vector<vector<char>> matrix(M, vector<char>(N));
        queue<pair<int, int>> J_pos;
        queue<pair<int, int>> F_pos;

        // input data.
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cin >> matrix[i][j];        
                switch (matrix[i][j])
                {
                case '*':
                    F_pos.push(make_pair(i, j));
                    break;
                case '@':
                    //printf("(%d, %d)\n", i, j);
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


        int ans = bfs(matrix, J_pos, F_pos);
            
        if(ans == -1){
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << ans << '\n';
        }
    }
}