#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define MAXN 100'000'000

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 1;
    
    vector<vector<int>> matrix;
    vector<vector<int>> shortest_path;
    
    matrix.resize(N+1, vector<int>(N+1, MAXN));
    shortest_path.resize(N+1, vector<int>(N+1));

    int src, dst, w;
    for(int i = 0; i < road.size(); i++){
        src = road[i][0], dst = road[i][1], w = road[i][2];
        matrix[src][dst] = min(matrix[src][dst], w);
        matrix[dst][src] = min(matrix[dst][src], w);
    }

    shortest_path = matrix;

    for(int k = 1; k <= N; k++){

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) continue;
                shortest_path[i][j] = min(shortest_path[i][j], shortest_path[i][k] + shortest_path[k][j]);
            }
        }
    }
        
    for(int i = 1; i <= N; i++){
        if(shortest_path[1][i] <= K) answer++;
    }
    return answer;
}