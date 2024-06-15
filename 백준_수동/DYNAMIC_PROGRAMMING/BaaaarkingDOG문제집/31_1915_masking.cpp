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

void print_matrix(){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
           cout << matrix_temp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}

// mask 순회
bool find_square(int i, int j, int mask_size){
    for(int tmp_i = i; tmp_i < i + mask_size; tmp_i++){
        for(int tmp_j = j; tmp_j < j + mask_size; tmp_j++){
            if(!matrix[tmp_i][tmp_j]){
                return false;  
            }          
        }              
    }


    return true;
}

bool mask_searching(int mask_size){
    bool pass;
    for(int i = 0; i < N - mask_size + 1; i++){
            for(int j = 0; j < M - mask_size + 1; j++){    
                // mask 순회  
                //cout << "mask_size (r, c): " << mask_size << " " << i << " " << j << '\n';
                if(!matrix_temp[i][j]) continue;

                pass = find_square(i, j, mask_size);   
                
                if(pass) return true;
                else{
                    matrix_temp[i][j] = 0;
                }
            }
       
    }

    return false;

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

    matrix_temp = matrix;

    // print_matrix();

    int mask_size = 0;
    while(1){
        
        //cout << "mask_size: " << mask_size+1 << '\n';
        if(mask_searching(mask_size+1)){
            mask_size++;
        }
        else{
            break;
        }
        
        // print_matrix();
    }
   
    int ans = mask_size * mask_size;

    cout << ans << '\n';
}