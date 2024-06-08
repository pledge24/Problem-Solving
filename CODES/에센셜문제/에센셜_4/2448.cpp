#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<vector<char>> cur_triangle = {   {' ', ' ', '*', ' ', ' '},
                                        {' ', '*', ' ', '*', ' '},
                                        {'*', '*', '*', '*', '*'},
                                    };

void input_triangle(vector<vector<char>> &next_triangle, int offset_x, int offset_y){
    int cur_r_size = cur_triangle.size();
    int cur_c_size = cur_triangle[0].size();

    // cout << "offset_x : " << offset_x << " offset_y : " << offset_y << '\n';
    // cout << "r : " << next_triangle.size() << " c : " << next_triangle[0].size() << '\n';
    for(int x = 0; x < cur_r_size; x++){
        for(int y = 0; y < cur_c_size; y++){
            next_triangle[offset_x + x][offset_y + y] = cur_triangle[x][y];
        }
    }
}

int main() {
	fastio;
    int N; cin >> N;
    int level = log2(N / 3);
   
    // cout << level << '\n';
    int rows = 3, cols = 5;
    for(int cur_level = 1; cur_level <= level; cur_level++){
        rows *= 2;
        cols = cols*2 + 1;

        vector<vector<char>> next_triangle(rows, vector<char>(cols, ' '));

        input_triangle(next_triangle, 0, cols / 4 + 1);
        input_triangle(next_triangle, rows / 2, 0);
        input_triangle(next_triangle, rows / 2, cols / 2 + 1);
        
        cur_triangle.resize(rows, vector<char>(cols));
        cur_triangle.swap(next_triangle);
    }

    for(vector<char> v : cur_triangle){
        for(char c : v){
            cout << c;
        }
        cout << '\n';
    }
}