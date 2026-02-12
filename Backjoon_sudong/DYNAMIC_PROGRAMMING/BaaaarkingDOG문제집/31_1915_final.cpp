#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 3

int dx[DIR] {0, 1, 1};
int dy[DIR] {1, 1, 0};

using namespace std;

int N, M;
vector<vector<int>> matrix;

bool isChange = false;

// bool inRange(int r, int c){
//     return 0 <= r && r < N && 0 <= c && c < M;
// }

void find_next_square(int r, int c, int square_len){
    bool find = true;

    for(int i = 0; i < DIR; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];
        
        find = find && (matrix[nx][ny] >= square_len);
    }

    if(find){
        matrix[r][c] = square_len + 1;  
        isChange = true;     
    }

    return;
}

void print_matrix(){

     for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
           cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}

int main() {
	fastio;
    cin >> N >> M;

    matrix.resize(N, vector<int>(M));

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

    while(isChange){
        
        isChange = false;
 
        int cnt = 0;
        for(int i = 0; i < N - square_len; i++){
            for(int j = 0; j < M - square_len; j++){    
                cnt++;              
                if(matrix[i][j] == square_len){                   
                    find_next_square(i, j, square_len);
                    //cnt++;
                }
            }
        }
            
        if(isChange) square_len++;

        //cout << "square_len: " << square_len << '\n';
        cout << "cnt: " << cnt << '\n';
        print_matrix();

    }
    
    int ans = square_len * square_len;

    cout << ans << '\n';

    long long cccnnnttt = 0;
    for(int i = 1; i <= 999; i++){
        cccnnnttt += i*i;
    }

    string cnt_str = to_string(cccnnnttt);
    for(int i = 0; i < cnt_str.length(); i++){
        cout << cnt_str[i];
        if(cnt_str.length() % 3 == (i + 1) % 3) cout << ",";
    }
    cout << '\n';
    cout << "cccnnnttt: " << cccnnnttt << '\n';

}