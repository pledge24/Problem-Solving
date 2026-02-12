#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

pair<int, int> getRC(int len){
    int r;
    for(int i = 1; i <= sqrt(len); i++){
        if(len % i == 0){
            r = i;
        }
    }

    return make_pair(r, len/r);
}

int main() {
	fastio;
    string str; cin >> str;

    int len = str.length();
    int r, c;
    tie(r, c) = getRC(len);

    vector<vector<char>> matrix;
    matrix.resize(r, vector<char>(c));

    for(int i = 0; i < len; i++){
        int nx = i % r;
        int ny = i / r;
        matrix[nx][ny] = str[i];
    }

    string ans = "";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ans += matrix[i][j];
        }
    }

    cout << ans << '\n';
    
}