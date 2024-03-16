#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 6

using namespace std;

int L, R, C;

int dl[DIR] = {-1, 1, 0, 0, 0, 0};
int dr[DIR] = {0, 0, 1, 0, -1, 0};
int dc[DIR] = {0, 0, 0, 1, 0, -1};

bool inRange(int l, int r, int c){
    return 0 <= l && l < L && 0 <= r && r < R && 0 <= c && c < C;
}

void print_test(vector<vector<vector<char>>> &cube){
    for(int l = 0; l < L; l++){
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                cout << cube[l][r][c];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    cout << "-----------------\n";
}

int bfs(int start_l, int start_r, int start_c, vector<vector<vector<char>>> &cube){
    int min_time = 0;

    queue<array<int, 3>> q;

    q.push({start_l, start_r, start_c});
  
    array<int, 3> pos = q.front();

    while(!q.empty()){
       
        queue<array<int, 3>> q_temp;
  
        while(!q.empty()){

            array<int, 3> pos = q.front();
            q.pop();

            int pos_l = pos[0];
            int pos_r = pos[1];
            int pos_c = pos[2];

            for(int i = 0; i < DIR; i++){
                int nl = pos_l + dl[i];
                int nr = pos_r + dr[i];
                int nc = pos_c + dc[i];

                if(inRange(nl, nr, nc)){
                    if(cube[nl][nr][nc] == 'E'){
                        return min_time + 1;
                    }
                    else if(cube[nl][nr][nc] == '.'){
                        //printf("nl: %d, nr: %d, nc: %d\n", nl, nr, nc);

                        cube[nl][nr][nc] = 'S';
                        q_temp.push({nl, nr, nc});
                    }

                }
            }
        }

        q = q_temp;

        min_time++;

        //print_test(cube);
    }

    return -1;
}

void make_building(int L, int R, int C){

    vector<vector<vector<char>>> cube;
    cube.resize(L, vector<vector<char>>(R, vector<char>(C)));
    
    int start_l, start_r, start_c;
    // input data.
    for(int l = 0; l < L; l++){
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                cin >> cube[l][r][c];
                if(cube[l][r][c] == 'S'){
                    start_l = l;
                    start_r = r;
                    start_c = c;
                }
            }
        }
    }

    
    int ans = bfs(start_l, start_r, start_c, cube);
        
    if(ans == -1){
        printf("Trapped!\n");
    }
    else{
        printf("Escaped in %d minute(s).\n", ans);
    }
    // printf랑 cout을 섞어 쓰면 틀린 판정이 될 수도 있다;;
}

int main() {
	fastio;
    cin >> L >> R >> C;

    while(L != 0 && R != 0 && C != 0){
        
        make_building(L, R, C);
      
        cin >> L >> R >> C;
        
    }
    
}