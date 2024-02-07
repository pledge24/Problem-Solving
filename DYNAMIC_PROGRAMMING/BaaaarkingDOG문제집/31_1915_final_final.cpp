#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 3

int dx[DIR] {0, 1, 1};
int dy[DIR] {1, 1, 0};

using namespace std;

int N, M;
vector<vector<int>> matrix;

bool isChange = false;

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
        }
    }
    // print test.
    // print_matrix();

    int square_len = matrix[0][0];
    for(int i = 0; i < N; i++){       
        for(int j = 0; j < M; j++){ 
            
            if(i > 0 && j > 0 && matrix[i][j]){
                matrix[i][j] = min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;             
            }
            
            square_len = max(square_len, matrix[i][j]);
        }
    }
          
    //cout << "square_len: " << square_len << '\n';
    //cout << "cnt: " << cnt << '\n';
    //print_matrix();
   
    int ans = square_len * square_len;

    cout << ans << '\n';

 

}