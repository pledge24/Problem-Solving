#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 8

using namespace std;
using Matrix = vector<vector<char>>;
using Pos = pair<int, int>;

int N, M, K; 
int dx[DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[DIR] = {0, 1, 1, 1, 0, -1, -1, -1};

Pos getNextPos(int nx, int ny){
    if(nx < 1) nx = N;
    else if(nx > N) nx = 1;
    
    if(ny < 1) ny = M;
    else if(ny > M) ny = 1;    

    return make_pair(nx, ny);
}

// 지나간 위치에 대한 로그를 찍고싶은데;;
unordered_map<pair<Pos, int>, int> logData;

void dfs(Matrix& matrix, const string& str, vector<Pos>& v1, int& cnt){
    Pos curPos = v1.back();
    int curIdx = v1.size()-1;

    // 유망하지 않다면 컷
    if(matrix[curPos.first][curPos.second] != str[curIdx])
        return;
    
    // 종료 조건
    if(v1.size() == K){
        for(int i = 0; i < v1.size(); i++){
            pair<Pos, int> log = make_pair(v1[i], i);
            alreadyFind[log] = true;
        }
    }

    for(int i = 0; i < DIR; i++){
        Pos nextPos = getNextPos(curPos.first+dx[i], curPos.second+dy[i]);
        
        if(alreadyFind[make_pair(nextPos, v1.size()+1)])
            continue;

        v1.push_back(nextPos);
        dfs(matrix, str, v1, cnt);
        v1.pop_back();
    }
}

int startTest(Matrix& matrix, const string& str){
    int cnt = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            Pos curPos = make_pair(i, j);
            vector<Pos> v1 = {curPos};
            dfs(matrix, str, v1, cnt);
        }
    }

    return cnt;
}

int main(void){
    fastio;
    cin >> N >> M >> K;

    // Input Matrix
    Matrix matrix(N+1, vector<char>(M+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> matrix[i][j];
        }
    }

    // Input str
    for(int i = 0; i < K; i++){
        string str; cin >> str;
        int cnt = startTest(matrix, str);
        cout << cnt << '\n';
    }

    return 0;
}