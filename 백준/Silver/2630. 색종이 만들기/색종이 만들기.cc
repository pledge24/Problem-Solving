#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

pair<int, int> dnc(vector<vector<int>>& matrix, int x, int y, int N){
    pair<int, int> p;

    if(N == 1){
        if(matrix[x][y] == 0) p.first = 1;
        else p.second = 1;

        return p;
    } 

    auto [a1, b1] = dnc(matrix, x, y, N/2);
    auto [a2, b2] = dnc(matrix, x+N/2, y, N/2);
    auto [a3, b3] = dnc(matrix, x, y+N/2, N/2);
    auto [a4, b4] = dnc(matrix, x+N/2, y+N/2, N/2);

    int totalA = a1 + a2 + a3 + a4;
    int totalB = b1 + b2 + b3 + b4;

    p.first = totalB == 0 ? 1 : totalA;
    p.second = totalA == 0 ? 1 : totalB;
    
    return p;
}

int main() {
	fastio;
    int N; cin >> N;
    vector<vector<int>> matrix;

    matrix.resize(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    pair<int, int> p = dnc(matrix, 0, 0, N);

    cout << p.first << '\n';
    cout << p.second << '\n';
    
}