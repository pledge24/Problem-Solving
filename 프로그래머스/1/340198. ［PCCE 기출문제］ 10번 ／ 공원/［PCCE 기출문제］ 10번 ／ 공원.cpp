#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    int R = park.size();
    int C = park[0].size();
    
    int maxSquare = -1;
    vector<vector<int>> DP(R, vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(park[i][j] != "-1")
                continue;
            
            if(i == 0 || j == 0){
                DP[i][j] = 1;
            }
            else{
                DP[i][j] = min({DP[i-1][j], DP[i][j-1], DP[i-1][j-1]}) + 1;
            }
            
            maxSquare = max(maxSquare, DP[i][j]);
        }
    }
    
    for(auto elem : mats){
        if(elem <= maxSquare){
            answer = max(answer, elem);
        }
    }
    
    return answer;
}