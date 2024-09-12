#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}
vector<int> solution(int n) {
    vector<int> answer;
    N = n;
    
    vector<vector<int>> v1;
    v1.resize(n, vector<int>(n));
    
    int pos_x = 0, pos_y = 0;
    v1[0][0] = 1;
    int cnt = 2;
    bool end = false;
    while(!end){
        end = true;
        while(inRange(pos_x+1, pos_y) && !v1[pos_x+1][pos_y]){
            pos_x++;
            v1[pos_x][pos_y] = cnt;
            cnt++;
            end = false;
        }
        
        if(end) break;

        while(inRange(pos_x, pos_y+1) && !v1[pos_x][pos_y+1]){
            pos_y++;
            v1[pos_x][pos_y] = cnt;
            cnt++;
        }

        while(inRange(pos_x-1, pos_y-1) && !v1[pos_x-1][pos_y-1]){
            pos_x--; pos_y--;
            v1[pos_x][pos_y] = cnt;
            cnt++;
        }
    
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            //cout << v1[i][j] << ' ';
            answer.push_back(v1[i][j]);
        }
        cout << '\n';
    }
    return answer;
}