#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXLEN 5
#define DIR 8

using namespace std;
using Matrix = vector<vector<char>>;
using Pos = pair<int, int>;

int N, M, K; 
int dx[DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[DIR] = {0, 1, 1, 1, 0, -1, -1, -1};

Pos getNextPos(int nx, int ny){
    if(nx < 0) nx = N-1;
    else if(nx >= N) nx = 0;
    
    if(ny < 0) ny = M-1;
    else if(ny >= M) ny = 0;    

    return make_pair(nx, ny);
}

void dfsUtil(Matrix& matrix, map<string, int>& m1, Pos pos, string& str, int& maxLen){
    if(str.length() == maxLen){
        // cout << "maxLen! str: " << s << '\n';

        m1[str]++;
        return;
    }

    for(int i = 0; i < DIR; i++){
        Pos nextPos = getNextPos(pos.first + dx[i], pos.second + dy[i]);

        str.push_back(matrix[nextPos.first][nextPos.second]);
        m1[str]++;
        dfsUtil(matrix, m1, nextPos, str, maxLen);
        str.pop_back();
    }
}

void dfs(Matrix& matrix, map<string, int>& m1, Pos pos, int maxLen){
    string str = {matrix[pos.first][pos.second]};

    dfsUtil(matrix, m1, pos, str, maxLen);
}

void CalcAllCase(Matrix& matrix, map<string, int>& m1, int maxLen){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            Pos pos = make_pair(i, j);
            dfs(matrix, m1, pos, maxLen);
        }
    }
}

int main(void){
    fastio;
    cin >> N >> M >> K;

    Matrix matrix(N, vector<char>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];
        }
    }

    map<string, int> m1;
    CalcAllCase(matrix, m1, MAXLEN);

    // for(auto it : m1){
    //     cout << it.first << " " << it.second << '\n';
    // }

    for(int i = 0; i < K; i++){
        string str; cin >> str;
        cout << m1[str] << '\n';
    }

    return 0;
}