#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 8

using namespace std;

int N, M;
vector<vector<int>> matrix;
vector<vector<int>> matrix_temp;

bool inRange(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
}

int find_next_square(int r, int c, int square_len){
    int cnt = 0;
    int offset = square_len/2;

    bool dir[DIR + 1];

    dir[1] = inRange(r - offset, c - offset) && matrix[r - offset][c - offset];       // 왼쪽 위
    dir[3] = inRange(r - offset, c + offset) && matrix[r - offset][c + offset];      // 오른쪽 위
    dir[5] = inRange(r + offset, c + offset) && matrix[r + offset][c + offset];      // 오른쪽 아래
    dir[7] = inRange(r + offset, c - offset) && matrix[r + offset][c - offset];      // 오른쪽 위

    // 위
    dir[2] = true;
    for(int tmp_c = c-offset+1; tmp_c < c+offset; tmp_c++){
        if(!inRange(r-offset, tmp_c) || !matrix[r-offset][tmp_c]){
            dir[2] = false;
            break;
        }
    }

    // 오른쪽
    dir[4] = true;
    for(int tmp_r = r-offset+1; tmp_r < r+offset; tmp_r++){
        if(!inRange(tmp_r, c+offset) || !matrix[tmp_r][c+offset]){
            dir[4] = false;
            break;
        }
    }

    // 아래
    dir[6] = true;
    for(int tmp_c = c-offset+1; tmp_c < c+offset; tmp_c++){
        if(!inRange(r+offset, tmp_c) || !matrix[r+offset][tmp_c]){
            dir[6] = false;
            break;
        }
    }

    // 왼쪽
    dir[8] = true;
    for(int tmp_r = r-offset+1; tmp_r < r+offset; tmp_r++){
        if(!inRange(tmp_r, c-offset) || !matrix[tmp_r][c-offset]){
            dir[8] = false;
            break;
        }
    }
    
    if(dir[2] && dir[3] && dir[4]) cnt++;
    if(dir[4] && dir[5] && dir[6]) cnt++;
    if(dir[6] && dir[7] && dir[8]) cnt++;
    if(dir[8] && dir[1] && dir[2]) cnt++;

    return cnt;
}

void print_matrix(){

     for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
           cout << matrix_temp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}

int main() {
	fastio;
    cin >> N >> M;

    matrix.resize(N, vector<int>(M));

    bool isChange = false;
    string num_str;
    // input data.
    for(int i = 0; i < N; i++){
        cin >> num_str;
        for(int j = 0; j < M; j++){         
            matrix[i][j] = num_str[j] - '0';
            if(num_str[j] - '0') {
                isChange = true;
            }
        }
    }
    // print test.
    // print_matrix();

    int square_len = isChange ? 1 : 0;

    matrix_temp = matrix;
    while(isChange){
        
        isChange = false;

        if(square_len % 2 == 1){                // 짝수 길이 구할 때
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){                  
                    if(matrix_temp[i][j] > 0){
                        matrix_temp[i][j] = find_next_square(i, j, square_len+1);

                        if(matrix_temp[i][j] > 0){
                            isChange = true;
                        }
                    }
                }
            }
        }
        else{                                   // 홀수 길이 구할 때
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(matrix_temp[i][j] == 4){
                        matrix_temp[i][j] = 1;
                        isChange = true;
                    }
                    else{
                        matrix_temp[i][j] = 0;
                    }
                }
            }
        }

        //matrix = matrix_temp;

        if(isChange) square_len++;

        //cout << "square_len: " << square_len << '\n';
        
        //print_matrix();

    }
    
    int ans = square_len * square_len;

    cout << ans << '\n';
}