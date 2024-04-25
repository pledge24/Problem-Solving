#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix;
vector<int> ans;

struct pos_data{
    int x;
    int y;
};

void print_matrix(){
    if(matrix.size() > 10) return;
    
    for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix[0].size(); j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void rotateSquare(int x1, int y1, int x2, int y2){
    int w = y2 - y1 + 1;
    int h = x2 - x1 + 1;
    
    bool isMonoRow = false;
    bool isMonoCol = false;
    if(w == 1 && h == 1) return;
    if(w == 1) isMonoCol = true;
    if(h == 1) isMonoRow = true;
    
    vector<pos_data> v1_pos;
    vector<int> v1;
    
    int x = x1; int y = y1;
    if(isMonoRow){
        for(int i = 0; i < w; i++){
            v1_pos.push_back({x, y});
            v1.push_back(matrix[x][y]);
            y++;
        } 
    }
    if(isMonoCol){
        for(int i = 0; i < h; i++){
            v1_pos.push_back({x, y});
            v1.push_back(matrix[x][y]);
            x++;
        } 
    }
    
    if(!isMonoRow && !isMonoCol){
        // right.
        for(int i = 0; i < w-1; i++){
            v1_pos.push_back({x, y});
            v1.push_back(matrix[x][y]);
            y++;
        } 
           
        // down.
        for(int i = 0; i < h-1; i++){
            v1_pos.push_back({x, y});
            v1.push_back(matrix[x][y]);
            x++;
        } 
        
        // left.  
        for(int i = 0; i < w-1; i++){
            v1_pos.push_back({x, y});
            v1.push_back(matrix[x][y]);
            y--;
        } 
        // up.
        for(int i = 0; i < h-1; i++){
            v1_pos.push_back({x, y});
            v1.push_back(matrix[x][y]);
            x--;
        } 
    }
    
    
    // if(w < 10){
    //     for(int elem : v1){
    //         cout << elem << ' ';
    //     }
    //     cout << '\n';
    // }
    
    
    vector<int> min_v;
    for(int i = 0; i < v1.size(); i++){
        
        int next_i = (i+1) % v1.size();
        int nx = v1_pos[next_i].x;
        int ny = v1_pos[next_i].y;
               
        if(v1[i] != v1[next_i]){
            min_v.push_back(v1[i]);        
        }
        
        matrix[nx][ny] = v1[i];
    }
    
    //cout << "min_num is " << min_num << '\n';
    ans.push_back(*min_element(min_v.begin(), min_v.end()));
    
    //print_matrix();
    
    return;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    matrix.resize(rows+1, vector<int>(columns+1));
    
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            matrix[i][j] = (i-1)*columns + j;
            //cout << matrix[i][j] << ' ';
        }
        //cout << '\n';
    }
    
    int x1, y1, x2, y2;
    for(vector<int> mono_q : queries){
        x1 = mono_q[0], y1 = mono_q[1];
        x2 = mono_q[2], y2 = mono_q[3];
        
        rotateSquare(x1, y1, x2, y2);
    }
        
    answer = ans;
    
    return answer;
}